# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/04 15:11:16 by cleo              #+#    #+#              #
#    Updated: 2021/02/09 14:42:28 by cleo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEAD=ft_printf.h
SRC := itoa_base.c ft_printf.c format.c conv_x.c conv_u.c
SRC += conv_percent.c conv_c.c buffer.c conv_s.c conv_d_i.c
SRC += format.c parse_format.c conv_p.c len_signed.c
SRC += len_unsigned.c conv_n.c conv_o.c
SRC_BONUS := ft_sprintf_bonus.c ft_dprintf_bonus.c
OBJ_LIB = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -I42_libft
NAME=libftprintf.a
LIBFT = 42_libft

all: $(NAME)

bonus:
	@make all OBJ_LIB="$(OBJ_LIB) $(OBJ_BONUS)"

$(NAME): $(HEAD) $(OBJ_LIB)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJ_LIB)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	make clean -C $(LIBFT)
	rm -rf $(OBJ_LIB) $(OBJ_BONUS)

fclean: clean
	make fclean -C $(LIBFT)
	rm -rf $(NAME)

.PHONY: clean fclean re all bonus
