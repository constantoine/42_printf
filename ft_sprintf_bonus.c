/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf_bonus.c                                 :+:      :+:    :+:   */
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

int			ft_ssprintf(char **dst, const char *str, ...)
{
	t_printf	pf;
	va_list		args;
	int			ret;
	char		*index;

	ft_bzero(&pf, sizeof(t_printf));
	pf.flush = buffer_flush_string_alloc;
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
	*dst = pf.str;
	return (pf.len);
}

int			ft_sprintf(char *dst, const char *str, ...)
{
	t_printf	pf;
	va_list		args;
	int			ret;
	char		*index;

	ft_bzero(&pf, sizeof(t_printf));
	pf.flush = buffer_flush_string_noalloc;
	pf.str = dst;
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

int			ft_snprintf(char *dst, size_t limit, const char *str, ...)
{
	t_printf	pf;
	va_list		args;
	int			ret;
	char		*index;

	ft_bzero(&pf, sizeof(t_printf));
	pf.flush = buffer_flush_string_noalloc_limit;
	pf.str = dst;
	pf.buffer.fd = limit;
	va_start(args, str);
	while (*str)
	{
		if (!(index = ft_strchr(str, '%')))
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

int			ft_vsprintf(char *dst, const char *str, va_list args)
{
	t_printf	pf;
	int			ret;
	char		*index;

	ft_bzero(&pf, sizeof(t_printf));
	pf.flush = buffer_flush_string_noalloc;
	pf.str = dst;
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

int			ft_vsnprintf(char *dst, size_t limit, const char *str, va_list args)
{
	t_printf	pf;
	int			ret;
	char		*index;

	ft_bzero(&pf, sizeof(t_printf));
	pf.flush = buffer_flush_string_noalloc_limit;
	pf.str = dst;
	pf.buffer.fd = limit;
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
