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

uintmax_t		ft_abs(intmax_t num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

void			conv_num_print(t_printf *pf, char sign, char pad, int padding)
{
	char	*str;
	int		zero_pad;

	str = ((char **)pf->format.infos)[0];
	zero_pad = *(((int **)pf->format.infos)[1]);
	if (!(pf->format.flags & MINUS) &&
		!(pf->format.flags & PRECISION) && pad == '0')
		padding = 0;
	while (!(pf->format.flags & MINUS) && padding--)
		pf->len += send_to_buffer(pf, &pad, 1);
	if (sign == 'x' || sign == 'X')
		pf->len += send_to_buffer(pf, "0", 1);
	if (sign)
		pf->len += send_to_buffer(pf, &sign, 1);
	while (zero_pad--)
		pf->len += send_to_buffer(pf, "0", 1);
	pf->len += send_to_buffer(pf, str, ft_strlen(str));
	while (padding-- > 0)
		pf->len += send_to_buffer(pf, &pad, 1);
}

void			conv_num(t_printf *pf, char *str, char sign)
{
	size_t	len;
	size_t	len_sign;
	int		padding;
	int		zero_pad;
	char	pad;

	pf->format.infos = (void*[2]){str, &zero_pad};
	if (pf->format.flags & PRECISION && pf->format.flags & ZERO)
		pf->format.flags &= ~ZERO;
	pad = pf->format.flags & ZERO ? '0' : ' ';
	len = ft_strlen(str);
	if (!(zero_pad = 0) && pf->format.precision > len)
		zero_pad = pf->format.precision - len;
	len_sign = len + zero_pad;
	if (sign)
		len_sign++;
	if (sign == 'x' || sign == 'X')
		len_sign++;
	if (!(padding = 0) && pf->format.width > len_sign)
		padding = pf->format.width - len_sign;
	if (!(pf->format.flags & MINUS) &&
		!(pf->format.flags & PRECISION) && pad == '0')
		zero_pad += padding;
	conv_num_print(pf, sign, pad, padding);
}

void			conv_d(t_printf *pf, va_list args)
{
	intmax_t	num;
	char		str[BASE_10_LEN];
	char		*str_final;
	uint8_t		len;
	char		sign;

	num = len_signed(pf, args);
	len = BASE_10_LEN;
	ft_bzero(str, BASE_10_LEN);
	pf->format.infos = &len;
	str_final = ft_itoa_noalloc(ft_abs(num), str, BASE_10_LEN);
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
