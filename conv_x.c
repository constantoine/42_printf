/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:53:41 by crebert           #+#    #+#             */
/*   Updated: 2020/03/29 16:55:47 by cleo             ###   ########.fr       */
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
	uint8_t	len;

	len = sizeof(uintmax_t) * 2 + 2;
	pf->format.infos = &len;
	prec = pf->format.precision;
	width = pf->format.width;
	pf->format.width = (width > prec ? width : prec);
	pf->format.precision = pf->format.precision ? UINT_MAX : 0;
	ptr = ft_itoa_base_pf(va_arg(args, unsigned int),
		BASE_HEX_M, str, &(pf->format));
	if (*ptr != 0 && *ptr != '0' && pf->format.flags & HASH)
	{
		ptr[-1] = 'x';
		ptr[-2] = '0';
		ptr = &ptr[-2];
	}
	pf->format.precision = UINT_MAX;
	conv_s_str(pf, ptr);
}

void	conv_x_capital(t_printf *pf, va_list args)
{
	char	str[sizeof(uintmax_t) * 2 + 2];
	char	*ptr;
	int		width;
	int		prec;
	uint8_t	len;

	len = sizeof(uintmax_t) * 2 + 2;
	pf->format.infos = &len;
	prec = pf->format.precision;
	width = pf->format.width;
	pf->format.width = (width > prec ? width : prec);
	pf->format.precision = pf->format.precision ? UINT_MAX : 0;
	ptr = ft_itoa_base_pf(va_arg(args, unsigned int),
		BASE_HEX_C, str, &(pf->format));
	if (*ptr != 0 && *ptr != '0' && pf->format.flags & HASH)
	{
		ptr[-1] = 'X';
		ptr[-2] = '0';
		ptr = &ptr[-2];
	}
	conv_s_str(pf, ptr);
}
