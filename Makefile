# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelkhams <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/14 19:09:12 by oelkhams          #+#    #+#              #
#    Updated: 2019/07/14 20:04:10 by oelkhams         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c checker.c solve1.c solve2.c free.c parte1.c

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(FLAG) $(SRC) libft/libft.a -o $(NAME)

clean:
	@make fclean -C libft

fclean: clean
	@rm -f $(NAME)

re: fclean all
