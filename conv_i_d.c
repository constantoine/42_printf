/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_i_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 15:36:13 by cleo              #+#    #+#             */
/*   Updated: 2020/05/11 16:26:31 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "ft_printf.h"
#include "conv.h"
#include <limits.h>

void	conv_num_sign(t_printf *pf, char *str)
{
	char	zero;

	zero = '0';
	if (pf->format.precision != UINT_MAX)
	{
		if (pf->format.precision >= ft_strlen(str) - 1)
			send_to_buffer(pf, &str[0], 1);
		while (pf->format.precision-- >= ft_strlen(str))
			send_to_buffer(pf, &zero, 1);
	}
	else
		pf->format.precision = get_uint_size(num);

	send_to_buffer(pf, &str[1], ft_strlen(str) - 1);
}

void	conv_num_str(t_printf *pf, char *str)
{
	size_t	len;
	size_t	padlen;
	char	zero;
	char	pad;
	char	def;

	def = 0;
	len = pf->format.precision;
	if (((zero = '0') && (len == 0 || len == UINT_MAX)) && (def = 1))
		len = ft_strlen(str);
	if (pf->format.flags & ZERO)
		def = 0;
	pad = ' ';
	padlen = pf->format.width > len ? pf->format.width - len : 0;
	while (!(pf->format.flags & MINUS) && padlen && padlen--)
		pf->len += send_to_buffer(pf, &pad, 1);
	if ((*str == '-' || *str == '+' || *str == ' ') &&
		!def && len >= ft_strlen(str) - 1)
		conv_num_sign(pf, str);
	else
	{
		while (pf->format.precision-- > ft_strlen(str))
			pf->len += send_to_buffer(pf, &zero, 1);
		pf->len += send_to_buffer(pf, str, ft_strlen(str));
	}
	while (pf->format.flags & MINUS && padlen--)
		pf->len += send_to_buffer(pf, &pad, 1);
}

void	conv_d(t_printf *pf, va_list args)
{
	char				str[BASE_10_LEN];
	char				*ptr;
	uint8_t				len;

	len = BASE_10_LEN;
	pf->format.infos = &len;
	ptr = ft_itoa_base_pf_signed(va_arg(args, unsigned int),
							BASE_DEC, str, &(pf->format));
	conv_num_str(pf, ptr);
}

void	conv_i(t_printf *pf, va_list args)
{
	conv_d(pf, args);
}
