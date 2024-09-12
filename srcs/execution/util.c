/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:55:53 by hzakharc          #+#    #+#             */
/*   Updated: 2024/09/10 18:14:36 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	error_msg(char *str)
{
	if (str)
		ft_putstr_fd(str, 2);
}

void	put_error(char **msg)
{
	int	i;

	i = 0;
	if (!msg)
		return ;
	while (msg[i] != NULL)
	{
		error_msg(msg[i]);
		i++;
	}
}
