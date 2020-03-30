/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_i_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 15:36:13 by cleo              #+#    #+#             */
/*   Updated: 2020/03/30 12:01:41 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "ft_printf.h"
#include "conv.h"
#include <limits.h>

void	conv_d(t_printf *pf, va_list args)
{
	char	str[BASE_10_LEN];
	char	*ptr;
	int		width;
	int		prec;
	uint8_t	len;

	len = BASE_10_LEN;
	pf->format.infos = &len;
	prec = pf->format.precision;
	width = pf->format.width;
	pf->format.width = (width > prec ? width : prec);
	pf->format.precision = pf->format.precision ? UINT_MAX : 0;
	ptr = ft_itoa_base_pf_signed(va_arg(args, unsigned int),
							BASE_DEC, str, &(pf->format));
	pf->format.precision = UINT_MAX;
	conv_s_str(pf, ptr);
}

void	conv_i(t_printf *pf, va_list args)
{
	conv_d(pf, args);
}
