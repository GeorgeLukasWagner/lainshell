/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:55:53 by hzakharc          #+#    #+#             */
/*   Updated: 2024/09/19 13:03:55 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	here_doc()
{
	int	fd;

	fd = open(".heredoc", O_RDONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("here_doc cannot be accessed\n", 2);
		return ;
	}
	while (1)
	{
		
	}
}

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
