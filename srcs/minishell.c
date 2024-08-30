/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:35:12 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/30 22:24:33 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_signum = 0;

void	lain_loop(t_data data)
{
	char		*lain;

	while (1)
	{
		lain = readline("\033[1;32mlainshell:\033[0m");
		if (!lain)
			break ;
		if (lain[0] != '\0')
		{
			add_history(lain);
			data.args = split_args(lain);
			syntax_error(data.args);
			exec_built(data.args->data, data);
			free_list(&data.args);
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
	t_data	data;

	(void)ac;
	(void)av;
	data.env = init_env(envp);
	init_signal();
	lain_loop(data);
}
