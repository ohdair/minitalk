/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:54:44 by jaewpark          #+#    #+#             */
/*   Updated: 2021/09/28 16:19:14 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	sendErr(t_putStr *info, int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_putstr_fd("Invalid argument number!\n", 1);
		exit(1);
	}
	info->pid = ft_atoi(argv[1]);
	if (info->pid < 101 || info->pid > 99999)
	{
		ft_putstr_fd("Wrong PID Number\n", 1);
		exit(1);
	}
}
