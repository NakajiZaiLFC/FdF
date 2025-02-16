# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 15:11:39 by snakajim          #+#    #+#              #
#    Updated: 2024/07/14 18:42:47 by snakajim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 	= libftprintf.a
CC		 	= cc -I./include
FLAGS	 	= -Wall -Wextra -Werror
LIBFT		= libft/libft.a
SRCS	 	= ft_printf.c ft_printf_char.c ft_printf_hex.c ft_printf_int.c ft_printf_pointer.c ft_printf_string.c ft_printf_unsigned.c 
OBJ			= $(SRCS:.c=.o)

%.o:%.c
	${CC} ${FLAGS} -c $< -o $@

$(NAME): $(OBJ)
	make -C libft
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJ)
	
all: $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re