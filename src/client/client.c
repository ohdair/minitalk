/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:46:43 by jaewpark          #+#    #+#             */
/*   Updated: 2021/09/27 21:05:43 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/client.h"

void	send_message(t_putStr *info)
{
	int	i;
	int	current_bit;
	int bit_temp;

	i = 0;
	while (info->arg[i])
	{
		current_bit = 0;
		while (current_bit < 8)
		{
			bit_temp = info->arg[i] >> (7 - current_bit) & 1;
			if (bit_temp == 0)
			{
				kill(info->pid, SIGUSR1);
				usleep(30);
			}
			else if (bit_temp == 1)
			{
				kill(info->pid, SIGUSR2);
				usleep(30);
			}
			current_bit++;
		}
		usleep(200);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_putStr	info;

	sendErr(&info, argc, argv);
	info.arg = argv[2];
	send_message(&info);
	return (0);
}
