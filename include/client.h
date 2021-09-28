/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:46:52 by jaewpark          #+#    #+#             */
/*   Updated: 2021/09/28 16:18:01 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include "util.h"

typedef struct s_putStr
{
	char	*arg;
	int		pid;
}	t_putStr;

void	sendErr(t_putStr *info, int argc, char *argv[]);
#endif
