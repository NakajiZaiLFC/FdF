#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snakajim <snakajim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/01 15:04:41 by snakajim          #+#    #+#              #
#    Updated: 2025/01/01 16:07:30 by snakajim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	fdf
CC 		= 	cc
CFLAGS 	= 	-Wall -Wextra -Werror -I./minilibx
LDFLAGS = 	-L./minilibx-linux -lmlx -L/usr/lib -lXext -lX11 -lm -lz
RM 		= 	rm -rf

PRINTF 	= 	ft_printf/libftprintf.a

GNL_SRC = 	get_next_line.c \
            get_next_line_utils.c

FDF_SRC =	main.c \
            fdf_free.c \
            fdf_init.c \
            fdf_utils.c \
            hook.c \
			fdf_set.c \
			fdf_draw_image.c \
			fdf_calculate.c \
            make_mlx_win.c

OBJ_DIR = 	obj/
FDF_OBJ = 	$(addprefix $(OBJ_DIR), $(FDF_SRC:.c=.o))
GNL_OBJ = 	$(addprefix $(OBJ_DIR), $(GNL_SRC:.c=.o))
OBJ 	= 	$(FDF_OBJ) $(GNL_OBJ)

all: $(PRINTF) $(NAME)

$(OBJ_DIR)%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)%.o: gnl/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(PRINTF) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(PRINTF) $(LDFLAGS) -o $(NAME)

$(PRINTF):
	@make -sC ft_printf

clean:
	@$(RM) $(OBJ_DIR)
	@make -sC ft_printf clean

fclean: clean
	@$(RM) $(NAME)
	@make -sC ft_printf fclean

re: fclean all

.PHONY: all clean fclean re