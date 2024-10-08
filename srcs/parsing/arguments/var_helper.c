/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:26:30 by gwagner           #+#    #+#             */
/*   Updated: 2024/10/07 17:26:39 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"

void	put_exit_code(t_args **list, size_t i, int ecode)
{
	char	*new[3];

	new[0] = ft_substr((*list)->data, 0, i - 1);
	new[1] = ft_itoa(ecode);
	new[2] = ft_substr((*list)->data + i, 1,
			ft_strlen((*list)->data + i + 1));
	free((*list)->data);
	(*list)->data = ft_strjoin(new[0], new[1]);
	free(new[0]);
	free(new[1]);
	new[0] = ft_strjoin((*list)->data, new[2]);
	free((*list)->data);
	(*list)->data = new[0];
	free(new[2]);
}
