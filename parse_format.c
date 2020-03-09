/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:12:20 by crebert           #+#    #+#             */
/*   Updated: 2020/03/09 23:58:27 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_format.h"

int	parse_format(t_format *format, const char *str_format, va_list args)
{
	int	index;

	index = 1;
	index += parse_flags(format, &str_format[index]);
	index += parse_width(format, &str_format[index], args);
	index += parse_prec(format, &str_format[index], args);
	index += parse_len(format, &str_format[index]);
	index = (parse_type(format, &str_format[index]) == 1 ? index + 1 : -1);
	if (index == -1)
		format->flags |= ERROR;
	return (index);
}
