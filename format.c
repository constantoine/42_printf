/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:21:51 by crebert           #+#    #+#             */
/*   Updated: 2020/02/18 01:09:33 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

static size_t	parse_flags(t_format *format, char *str_format)
{
	size_t		index;
	size_t		flag_pos;

	index = 0;
	if (str_format[0] == '%')
		format->flags |= PERCENT;
	if (str_format[0] == '%')
		return (format);
	while (str_format[index] &&
		(flag_pos = (size_t)ft_strchr(FLAGS, str_format[index])))
		format->flags |= 1 << (flag_pos - (size_t)&str_format[index++]);
	if ((format->flags >> 1) & 1u)
		format->flags &= ~SPACE;
	if ((format->flags >> 0) & 1u)
		format->flags &= ~ZERO;
	return (index);
}

static size_t	parse_width(t_format *format, char *str_format, va_list args)
{
	size_t	index;

	index = 0;
	if (str_format[index] == '*')
	{
		format->width = va_arg(args, unsigned int);
			index++;
	}
	else
	{
		format->width = ft_atoi(str_format);
		while (ft_strchr(BASE_DEC, str_format[index]) && str_format[index])
			index++;
	}
	return (index);
}

static size_t	parse_prec(t_format *format, char *str_format, va_list args)
{
	size_t	index;

	index = 0;
	while (str_format[index] == '.')
	{
		index++;
		if (str_format[index] == '*')
		{
			format->precision = va_arg(args, unsigned int);
			index++;
		}
		else {
			format->precision = ft_atoi(&str_format[index]) > 0 ?
				ft_atoi(&str_format[index]) : 0;
			while (ft_strchr(BASE_DEC, str_format[index]) && str_format[index])
				index++;
		}
	}
	return (index);
}

static size_t	parse_len(t_format *format, char *str_format)
{

}

t_format		*parse_format(t_format *format, char *str_format, va_list args)
{
	size_t		index;
	size_t		flag_pos;

	index = 0;
	str_format += (size_t)parse_flags(format, str_format);
	str_format += (size_t)parse_width(format, str_format, args);
	str_format += (size_t)parse_prec(format, str_format, args);
	str_format += (size_t)parse_len(format, str_format);
	return (format);
}
