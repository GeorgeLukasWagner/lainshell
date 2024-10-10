/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lainloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:53:41 by gwagner           #+#    #+#             */
/*   Updated: 2024/10/10 16:56:20 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

void	exit_lain(t_data data)
{
	printf("exit\n");
	free_env(&data.env);
	exit(0);
}

int	is_valid(t_args *list)
{
	t_args	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		if (tmp->token != PIPE)
			i = 1;
		tmp = tmp->next;
	}
	return (i);
}

void	runthisbs(t_data *data)
{
	trim_quotes(&data->args);
	data->redir = get_redir(&data->args);
	open_all_files(&data->redir, data);
	ft_close(&data->here_doc_fd);
	if (data->args != NULL && is_valid(data->args))
	{
		data->cmd = make_cmd(data->args);
		clean_cmd(&data->cmd);
		exec(data);
		free_cmd(data->cmd);
	}
	free_alt(&data->redir);
}

void	lain_loop(t_data data)
{
	char		*lain;

	while (1)
	{
		lain = readline("\033[1;32mlainshell:\033[0m ");
		if (!lain)
			exit_lain(data);
		if (lain[0] != '\0')
		{
			add_history(lain);
			data.args = split_args(lain);
			put_vars(&data.args, data.env, data.ecode);
			if (!syntax_error(data.args))
				runthisbs(&data);
			free_list(&data.args);
		}
		free(lain);
	}
}
