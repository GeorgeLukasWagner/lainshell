/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:35:12 by gwagner           #+#    #+#             */
/*   Updated: 2024/10/10 16:54:25 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <readline/readline.h>

int	g_signum = 0;

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
	data.here_doc_fd = -1;
	data.ecode = 0;
	data.error_file = 0;
	init_signal();
	lain_loop(data);
}
