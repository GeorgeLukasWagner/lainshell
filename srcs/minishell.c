/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:35:12 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/23 13:20:55 by gwagner          ###   ########.fr       */
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
		}
	}
}

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	lain_loop(envp);
}
