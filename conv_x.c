/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:53:41 by crebert           #+#    #+#             */
/*   Updated: 2020/03/30 12:02:18 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "ft_printf.h"
#include "conv.h"
#include <limits.h>
#include <stdio.h>

void	conv_x(t_printf *pf, va_list args)
{
	char	str[BASE_16_LEN];
	char	*ptr;
	int		width;
	int		prec;
	uint8_t	len;

	len = BASE_16_LEN;
	pf->format.infos = &len;
	prec = pf->format.precision;
	width = pf->format.width;
	pf->format.width = (width > prec ? width : prec);
	ptr = ft_itoa_base_pf(va_arg(args, unsigned int),
		BASE_HEX_M, str, &(pf->format));
	if (*ptr != 0 && *ptr != '0' && pf->format.flags & HASH)
	{
		ptr[-1] = 'x';
		ptr[-2] = '0';
		ptr = &ptr[-2];
	}
	if (pf->format.width <= (unsigned int)prec)
		pf->format.flags |= ZERO;
	conv_s_str(pf, ptr);
}

void	conv_x_capital(t_printf *pf, va_list args)
{
	char	str[BASE_16_LEN];
	char	*ptr;
	int		width;
	int		prec;
	uint8_t	len;

	len = BASE_16_LEN;
	pf->format.infos = &len;
	prec = pf->format.precision;
	width = pf->format.width;
	pf->format.width = (width > prec ? width : prec);
	ptr = ft_itoa_base_pf(va_arg(args, unsigned int),
		BASE_HEX_C, str, &(pf->format));
	if (*ptr != 0 && *ptr != '0' && pf->format.flags & HASH)
	{
		ptr[-1] = 'X';
		ptr[-2] = '0';
		ptr = &ptr[-2];
	}
	if (pf->format.width <= (unsigned int)prec)
		pf->format.flags |= ZERO;
	conv_s_str(pf, ptr);
}
