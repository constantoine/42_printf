/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:42:14 by crebert           #+#    #+#             */
/*   Updated: 2020/02/17 18:48:40 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif
# include "ft_printf.h"
# include <stddef.h>

typedef	struct	s_buffer
{
	char	buffer[BUFFER_SIZE];
	size_t	index;
	int		fd;
}				t_buffer;

int		buffer_flush(t_buffer *buffer);
int		send_to_buffer(t_buffer *buffer, char *str);

# endif
