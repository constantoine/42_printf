/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:05:28 by crebert           #+#    #+#             */
/*   Updated: 2021/02/09 14:40:26 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "conv.h"
#include "libft/libft.h"
#include "parse_format.h"
#include <stdio.h>

int			ft_dprintf(int fd, const char *str, ...)
{
	t_printf	pf;
	va_list		args;
	int			ret;
	char		*index;

	ft_bzero(&pf, sizeof(t_printf));
	pf.buffer.fd = fd;
	pf.flush = buffer_flush;
	va_start(args, str);
	while (*str)
	{
		index = ft_strchr(str, '%');
		if (!index)
			send_to_buffer(&pf, str, ft_strlen(str));
		if (!index)
			break ;
		send_to_buffer(&pf, str, index - str);
		str += index - str;
		str += parse_format(&(pf.format), str, args);
		conv(&pf, args);
	}
	if ((ret = buffer_flush(&pf)) != -1)
		pf.len += ret;
	va_end(args);
	return (pf.len);
}

int			ft_vdprintf(int fd, const char *str, va_list args)
{
	t_printf	pf;
	int			ret;
	char		*index;

	ft_bzero(&pf, sizeof(t_printf));
	pf.buffer.fd = fd;
	pf.flush = buffer_flush;
	while (*str)
	{
		index = ft_strchr(str, '%');
		if (!index)
			send_to_buffer(&pf, str, ft_strlen(str));
		if (!index)
			break ;
		send_to_buffer(&pf, str, index - str);
		str += index - str;
		str += parse_format(&(pf.format), str, args);
		conv(&pf, args);
	}
	if ((ret = buffer_flush(&pf)) != -1)
		pf.len += ret;
	return (pf.len);
}

int			ft_vprintf(const char *str, va_list args)
{
	t_printf	pf;
	int			ret;
	char		*index;

	ft_bzero(&pf, sizeof(t_printf));
	pf.flush = buffer_flush;
	while (*str)
	{
		index = ft_strchr(str, '%');
		if (!index)
			send_to_buffer(&pf, str, ft_strlen(str));
		if (!index)
			break ;
		send_to_buffer(&pf, str, index - str);
		str += index - str;
		str += parse_format(&(pf.format), str, args);
		conv(&pf, args);
	}
	if ((ret = buffer_flush(&pf)) != -1)
		pf.len += ret;
	return (pf.len);
}
