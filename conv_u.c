/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:10:09 by crebert           #+#    #+#             */
/*   Updated: 2020/04/04 15:16:38 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "libft/libft.h"
#include "conv.h"
#include <limits.h>

void			conv_u(t_printf *pf, va_list args)
{
	uintmax_t		num;
	char			str[BASE_10_LEN];
	char			*str_final;
	uint8_t			len;
	char			sign;

	pf->format.flags &= ~PLUS;
	num = len_unsigned(pf, args);
	len = BASE_10_LEN;
	pf->format.infos = &len;
	ft_bzero(str, BASE_10_LEN);
	str_final = ft_itoa_noalloc(ft_abs(num), str, BASE_10_LEN);
	if (!(sign = 0) && pf->format.flags & PLUS)
		sign = '+';
	else if (pf->format.flags & SPACE)
		sign = ' ';
	if (!num && pf->format.flags & PRECISION && !pf->format.precision)
		str_final[0] = 0;
	conv_num(pf, str_final, sign);
}
