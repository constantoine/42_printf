/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:45:06 by crebert           #+#    #+#             */
/*   Updated: 2020/03/09 23:10:58 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "parse_format.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef	struct	s_buffer
{
	char	buffer[BUFFER_SIZE];
	size_t	index;
	int		fd;
}				t_buffer;

typedef struct	s_printf
{
	int			len;
	char		*str;
	t_buffer	buffer;
	t_format	format;
}				t_printf;

#include "buffer.h"

int ft_printf(const char *str, ...);

#endif
