/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:48:27 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/12 18:04:51 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

int	is_flag(char *cmd)
{
	size_t	i;

	i = 0;
	if (ft_strlen(cmd) == 1)
		return (0);
	if (cmd[i] == '-')
		i++;
	else
		return (0);
	while (cmd[i] == 'n')
		i++;
	if (i == ft_strlen(cmd))
		return (1);
	return (0);
}

void	echo_util(int *nl, t_cmd *cmd, int i)
{
	int	cec;

	cec = 0;
	if (is_flag(cmd->argv[i]) == 1)
	{
		while (cmd->argv[i] && is_flag(cmd->argv[i]) == 1)
			i++;
		*nl = TRUE;
	}
	i = 1;
	while (cmd->argv[i] != NULL)
	{
		if (is_flag(cmd->argv[i]) == 0 || cec)
		{
			printf("%s", cmd->argv[i]);
			cec = 1;
		}
		if (cmd->argv[i + 1] != NULL && is_flag(cmd->argv[i]) == 0)
			printf(" ");
		i++;
	}
}

int	ft_echo(t_cmd *cmd)
{
	int	i;
	int	nl;

	if (matrix_size(cmd->argv) > 1)
	{
		i = 1;
		nl = FALSE;
		if (cmd->argv[1] == NULL || cmd->argv[1][0] == '\0')
		{
			printf("\n");
			return (0);
		}
		echo_util(&nl, cmd, i);
		if (nl == FALSE)
			printf("\n");
	}
	else
		printf("\n");
	return (0);
}
