/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:07:11 by crebert           #+#    #+#             */
/*   Updated: 2020/03/30 12:02:05 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "ft_printf.h"
#include "conv.h"
#include <limits.h>

void			conv_p(t_printf *pf, va_list args)
{
	unsigned int	num;
	char			str[BASE_16_LEN];
	char			*str_final;
	uint8_t			len;
	char			sign;

	if (pf->format.flags & PLUS)
		pf->format.flags &= ~PLUS;
	num = va_arg(args, unsigned int);
	len = BASE_16_LEN;
    printf("%d\n", num);
	pf->format.infos = &len;
	str_final = ft_itoa_base_pf(num, BASE_HEX_M, str, &(pf->format));
	//printf("atoi: %d->%d->%s\n", ft_abs(num), num, str_final);
	if (pf->format.flags & PLUS)
		sign = '+';
	else if (pf->format.flags & SPACE)
		sign = ' ';
	if (!num && pf->format.flags & PRECISION && !pf->format.precision)
		str_final[0] = 0;
	conv_num(pf, str_final, sign);
}