/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:35:12 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/23 16:04:56 by hzakharc         ###   ########.fr       */
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
		lain = readline("\033[1;32mlainshell\033[0m:");
		if (!lain)
			break ;
		if (lain[0] != '\0')
		{
			add_history(lain);
			args = split_args(lain);
			syntax_error(args);
			if (ft_strncmp(args->data, "pwd", ft_strlen(args->data)) == 0)
				ft_pwd();
			else if (ft_strncmp(args->data, "cd", ft_strlen(args->data)) == 0)
				ft_cd(args);
			ft_printlst(args);
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
