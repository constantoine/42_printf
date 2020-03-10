/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:05:28 by crebert           #+#    #+#             */
/*   Updated: 2020/03/10 01:07:47 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "conv.h"

void	conv(t_printf *pf, va_list args)
{
	if (pf->format.type & STRING_S)
		conv_s(pf, va_arg(args, char *));
}

int		ft_printf(const char *str, ...)
{
	t_printf	pf;
	va_list		args;
	int			ret;
	char		*index;

	pf.len = 0;
	pf.buffer.index = 0;
	pf.buffer.fd = 1;
	ft_bzero(pf.buffer.buffer, BUFFER_SIZE);
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

int		main(void)
{
	ft_printf("ok%-*.2s%s", 15, "ok", "bit");
}
