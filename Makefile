# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: copinto- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/13 13:17:45 by copinto-          #+#    #+#              #
#    Updated: 2019/07/09 23:40:37 by copinto-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_gnl
OBJECTS1 = get_next_line.o
OBJECTS2 = main.o
LIBFT_DIR = libft/

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	@clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	@clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
	@echo "[INFO] Executable [$(NAME)] created!"

all: $(NAME)

clean:
	@rm -f $(OBJECTS1) $(OBJECTS2)
	@make -C $(LIBFT_DIR) fclean
	@echo "[INFO] Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] Library [$(NAME)] removed!"
	
re: fclean all

.PHONY: all, clean, fclean , re

re: fclean all
