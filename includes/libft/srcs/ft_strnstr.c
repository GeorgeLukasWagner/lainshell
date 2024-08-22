/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:40:36 by gwagner           #+#    #+#             */
/*   Updated: 2024/06/10 15:58:28 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (small[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (small[j] == big[i + j] && (i + j) < len)
		{
			if (small[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
