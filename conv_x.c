/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:53:41 by crebert           #+#    #+#             */
/*   Updated: 2020/03/10 12:16:57 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "ft_printf.h"
#include "conv.h"
#include <limits.h>

void	conv_x(t_printf *pf, va_list args)
{
	char	str[sizeof(uintmax_t) * 2 + 2];
	char	*ptr;
	int		width;
	int		prec;

	prec = pf->format.precision;
	width = pf->format.width;
	pf->format.width = (width > prec ? width : prec);
	pf->format.precision = UINT_MAX;
	ptr = ft_itoa_base_pf(va_arg(args, unsigned int),
		BASE_HEX_M, str, sizeof(uintmax_t) * 2 + 2);
	conv_s_str(pf, ptr);
}

void	conv_x_capital(t_printf *pf, va_list args)
{
	char	str[sizeof(uintmax_t) * 2 + 2];
	char	*ptr;
	int		width;
	int		prec;

	prec = pf->format.precision;
	width = pf->format.width;
	pf->format.width = (width > prec ? width : prec);
	pf->format.precision = UINT_MAX;
	ptr = ft_itoa_base_pf(va_arg(args, unsigned int),
		BASE_HEX_C, str, sizeof(uintmax_t) * 2 + 2);
	conv_s_str(pf, ptr);
}
