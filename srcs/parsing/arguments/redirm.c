/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:16:24 by gwagner           #+#    #+#             */
/*   Updated: 2024/09/19 20:13:31 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

int	rm_redir(t_args *tmp)
{
	t_args	*to_rm;
	t_args	*to_rm2;
	int		ret;

	ret = 0;
	to_rm = tmp->next;
	to_rm2 = tmp->next->next;
	if (tmp->next->next->next)
		tmp->next = tmp->next->next->next;
	else
	{
		tmp->next = NULL;
		ret = 1;
	}
	free(to_rm->data);
	free(to_rm2->data);
	free(to_rm);
	free(to_rm2);
	return (ret);
}

int	rm_redir2(t_args **args)
{
	t_args	*to_rm;
	t_args	*to_rm2;
	int		ret;

	ret = 0;
	to_rm = *args;
	to_rm2 = to_rm->next;
	if (to_rm2->next)
		*args = to_rm2->next;
	else
	{
		*args = NULL;
		ret = 1;
	}
	free(to_rm->data);
	free(to_rm2->data);
	free(to_rm);
	free(to_rm2);
	return (ret);
}

t_alt	*altnew(char *data, t_token token, size_t i)
{
	t_alt	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->data = data;
	new->token = token;
	new->index = i;
	new->next = NULL;
	return (new);
}

t_alt	*ft_altlast(t_alt *head)
{
	t_alt	*tmp;

	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_altadd_back(t_alt **list, t_alt *new)
{
	t_alt	*n;

	if (*list)
	{
		n = ft_altlast(*list);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*list = new;
		(*list)->next = NULL;
	}
}

void	re_redir(t_args *tmp, t_alt **redir, size_t i)
{
	t_alt	*new;

	new = altnew(ft_strdup(tmp->next->data), tmp->token, i);
	ft_altadd_back(redir, new);
}

void	free_alt(t_alt **list)
{
	t_alt	*head;
	t_alt	*tmp;

	head = *list;
	while (head)
	{
		tmp = head;
		head = head->next;
		if (tmp->data)
			free(tmp->data);
		free(tmp);
	}
}

void	print_redir(t_alt *redir)
{
	t_alt	*tmp;

	tmp = redir;
	while (tmp)
	{
		printf("redir: %s type: %d index: %d\n",
			tmp->data, tmp->token, tmp->index);
		tmp = tmp->next;
	}
}

t_alt	*get_redir(t_args **args)
{
	t_args	*tmp;
	t_alt	*redir;
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	redir = NULL;
	tmp = *args;
	while (tmp && tmp->next)
	{
		if (tmp->next->token == REDIR_OUT || tmp->next->token == REDIR_APPEND
			|| tmp->next->token == REDIR_IN || tmp->next->token == HERE_DOC)
		{
			re_redir(tmp->next, &redir, i);
			ret = rm_redir(tmp);
			if (ret)
				break ;
		}
		else if (tmp->token == REDIR_OUT || tmp->token == REDIR_APPEND
			|| tmp->token == REDIR_IN || tmp->token == HERE_DOC)
		{
			re_redir(tmp, &redir, i);
			ret = rm_redir2(&tmp);
			*args = tmp;
			if (ret || !tmp->next)
				break ;
		}
		if (tmp->token == PIPE && tmp->next)
			i++;
		if (tmp->next->token != REDIR_OUT && tmp->next->token != REDIR_APPEND
			&& tmp->next->token != REDIR_IN && tmp->next->token != HERE_DOC && tmp->next)
			tmp = tmp->next;
	}
	return (redir);
}
