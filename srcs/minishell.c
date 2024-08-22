/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:35:12 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/22 14:31:35 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	lain_loop(char **envp)
{
	char		*lain;
	char		**args;
	pid_t		pid;

	while (1)
	{
		lain = readline("[LainShell]:");
		if (lain[0] != '\0')
		{
			add_history(lain);
			args = ft_split(lain, ' ');
		}	
	}
}

void	init_envp(char **envp, t_data *data)
{
	int	i;

	i = 0;
	data->env = NULL;
	while (envp[i])
	{
		ft_lstadd_back(&data->env, ft_lstnew(ft_strdup(envp[i])));
		i++;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	(void)ac;
	(void)av;
	init_envp(envp, &data);
	// lain_loop(envp);
}
