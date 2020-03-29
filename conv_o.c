/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:07:11 by crebert           #+#    #+#             */
/*   Updated: 2020/03/29 16:55:35 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "ft_printf.h"
#include "conv.h"
#include <limits.h>

void	conv_o(t_printf *pf, va_list args)
{
	char	str[(uint8_t)(sizeof(uintmax_t) * 8 * LOG2_8) + 2 + 1];
	char	*ptr;
	int		width;
	int		prec;
	uint8_t	len;

	len = (uint8_t)(sizeof(uintmax_t) * 8 * LOG2_8) + 2 + 1;
	pf->format.infos = &len;
	prec = pf->format.precision;
	width = pf->format.width;
	pf->format.width = (width > prec ? width : prec);
	pf->format.precision = pf->format.precision ? UINT_MAX : 0;
	ptr = ft_itoa_base_pf(va_arg(args, unsigned int),
		BASE_OCT, str, &(pf->format));
	if (*ptr != 0 && *ptr != '0' && pf->format.flags & HASH)
	{
		ptr[-1] = '0';
		ptr = &ptr[-1];
	}
	pf->format.precision = UINT_MAX;
	conv_s_str(pf, ptr);
}
