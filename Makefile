# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 19:53:24 by icarboni          #+#    #+#              #
#    Updated: 2022/11/15 20:14:14 by icarboni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = clang
FLAG = -Wall -Wextra -Werror -I.
SRC = pipex.c pipex_utils.c parser.c parser_utils.c
OBJ = ${SRC:.c=.o}
LIBFT = ./libft/libft.a
MAKE_LIBFT = -f ./libft/Makefile

all: make_libft $(NAME)

make_libft:
	cd libft && $(MAKE) 
	
$(NAME): $(OBJ)
	$(CC) $(FLAG) -o $(NAME) $(OBJ) $(LIBFT)

$(OBJ): $(SRC)
	$(CC) $(FLAG) -c $(SRC)

clean:
	/bin/rm -f $(OBJ)
	cd libft && $(MAKE) fclean

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all 

.PHONY: clean fclean all re
