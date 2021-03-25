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
#include "ft_printf.h"
#include "conv.h"
#include <limits.h>

void			conv_u(t_printf *pf, va_list args)
{
	unsigned int	num;
	char			str[BASE_10_LEN];
	char			*str_final;
	uint8_t			len;
	char			sign;

	if (pf->format.flags & PLUS)
		pf->format.flags &= ~PLUS;
	num = va_arg(args, unsigned int);
	len = BASE_10_LEN;
	pf->format.infos = &len;
	str_final = ft_itoa_noalloc(ft_abs(num), str, BASE_10_LEN);
	//printf("atoi: %d->%d->%s\n", ft_abs(num), num, str_final);
	if (pf->format.flags & PLUS)
		sign = '+';
	else if (pf->format.flags & SPACE)
		sign = ' ';
	if (!num && pf->format.flags & PRECISION && !pf->format.precision)
		str_final[0] = 0;
	conv_num(pf, str_final, sign);
}
