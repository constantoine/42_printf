/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:49:36 by crebert           #+#    #+#             */
/*   Updated: 2020/03/10 01:09:29 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

int		buffer_flush(t_printf *pf)
{
	int	ret;

	ret = write(pf->buffer.fd, pf->buffer.buffer, pf->buffer.index);
	pf->buffer.index = 0;
	return (ret);
}

int		send_to_buffer(t_printf *pf, const char *str, size_t len)
{
	size_t	index;
	size_t	to_write;
	size_t	ret;
	int		tmp;

	index = 0;
	ret = 0;
	while (len)
	{
		to_write = (len > BUFFER_SIZE - pf->buffer.index ? BUFFER_SIZE : len);
		ft_memcpy(&(pf->buffer.buffer[pf->buffer.index]), str, to_write);
		str += to_write;
		len -= to_write;
		pf->buffer.index += to_write;
		if (pf->buffer.index == BUFFER_SIZE)
		{
			if ((tmp = buffer_flush(pf)) == -1)
				break ;
			ret += tmp;
		}
	}
	if (tmp == -1)
		return (-1);
	return (ret);
}
