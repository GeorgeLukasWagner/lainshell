/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:55:53 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/07 17:34:03 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	here_doc(t_alt *redir)
{
	int		fd;
	char	*tmp_storage;
	char	*delim;

	delim = redir->data;
	fd = open("/tmp/.heredoc", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		tmp_storage = readline("heredoc > ");
		if (!tmp_storage ||
			ft_strncmp(tmp_storage, delim, ft_strlen(tmp_storage)) == 0)
		{
			free(tmp_storage);
			break ;
		}
		ft_putstr_fd(tmp_storage, fd);
		ft_putstr_fd("\n", fd);
		free(tmp_storage);
	}
	close(fd);
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
