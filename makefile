# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/27 20:50:16 by jaewpark          #+#    #+#              #
#    Updated: 2021/09/27 21:16:00 by jaewpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SHELL = /bin/sh
CFLAGS += -Iinclude -Wall -Werror -Wextra
RM = rm -f

NAME_SERVER = server
NAME_CLIENT = client

SRC_COMMON = src/util

SRCS_SERVER:= $(shell find $(SRC_COMMON) src/server -name "*.c")
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

SRCS_CLIENT:= $(shell find $(SRC_COMMON) src/client -name "*.c")
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)

.o: .c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_CLIENT)
	$(RM) $(OBJS_SERVER)


fclean: clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all


debug: CFLAGS += -g
debug: fclean

.PHONY: all clean fclean re debug
