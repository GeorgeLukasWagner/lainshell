/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:35:12 by gwagner           #+#    #+#             */
/*   Updated: 2024/10/07 17:36:27 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <readline/readline.h>

int	g_signum = 0;

void	exit_lain(t_data data)
{
	free_env(&data.env);
	exit(0);
}

void	lain_loop(t_data data)
{
	char		*lain;

	while (1)
	{
		lain = readline("\033[1;32mlainshell:\033[0m ");
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
				open_all_files(&data.redir);
				if (data.args != NULL)
				{
					data.cmd = make_cmd(data.args);
					ft_printcmd(data.cmd);
					exec(&data);
					clean_cmd(&data.cmd);
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
	if (signum == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	init_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, SIG_IGN);
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
	init_signal();
	lain_loop(data);
}
