/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwagner <gwagner@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 12:39:41 by gwagner           #+#    #+#             */
/*   Updated: 2024/08/18 15:17:00 by gwagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_space(int c)
{
	if ((c > 8 && c < 14)
		|| (c == 32))
		return (8192);
	return (0);
}

int	ft_atoi(char const *str)
{
	long long int	n;
	long long int	check;
	int				sign;

	n = 0;
	sign = 1;
	while (*str && check_space(*str))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		check = n;
		n = n * 10 + sign * (*str - 48);
		if (n > check && sign < 0)
			return (0);
		if (n < check && sign > 0)
			return (-1);
		str++;
	}
	return (n);
}
