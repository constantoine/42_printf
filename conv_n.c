/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:07:11 by crebert           #+#    #+#             */
/*   Updated: 2020/03/30 12:02:05 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "ft_printf.h"
#include "conv.h"
#include <limits.h>

void	conv_n(t_printf *pf, va_list args)
{
	int ret;

	ret = buffer_flush(pf);
	if (ret == -1)
		pf->format.flags |= ERROR;
	pf->len += ret;
	if (pf->format.len & SHORT_H)
		*va_arg(args, short*) = (short)(pf->len);
	else if (pf->format.len & CHAR_HH)
		*va_arg(args, char*) = (char)(pf->len);
	else if (pf->format.len & LONG_L)
		*va_arg(args, long int*) = (long int)(pf->len);
	else if (pf->format.len & LONGLONG_LL)
		*va_arg(args, long long int*) = (long long int)(pf->len);
	else
		*va_arg(args, int*) = pf->len;
}
