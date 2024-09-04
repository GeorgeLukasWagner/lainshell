/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:35:12 by gwagner           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/09/04 11:10:06 by gwagner          ###   ########.fr       */
=======
/*   Updated: 2024/09/03 13:56:46 by hzakharc         ###   ########.fr       */
>>>>>>> refs/remotes/origin/main
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		lain = readline("\033[1;32mlainshell:\033[0m");
		if (!lain)
			exit_lain(data);
		if (lain[0] != '\0')
		{
			add_history(lain);
			data.args = split_args(lain);
			put_vars(&data.args, data.env);
			if (!syntax_error(data.args))
			{
				//heredoc here
				trim_quotes(&data.args);
<<<<<<< HEAD
				data.cmd = make_cmd(data.args);
				exec_built(data.args->data, data);
=======
				ft_printlst(data.args);
				exec_built(data.args->data, &data);
>>>>>>> refs/remotes/origin/main
			}
			free_list(&data.args);
			free(lain);
		}
	}
}

void	signal_handler(int signum)
{
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
