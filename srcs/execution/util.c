/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:55:53 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/10 16:40:42 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	killchild(int signum)
{
	if (signum == SIGINT)
		exit(0);
}

void	here_doc(t_alt *redir, t_data *data)
{
	char	*tmp_storage;
	char	*full_str;
	char	*delim;

	signal(SIGINT, killchild);
	delim = ft_strjoin(redir->data, "\n");
	data->here_doc_fd = open("/tmp/.heredoc",
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		tmp_storage = readline("heredoc > ");
		full_str = ft_strjoin(tmp_storage, "\n");
		free(tmp_storage);
		if (!full_str || ft_strncmp(full_str, delim, ft_strlen(full_str)) == 0)
		{
			free(full_str);
			free(delim);
			break ;
		}
		ft_putstr_fd(full_str, data->here_doc_fd);
		free(full_str);
	}
	ft_close(&data->here_doc_fd);
	exit(0);
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
