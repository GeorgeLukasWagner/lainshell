/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:35:12 by gwagner           #+#    #+#             */
/*   Updated: 2024/10/09 18:13:37 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <readline/readline.h>

int	g_signum = 0;

void	exit_lain(t_data data)
{
	printf("exit\n");
	free_env(&data.env);
	exit(0);
}

int		is_valid(t_args *list)
{
	t_args	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		if (tmp->token != PIPE)
			i = 1;
		tmp = tmp->next;
	}
	return (i);
}

void	lain_loop(t_data data)
{
	char		*lain;

	while (1)
	{
		lain = readline("\033[1;32mlainshell:\033[0m ");
		// lain = readline("minishell$ ");
		if (!lain)
			exit_lain(data);
		if (lain[0] != '\0')
		{
			add_history(lain);
			data.args = split_args(lain);
			put_vars(&data.args, data.env, data.ecode);
			if (!syntax_error(data.args))
			{
				trim_quotes(&data.args);
				data.redir = get_redir(&data.args);
				open_all_files(&data.redir, &data);
				if (data.args != NULL && is_valid(data.args))
				{
					data.cmd = make_cmd(data.args);
					clean_cmd(&data.cmd);
					exec(&data);
					free_cmd(data.cmd);
				}
				free_alt(&data.redir);
			}
			free_list(&data.args);
		}
		free(lain);
	}
}

void	signal_handler(int signum)
{
	if (signum == SIGCHLD)
		g_signum = SIGCHLD;
	else if (signum == SIGINT)
	{
		write(1, "\n", 1);
		wait(NULL);
		if (g_signum == SIGCHLD)
		{
			g_signum = 0;
			return ;
		}
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_signum = 0;
	}
}

void	init_signal(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGCHLD, &sa, NULL);
	signal(SIGQUIT, SIG_IGN);
	sigaction(SIGTSTP, &sa, NULL);
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	(void)ac;
	(void)av;
	data.env = init_env(envp);
	data.pid = -1;
	data.pipefd[0] = -1;
	data.pipefd[1] = -1;
	data.fd[0] = -1;
	data.fd[1] = -1;
	data.ecode = 0;
	data.error_file = 0;
	init_signal();
	lain_loop(data);
}
