/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:16:24 by gwagner           #+#    #+#             */
/*   Updated: 2024/10/10 16:15:36 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include <stdio.h>

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

void	re_redir(t_args *tmp, t_alt **redir, size_t i)
{
	t_alt	*new;

	new = altnew(ft_strdup(tmp->next->data), tmp->token, i);
	ft_altadd_back(redir, new);
}

void	redir_helper(t_alt **redir, t_args **args, t_args *tmp, size_t i)
{
	int		ret;

	ret = 0;
	while (tmp && tmp->next)
	{
		if (tmp->token == PIPE && tmp->next)
			i++;
		if (redircheck(tmp, 1))
		{
			re_redir(tmp->next, redir, i);
			ret = rm_redir(tmp);
			if (ret)
				break ;
		}
		else if (redircheck(tmp, 2))
		{
			re_redir(tmp, redir, i);
			ret = rm_redir2(&tmp);
			*args = tmp;
			if (ret || !tmp->next)
				break ;
		}
		if (redircheck(tmp, 3) && !redircheck(tmp, 2))
			tmp = tmp->next;
	}
}

t_alt	*get_redir(t_args **args)
{
	t_args	*tmp;
	t_alt	*redir;
	size_t	i;

	i = 0;
	redir = NULL;
	tmp = *args;
	redir_helper(&redir, args, tmp, i);
	return (redir);
}
