/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:35:12 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/23 15:07:15 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_signum = 0;

void	lain_loop(char **envp)
{
	char		*lain;
	t_args		*args;

	(void)envp;
	while (1)
	{
		lain = readline("lainshell:");
		if (!lain)
			break ;
		if (lain[0] != '\0')
		{
			add_history(lain);
			args = split_args(lain);
			syntax_error(args);
			free_list(&args);
			free(lain);
		}
	}
}

void	signal_handler(int signum)
{
	g_signum = signum;
	if (signum == SIGINT)
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (signum == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	init_signal(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	init_signal();
	lain_loop(envp);
}
