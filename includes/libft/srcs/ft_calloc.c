/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:03:25 by gwagner           #+#    #+#             */
/*   Updated: 2024/06/12 12:03:51 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t size, size_t nmemb)
{
	void	*arr;
	size_t	fullsize;

	fullsize = size * nmemb;
	if (size && nmemb && size > (2147483647 / nmemb))
		return (NULL);
	arr = malloc(fullsize);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, fullsize);
	return (arr);
}
