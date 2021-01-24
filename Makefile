# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/04 15:11:16 by cleo              #+#    #+#              #
#    Updated: 2020/04/04 15:43:36 by cleo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEAD=ft_printf.h 42_libft/libft.h
SRC= 42_libft/ft_atoi.c 42_libft/ft_isalpha.c 42_libft/ft_isalnum.c
SRC:= $(SRC) 42_libft/ft_calloc.c 42_libft/ft_bzero.c 42_libft/ft_isdigit.c
SRC:= $(SRC) 42_libft/ft_isspace.c 42_libft/ft_memcpy.c 42_libft/ft_memset.c
SRC:= $(SRC) 42_libft/ft_memmove.c 42_libft/ft_tolower.c
SRC:= $(SRC) 42_libft/ft_strlen.c 42_libft/ft_toupper.c
SRC:= $(SRC) 42_libft/ft_strdup.c 42_libft/ft_putchar.c
SRC:= $(SRC) 42_libft/ft_putstr.c 42_libft/ft_isascii.c
SRC:= $(SRC) 42_libft/ft_isprint.c 42_libft/ft_putstr_fd.c
SRC:= $(SRC) 42_libft/ft_putendl_fd.c 42_libft/ft_putchar_fd.c
SRC:= $(SRC) 42_libft/ft_split.c 42_libft/ft_putnbr_fd.c
SRC:= $(SRC) 42_libft/ft_memchr.c 42_libft/ft_memccpy.c
SRC:= $(SRC) 42_libft/ft_memcmp.c 42_libft/ft_strchr.c
SRC:= $(SRC) 42_libft/ft_strrchr.c 42_libft/ft_strnstr.c
SRC:= $(SRC) 42_libft/ft_itoa.c 42_libft/ft_strtrim.c
SRC:= $(SRC) 42_libft/ft_strncmp.c 42_libft/ft_strjoin.c
SRC:= $(SRC) 42_libft/ft_strlcat.c 42_libft/ft_strlcpy.c
SRC:= $(SRC) 42_libft/ft_substr.c 42_libft/ft_strmapi.c
SRC:= $(SRC) itoa_base.c itoa_base_signed.c ft_printf.c format.c conv_x.c conv_u.c
SRC:= $(SRC) conv_percent.c conv_o.c conv_c.c buffer.c conv_s.c
SRC:= $(SRC) format.c parse_format.c
OBJ= $(SRC:.c=.o)
CC = gcc
CFLAGS =-fsanitize=address -g -Wall -Wextra -Werror -I42_libft
NAME=libftprintf.a

all: $(NAME)

bonus: $(NAME) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

$(NAME): $(HEAD) $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
			rm -rf $(NAME)

.PHONY: clean fclean re all bonus
