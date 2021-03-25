/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:46:16 by crebert           #+#    #+#             */
/*   Updated: 2021/02/09 14:53:26 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "ft_printf.h"
#include "conv.h"
#include <limits.h>

uintmax_t	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

void			conv_num(t_printf *pf, char *str, char sign)
{
	size_t	len;
	size_t	len_sign;
	int		padding;
	int		zero_pad;
	char	pad;

	if (pf->format.flags & PRECISION && pf->format.flags & ZERO)
		pf->format.flags &= ~ZERO;
	pad = pf->format.flags & ZERO ? '0' : ' ';
	len = ft_strlen(str);
	//printf(str);
	//printf("len: %d\n", len);
	if (!(zero_pad = 0) && pf->format.precision > len)
		zero_pad = pf->format.precision - len;
	len_sign = len + zero_pad;
	if (sign)
		len_sign++;
	//printf("len_sign: %d\n", len_sign);
	if (!(padding = 0) && pf->format.width > len_sign)
		padding = pf->format.width - len_sign;
	if (!(pf->format.flags & MINUS) && !(pf->format.flags & PRECISION) && pad == '0')
		zero_pad += padding;
	if (!(pf->format.flags & MINUS) && !(pf->format.flags & PRECISION) && pad == '0')
		padding = 0;
	//printf("prec: %d; width: %d; padding: %d; zero_pad: %d\n", pf->format.precision, pf->format.width, padding, zero_pad);
	while (!(pf->format.flags & MINUS)  && padding--)
		pf->len += send_to_buffer(pf, &pad, 1);
	if (sign)
		pf->len += send_to_buffer(pf, &sign, 1);
	while (zero_pad--)
		pf->len += send_to_buffer(pf, "0", 1);
	pf->len += send_to_buffer(pf, str, len);
	while (padding-- > 0)
		pf->len += send_to_buffer(pf, &pad, 1);
}

void			conv_d(t_printf *pf, va_list args)
{
	int		num;
	char	str[BASE_10_LEN];
	char	*str_final;
	uint8_t	len;
	char	sign;

	num = va_arg(args, int);
	len = BASE_10_LEN;
	pf->format.infos = &len;
	str_final = ft_itoa_noalloc(ft_abs(num), str, BASE_10_LEN);
	//printf("atoi: %d->%d->%s\n", ft_abs(num), num, str_final);
	if (!(sign = 0) && num < 0)
		sign = '-';
	else if (pf->format.flags & PLUS)
		sign = '+';
	else if (pf->format.flags & SPACE)
		sign = ' ';
	if (!num && pf->format.flags & PRECISION && !pf->format.precision)
		str_final[0] = 0;
	conv_num(pf, str_final, sign);
}

void			conv_i(t_printf *pf, va_list args)
{
	conv_d(pf, args);
}