/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:21:51 by crebert           #+#    #+#             */
/*   Updated: 2020/02/01 19:30:16 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"

t_format	*new_format()
{
	t_format	*format;

	if (!(format = malloc(sizeof(t_format))))
		return (NULL);
	format->flags = 0;
	format->len = 0;
	format->precision = 0;
	format->type = 0;
	format->width = 0;
	return (format);
}

t_format	*parse_format(char *str_format)
{
	t_format	*format;

	if (!(format = new_format()))
		return (NULL);
}
