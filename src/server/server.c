/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:53:14 by jaewpark          #+#    #+#             */
/*   Updated: 2021/09/28 11:21:57 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/server.h"

static void	handler_msg(int sig)
{
	static t_character	chr;

	if (sig == SIGUSR1)
	{
		chr.character |= 0;
		if (chr.current_bit < 7)
			chr.character <<= 1;
	}
	else if (sig == SIGUSR2)
	{
		chr.character |= 1;
		if (chr.current_bit < 7)
			chr.character <<= 1;
	}
	chr.current_bit++;
	if (chr.current_bit == 8)
	{
		write(1, &chr.character, 1);
		chr.character = 0;
		chr.current_bit = 0;
	}
}

int	main(void)
{
	int	pidNumber;

	pidNumber = getpid();
	ft_putnbr_fd(pidNumber, 0);
	write(1, "\n", 1);
	signal(SIGUSR1, handler_msg);
	signal(SIGUSR2, handler_msg);
	while (1)
		pause();
}
