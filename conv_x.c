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

void			conv_x(t_printf *pf, va_list args)
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
	ft_bzero(str, BASE_16_LEN);
	pf->format.infos = &len;
	str_final = ft_itoa_base_pf(num, BASE_HEX_M, str, &(pf->format));
	//printf("atoi: %d->%d->%s\n", ft_abs(num), num, str_final);
	if (!(sign = 0) && num && pf->format.flags & HASH)
		sign = 'x';
	else if (pf->format.flags & SPACE)
		sign = ' ';
	if (!num && pf->format.flags & PRECISION && !pf->format.precision)
		str_final[0] = 0;
	conv_num(pf, str_final, sign);
}

void			conv_x_capital(t_printf *pf, va_list args)
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
	ft_bzero(str, BASE_16_LEN);
	pf->format.infos = &len;
	str_final = ft_itoa_base_pf(num, BASE_HEX_C, str, &(pf->format));
	//printf("atoi: %d->%d->%s\n", ft_abs(num), num, str_final);
	if (!(sign = 0) && num && pf->format.flags & HASH)
		sign = 'X';
	else if (pf->format.flags & SPACE)
		sign = ' ';
	if (!num && pf->format.flags & PRECISION && !pf->format.precision)
		str_final[0] = 0;
	conv_num(pf, str_final, sign);
}