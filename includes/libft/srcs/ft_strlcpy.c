/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:09:56 by gwagner           #+#    #+#             */
/*   Updated: 2024/06/12 11:46:24 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char const *src, size_t n)
{
	size_t	i;

	i = ft_strlen(src);
	if (!n)
		return (i);
	while (--n && *src)
		*dest++ = *src++;
	*dest = '\0';
	return (i);
}
