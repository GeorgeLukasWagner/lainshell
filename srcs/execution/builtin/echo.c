/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc < hzakharc@student.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 15:48:27 by hzakharc          #+#    #+#             */
/*   Updated: 2024/10/07 15:59:16 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built.h"

int	is_flag(char *cmd)
{
	int	i;

	i = 1;
	if (cmd[0] == '-')
	{
		while (cmd[i] == 'n')
			i++;
	}
	if (cmd[i] != '\0')
		return (TRUE);
	else
		return (FALSE);
}

void	echo_util(int *nl, t_cmd *cmd, int i)
{
	if (ft_strlen(cmd->argv[i]) > 1)
	{
		if (is_flag(cmd->argv[i]) == FALSE)
		{
			while (is_flag(cmd->argv[i]) == FALSE)
				i++;
			*nl = TRUE;
		}	
	}
	while (cmd->argv[i] != NULL)
	{
		printf("%s", cmd->argv[i]);
		if (cmd->argv[i + 1] != NULL)
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
