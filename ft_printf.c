/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:05:28 by crebert           #+#    #+#             */
/*   Updated: 2020/03/10 12:21:00 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "conv.h"
#include <stdio.h>

static void	conv(t_printf *pf, va_list args)
{
	static void		(*conv[19])(t_printf *pf, va_list args);
	int				flag;

	flag = -1;
	if (!conv[12])
	{
		conv[9] = conv_x;
		conv[10] = conv_x_capital;
		conv[11] = conv_o;
		conv[12] = conv_s;
		conv[13] = conv_c;
		conv[18] = conv_percent;
	}
	while (++flag <= 19)
		if (pf->format.type & (1ul << flag))
			conv[flag](pf, args);
}

int			ft_printf(const char *str, ...)
{
	t_printf	pf;
	va_list		args;
	int			ret;
	char		*index;

	pf.len = 0;
	pf.buffer.index = 0;
	pf.buffer.fd = 1;
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
	return (pf.len);
}

int			main(void)
{
	ft_printf("%X", 0);
}