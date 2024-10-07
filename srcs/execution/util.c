/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:55:53 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/07 10:17:53 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	here_doc()
{
	int	fd;

	fd = open(".heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
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

void	free_matrix(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}
