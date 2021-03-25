/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:46:16 by crebert           #+#    #+#             */
/*   Updated: 2020/04/04 17:53:26 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "ft_printf.h"

void	conv_s_str(t_printf *pf, char *str)
{
	size_t	len;
	size_t	to_print;
	int		padding;
	char	pad;

	pad = pf->format.flags & ZERO ? '0' : ' ';
	len = ft_strlen(str);
	to_print = len;
	padding = 0;
	if (pf->format.flags & PRECISION && pf->format.precision < len)
		to_print = pf->format.precision;
	if (pf->format.width > to_print)
		padding = pf->format.width - to_print;
	if (!(pf->format.flags & MINUS))
		while (padding--)
			pf->len += send_to_buffer(pf, &pad, 1);
	pf->len += send_to_buffer(pf, str, to_print);
	while (padding-- > 0)
		pf->len += send_to_buffer(pf, &pad, 1);	
}

void	conv_s(t_printf *pf, va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	//printf("prec: %d, width: %d", pf->format.precision, pf->format.width);
	if (!str && pf->format.precision && pf->format.precision < ft_strlen(NULL_STR))
		pf->format.precision = 0;
	str = str ? str : NULL_STR;
	conv_s_str(pf, str);
}
