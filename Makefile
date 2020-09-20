# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbellavi <bbellavi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/20 23:35:52 by bbellavi          #+#    #+#              #
#    Updated: 2020/09/21 00:00:54 by bbellavi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= eval

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g

INC_DIR		= includes
SRC_DIR		= srcs

SRCS		= eval.c
SRCS		+= $(SRC_DIR)/interpreter.c
INC_FILES	= $(INC_DIR)/interpreter.h

.PHONY:	all re clean fclean

all: $(NAME)

$(NAME): $(SRCS) $(INC_FILES)
	@$(CC) $(CFLAGS) -o $@ $(SRCS) -I $(INC_DIR)

clean:
	@rm -f $(NAME)

fclean: clean
	@rm -rf $(NAME).dSYM

re: fclean all
