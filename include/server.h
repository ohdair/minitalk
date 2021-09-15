/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:30:57 by jaewpark          #+#    #+#             */
/*   Updated: 2021/09/27 19:31:44 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SERVER_
# define _SERVER_

#include <unistd.h>
#include <signal.h>
#include "util.h"

typedef struct	s_character
{
	char	character;
	int	current_bit;
}	t_character;

#endif
