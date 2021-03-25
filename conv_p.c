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
	uintptr_t	ptr;
	char		str[BASE_16_LEN];
	char		*str_final;
	uint8_t		len;

	pf->format.flags &= ~PRECISION;
	pf->format.flags &= ~PLUS;
	ptr = va_arg(args, uintptr_t);
	len = BASE_16_LEN - 2;
	ft_bzero(str, BASE_16_LEN);
	pf->format.infos = &len;
	str_final = ft_itoa_base_pf(ptr, BASE_HEX_M, &(str[2]), &(pf->format));
	str_final = ft_memcpy(&(str_final[-2]), "0x", 2);
	if (!ptr)
		str_final = NIL_STR;
	conv_s_str(pf, str_final);
}