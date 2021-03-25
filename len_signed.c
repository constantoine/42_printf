/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_signed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:46:16 by crebert           #+#    #+#             */
/*   Updated: 2020/04/04 17:53:26 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "ft_printf.h"

static	intmax_t	len_h_signed(va_list args)
{
	short	int	num;

	num = (short int)va_arg(args, uintptr_t);
	return ((intmax_t)num);
}

static	intmax_t	len_hh_signed(va_list args)
{
	char	num;

	num = (char)va_arg(args, uintptr_t);
	return ((intmax_t)num);
}

static	intmax_t	len_l_signed(va_list args)
{
	long	int	num;

	num = (long int)va_arg(args, uintptr_t);
	return ((intmax_t)num);
}

static	intmax_t	len_ll_signed(va_list args)
{
	long	long	int	num;

	num = (long long int)va_arg(args, uintptr_t);
	return ((intmax_t)num);
}

intmax_t			len_signed(t_printf *pf, va_list args)
{
	int	num;

	num = 0;
	if (pf->format.len & SHORT_H)
		return (len_h_signed(args));
	if (pf->format.len & CHAR_HH)
		return (len_hh_signed(args));
	if (pf->format.len & LONG_L)
		return (len_l_signed(args));
	if (pf->format.len & LONGLONG_LL)
		return (len_ll_signed(args));
	num = va_arg(args, int);
	return (num);
}
