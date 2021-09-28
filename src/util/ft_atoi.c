/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:42:59 by jaewpark          #+#    #+#             */
/*   Updated: 2021/09/28 16:45:38 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	ft_isspace(char c)
{
	if (9 <= c && c <= 13)
		return (1);
	if (c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long long	sign;
	long long	nbr;

	sign = 1;
	nbr = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && '0' <= *str && *str <= '9')
	{
		nbr = (nbr * 10) + (*str - '0');
		if (nbr > 2147483647 && sign == 1)
			return (-1);
		if (nbr > 2147483648 && sign == -1)
			return (0);
		str++;
	}
	return ((int)(nbr * sign));
}
