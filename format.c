/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:21:51 by crebert           #+#    #+#             */
/*   Updated: 2020/04/04 18:35:24 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include <limits.h>

int	parse_flags(t_format *format, const char *str_format)
{
	int		index;
	size_t	flag_pos;

	index = 0;
	format->flags = 0;
	if (str_format[0] == '%')
		format->flags |= PERCENT;
	if (str_format[0] == '%')
		return (0);
	while (str_format[index] &&
			(flag_pos = (size_t)ft_strchr(FLAGS, str_format[index])))
	{
		format->flags |= 1 << (flag_pos - (size_t)FLAGS);
		index++;
	}
	return (index);
}

int	parse_width(t_format *format, const char *str_format, va_list args)
{
	int	index;
	int	tmp;

	if ((index = 0) == 0 && str_format[0] == '*')
	{
		if (++index && (tmp = va_arg(args, int)) < 0)
		{
			if (tmp == INT_MIN)
				format->width = INT_MAX;
			else
				format->width = tmp * -1;
			format->flags |= MINUS;
		}
		else
			format->width = tmp;
	}
	else
	{
		format->width = ft_atoi(str_format);
		while (ft_strchr(BASE_DEC, str_format[index]) && str_format[index])
			index++;
	}
	return (index);
}

int	parse_prec(t_format *format, const char *s, va_list args)
{
	int	index;
	int	tmp;

	index = 0;
	while (s[index] == '.')
	{
		format->flags |= PRECISION;
		if ((format->precision = 0) == 0 && s[++index] == '*')
		{
			tmp = va_arg(args, int);
			if (index++ && tmp > 0)
				format->precision = (unsigned int)tmp;
		}
		else
		{
			tmp = ft_atoi(&s[index]);
			format->precision = tmp;
			while (ft_strchr(BASE_DEC, s[index]) && s[index])
				index++;
		}
		if (tmp < 0)
			format->flags &= ~PRECISION;
	}
	return (index);
}

int	parse_len(t_format *format, const char *str_format)
{
	size_t	len;

	if (str_format && str_format[0] == 'h' && str_format[1] == 'h')
	{
		format->len |= CHAR_HH;
		return (2);
	}
	if (str_format && str_format[0] == 'l' && str_format[1] == 'l')
	{
		format->len |= LONGLONG_LL;
		return (2);
	}
	if ((len = (size_t)ft_strchr(LEN, str_format[0])))
		format->len |= 1 << (len - (size_t)LEN);
	else
		return (0);
	return (1);
}

int	parse_type(t_format *format, const char *str_format)
{
	size_t	len;
	int		index;

	index = 0;
	if ((len = (size_t)ft_strchr(TYPE, str_format[index++])))
		format->type |= (1 << (len - (size_t)TYPE));
	else
		index = -1;
	return (index);
}
