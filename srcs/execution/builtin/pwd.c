/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:49:02 by hzakharc          #+#    #+#             */
/*   Updated: 2024/08/24 08:41:56 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

void	ft_pwd(void)
{
	printf("%s\n", getcwd(NULL, 0));
}

int		ft_cd(t_args *arg)
{
	t_args	*temp;

	temp = arg;
	if (!temp->next || temp->next->token != ARG)
	{
		chdir("/home/hzakharc");		// change this to work with the env
		return (0);
	}
	if (temp->next->next)
	{
		if (temp->next->next->token == ARG)
		{
			printf("cd: too many arguments\n");
			return (-1);
		}
	}
	if (chdir(temp->next->data) != 0)
	{
		printf("cd: %s: No such directory\n", temp->data);
		return (-1);
	}
	return (0);
}
