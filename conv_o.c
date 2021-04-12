/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:07:11 by crebert           #+#    #+#             */
/*   Updated: 2020/03/30 12:02:05 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "conv.h"
#include "libft/libft.h"
#include <limits.h>

void	conv_o(t_printf *pf, va_list args)
{
	char			str[BASE_8_LEN];
	char			*ptr;
	uintmax_t		num;
	char			sign;
	uint8_t			len;

	ft_bzero(str, BASE_8_LEN);
	len = BASE_8_LEN;
	num = len_unsigned(pf, args);
	pf->format.infos = &len;
	ptr = ft_itoa_base_pf(num, BASE_OCT, str, &(pf->format));
	if (!(sign = 0) && num && pf->format.flags & HASH)
		sign = 'X';
	else if (pf->format.flags & SPACE)
		sign = ' ';
	conv_num(pf, ptr, sign);
}
