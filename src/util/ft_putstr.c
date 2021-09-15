/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:09:10 by jaewpark          #+#    #+#             */
/*   Updated: 2021/09/27 11:03:40 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	ft_putstr_fd(char *s, int fd)
{
	int len;

	if (!s)
		return ;
	len = 0;
	while (s[len] != '\0')
		len++;
	write((unsigned int)fd, s, len);
}
