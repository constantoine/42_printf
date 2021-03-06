/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:05:28 by crebert           #+#    #+#             */
/*   Updated: 2021/02/09 14:40:26 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "conv.h"
#include "parse_format.h"
#include "format.h"
#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

void		conv(t_printf *pf, va_list args)
{
	static void	(*conv[19])(t_printf *pf, va_list args);
	int			flag;

	flag = -1;
	if (!conv[12])
	{
		conv[0] = conv_d;
		conv[1] = conv_i;
		conv[2] = conv_u;
		conv[9] = conv_x;
		conv[10] = conv_x_capital;
		conv[11] = conv_o;
		conv[12] = conv_s;
		conv[13] = conv_c;
		conv[14] = conv_p;
		conv[17] = conv_n;
		conv[18] = conv_percent;
	}
	while (++flag <= 19)
		if (pf->format.type & (1ul << flag))
			if (conv[flag])
				conv[flag](pf, args);
}

int			ft_printf(const char *str, ...)
{
	t_printf	pf;
	va_list		args;
	int			ret;
	char		*index;

	ft_bzero(&pf, sizeof(t_printf));
	pf.buffer.fd = 1;
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
