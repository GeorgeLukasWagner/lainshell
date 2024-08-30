/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:46:18 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/27 16:47:29 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

t_exp	*init_exp(t_env *env)
{
	t_env	*temp_env;
	t_exp	*exp;
	t_exp	*new;
	char	**temp;

	temp_env = env;
	exp = NULL;
	while (temp_env)
	{
		if (ft_strncmp("_=/", temp_env->data, 3) == 0)
			temp_env = temp_env->next;
		temp = ft_split(temp_env->data, '=');
		new = exp_lstnew(temp[0], temp[1]);
		free(temp);
		exp_lstadd_back(&exp, new);
		temp_env = temp_env->next;
	}
	return (exp);
}
