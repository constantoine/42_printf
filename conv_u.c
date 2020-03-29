/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:10:09 by crebert           #+#    #+#             */
/*   Updated: 2020/03/29 16:55:42 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "ft_printf.h"
#include "conv.h"
#include <limits.h>

void	conv_u(t_printf *pf, va_list args)
{
	char	str[(uint8_t)(sizeof(uintmax_t) * 8 * LOG2) + 2];
	char	*ptr;
	int		width;
	int		prec;
	uint8_t	len;

	len = (uint8_t)(sizeof(uintmax_t) * 8 * LOG2) + 2;
	pf->format.infos = &len;
	prec = pf->format.precision;
	width = pf->format.width;
	pf->format.width = (width > prec ? width : prec);
	pf->format.precision = pf->format.precision ? UINT_MAX : 0;
	ptr = ft_itoa_base_pf(va_arg(args, unsigned int),
		BASE_DEC, str, &(pf->format));
	pf->format.precision = UINT_MAX;
	conv_s_str(pf, ptr);
}
