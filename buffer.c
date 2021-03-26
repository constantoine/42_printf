/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:49:36 by crebert           #+#    #+#             */
/*   Updated: 2020/04/04 15:17:01 by cleo             ###   ########.fr       */
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

int		buffer_flush_string_alloc(t_printf *pf)
{
	int	ret;

	ret = pf->buffer.index + 1;
	pf->buffer.index = 0;
	if (!(pf->str = ft_strjoin(pf->str, pf->buffer.buffer)))
		return (-1);
	return (ret);
}

int		buffer_flush_string_noalloc(t_printf *pf)
{
	int	ret;

	ret = pf->buffer.index + 1;
	ft_memcpy(&((pf->str)[pf->len]), pf->buffer.buffer, ret);
	pf->buffer.index = 0;
	return (ret);
}

int		buffer_flush_string_noalloc_limit(t_printf *pf)
{
	int	ret;

	ret = pf->buffer.index + 1;
	pf->buffer.index = 0;
	if (pf->len == pf->buffer.fd)
		return (ret);
	if ((pf->len + ret) > pf->buffer.fd)
	{
		ft_memcpy(&((pf->str)[pf->len]), pf->buffer.buffer,
			pf->buffer.fd - pf->len - 1);
		ft_memcpy(&((pf->str)[pf->buffer.fd - 1]), "", 1);
	}
	else
		ft_memcpy(&((pf->str)[pf->len]), pf->buffer.buffer, ret);
	return (ret);
}

int		send_to_buffer(t_printf *pf, const char *str, size_t len)
{
	size_t	to_write;
	size_t	ret;
	int		tmp;

	ret = 0;
	tmp = 0;
	while (len)
	{
		to_write = (len > BUFFER_SIZE - pf->buffer.index ? BUFFER_SIZE : len);
		ft_memcpy(&(pf->buffer.buffer[pf->buffer.index]), str, to_write);
		str += to_write;
		len -= to_write;
		pf->buffer.index += to_write;
		if (pf->buffer.index == BUFFER_SIZE)
		{
			if ((tmp = (pf->flush)(pf)) == -1)
				break ;
			ret += tmp;
		}
	}
	if (tmp == -1)
		return (-1);
	return (ret);
}
