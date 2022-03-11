# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdwain <wdwain@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 14:52:40 by wdwain            #+#    #+#              #
#    Updated: 2022/03/11 15:34:45 by wdwain           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

HEADER = pipex.h
SRC = pipex.c \
		utils.c \
		ft_split.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strnstr.c
		
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	$(RM)  $(OBJ)

fclean: clean
	$(RM)  $(NAME)

re: fclean all

.PHONY: all clean fclean re