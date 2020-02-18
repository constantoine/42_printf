/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:49:36 by crebert           #+#    #+#             */
/*   Updated: 2020/02/17 18:48:49 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buffer.h"
#include "libft.h"
#include <unistd.h>

int		buffer_flush(t_buffer *buffer)
{
	int	ret;
	
	ret = write(buffer->fd, buffer->buffer, buffer->index);
	buffer->index = 0;
	return (ret);
}

int		send_to_buffer(t_buffer *buffer, char *str)
{
	size_t	index;
	size_t	len;
	size_t	to_write;
	size_t	ret;
	size_t	tmp;

	index = 0;
	ret = 0;
	len = ft_strlen(str);
	while (len)
	{
		to_write = (len > BUFFER_SIZE ? BUFFER_SIZE : len) - buffer->index;
		ft_memcpy(&buffer->buffer[buffer->index], str, to_write);
		str += to_write;
		len -= to_write;
		buffer->index += to_write;
		if (buffer->index == BUFFER_SIZE)
		{
			if ((tmp = buffer_flush(buffer)) == -1)
				break ;
			ret += tmp;
		}
	}
	return (ret);
}
