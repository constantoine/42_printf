/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:46:16 by crebert           #+#    #+#             */
/*   Updated: 2020/04/04 17:53:26 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "ft_printf_utils.h"

static	uintmax_t		len_h_unsigned(va_list args)
{
	short	unsigned	int	num;

	num = (short int)va_arg(args, uintptr_t);
	return ((uintmax_t)num);
}

static	uintmax_t		len_hh_unsigned(va_list args)
{
	unsigned	char	num;

	num = (char)va_arg(args, uintptr_t);
	return ((uintmax_t)num);
}

static	uintmax_t		len_l_unsigned(va_list args)
{
	long	unsigned	int	num;

	num = (long unsigned int)va_arg(args, uintptr_t);
	return ((uintmax_t)num);
}

static	uintmax_t		len_ll_unsigned(va_list args)
{
	unsigned	long	long	int	num;

	num = (unsigned long long int)va_arg(args, uintptr_t);
	return ((uintmax_t)num);
}

uintmax_t				len_unsigned(t_printf *pf, va_list args)
{
	unsigned	int	num;

	num = 0;
	if (pf->format.len & SHORT_H)
		return (len_h_unsigned(args));
	if (pf->format.len & CHAR_HH)
		return (len_hh_unsigned(args));
	if (pf->format.len & LONG_L)
		return (len_l_unsigned(args));
	if (pf->format.len & LONGLONG_LL)
		return (len_ll_unsigned(args));
	num = va_arg(args, unsigned int);
	return (num);
}
