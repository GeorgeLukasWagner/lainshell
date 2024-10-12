/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:44:07 by gwagner           #+#    #+#             */
/*   Updated: 2024/10/12 17:58:59 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

int	check_rtype(char *line, int i)
{
	if (line[i] == '<')
	{
		if (line[i + 1] == '<')
			return (i + 2);
		else
			return (i + 1);
	}
	else
	{
		if (line[i + 1] == '>')
			return (i + 2);
		else
			return (i + 1);
	}
}

int	putredir(t_args **list, char *line, int i, int *cmd)
{
	t_args	*new;

	*cmd = 0;
	if (line[i] == '<')
	{
		if (line[i + 1] == '<')
			new = ft_lstnew(ft_strdup("<<"), HERE_DOC);
		else
			new = ft_lstnew(ft_strdup("<"), REDIR_IN);
	}
	else
	{
		if (line[i + 1] == '>')
			new = ft_lstnew(ft_strdup(">>"), REDIR_APPEND);
		else
			new = ft_lstnew(ft_strdup(">"), REDIR_OUT);
	}
	ft_lstadd_back(list, new);
	return (check_rtype(line, i));
}

int	putpipe(t_args **list, int *i)
{
	t_args	*new;

	new = ft_lstnew(ft_strdup("|"), PIPE);
	ft_lstadd_back(list, new);
	*i += 1;
	return (1);
}

int	putarg(t_args **list, char *line, int i)
{
	t_args	*new;
	char	*arg;

	if (line[i] == '"' || line[i] == '\'')
		arg = ft_substr(line, i, wordlen(line + i));
	else
		arg = ft_substr(line, i, special_len(line + i));
	new = ft_lstnew(arg, ARG);
	ft_lstadd_back(list, new);
	if (line[i] == '"' || line[i] == '\'')
		i += wordlen(line + i);
	else
		i += special_len(line + i);
	if (!is_space(line[i]) && !is_token(line[i]))
		new->append = true;
	return (i);
}

t_args	*split_args(char *line)
{
	t_args	*list;
	int		i;
	int		cmd;

	list = NULL;
	i = 0;
	cmd = 1;
	while (line[i])
	{
		i = eat_space(line, i);
		if (check_redir(line, i))
			i = putredir(&list, line, i, &cmd);
		else if (line[i] == '|')
			cmd = putpipe(&list, &i);
		else if ((line[i] == '"' || line[i] == '\'')
			&& quotecheck(line, i, line[i]))
			i = putquote(&list, line, i, line[i]);
		else if (cmd && line[i])
			cmd = putcmd(&list, line, &i);
		else if (line[i])
			i = putarg(&list, line, i);
	}
	return (list);
}
