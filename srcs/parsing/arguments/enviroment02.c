/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:41:04 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/23 16:25:56 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

t_env	*init_env(char **envp)
{
	size_t	i;
	t_env	*env;
	t_env	*new;

	env = NULL;
	i = 0;
	while (envp[i])
	{
		new = env_lstnew(envp[i]);
		env_lstadd_back(&env, new);
		i++;
	}
	return (env);
}
