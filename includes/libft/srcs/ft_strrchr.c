/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:26:44 by gwagner           #+#    #+#             */
/*   Updated: 2024/06/12 11:24:02 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char const	*aux;

	aux = NULL;
	while (*s)
	{
		if (*s == (char)c)
			aux = s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((char *)aux);
}
