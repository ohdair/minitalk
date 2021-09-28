# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 20:50:16 by jaewpark          #+#    #+#              #
#    Updated: 2021/09/28 17:06:12 by jaewpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS += -Iinclude -Wall -Werror -Wextra
RM = rm -f

NAME_SERVER = server
NAME_CLIENT = client

SRC_COMMON = src/util

SRCS_SERVER =	src/server/server.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

SRCS_CLIENT =	src/client/client.c \
				src/client/client_err.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

SRCS_UTIL =	$(SRC_COMMON)/ft_atoi.c \
			$(SRC_COMMON)/ft_putnbr.c \
			$(SRC_COMMON)/ft_putchar.c \
			$(SRC_COMMON)/ft_putstr.c
OBJS_UTIL = $(SRCS_UTIL:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(OBJS_SERVER) $(OBJS_UTIL)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER) $(OBJS_UTIL)

$(NAME_CLIENT): $(OBJS_CLIENT) $(OBJS_UTIL)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT) $(OBJS_UTIL)

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_CLIENT)
	$(RM) $(OBJS_SERVER)
	$(RM) $(OBJS_UTIL)


fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all


debug: CFLAGS += -g
debug: fclean

.PHONY: all clean fclean re debug
