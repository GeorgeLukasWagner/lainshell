/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:37:58 by hzakharc          #+#    #+#             */
/*   Updated: 2024/09/08 14:22:16 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	pathfinder_util(char **to_find, char **args)
{
	char	*temp1;
	char	*temp2;
	char	*temp3;

	temp3 = ft_substr(to_find[0], 5, ft_strlen(to_find[0]));
	free(to_find[0]);
	to_find[0] = ft_strdup(temp3);
	free(temp3);
	temp1 = ft_strdup("/");
	temp2 = ft_strdup(args[0]);
	free(args[0]);
	args[0] = ft_strjoin(temp1, temp2);
	free(temp1);
	free(temp2);
}

static void	return_path(char *path, char **args)
{
	char	*temp;

	if (path == NULL)
	{
		temp = ft_substr(args[0], 1, ft_strlen(args[0]));
		free(args[0]);
		args[0] = ft_strdup(temp);
		free(temp);
	}
	else
	{
		free(args[0]);
		args[0] = ft_strdup(path);
		free(path);
	}
}

void	pathfinder(t_env *env, char **args)
{
	char	*path = NULL;
	char	**to_find;
	t_env	*src;
	int		i;

	src = find_node("PATH=", env);
	to_find = ft_split(src->data, ':');
	pathfinder_util(to_find, args);
	i = 0;
	while (to_find[i] != NULL)
	{
		path = ft_strjoin(to_find[i], args[0]);
		if (access(path, X_OK) == 0)
			break ;
		free(path);
		path = NULL;
		i++;
	}
	free_matrix(to_find);
	return_path(path, args);
}
