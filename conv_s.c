/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:46:16 by crebert           #+#    #+#             */
/*   Updated: 2020/03/10 12:19:25 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "ft_printf.h"

void	conv_s_str(t_printf *pf, char *str)
{
	size_t	len;
	size_t	padlen;

	str = str ? str : NULL_STR;
	len = pf->format.precision < ft_strlen(str) ?
		pf->format.precision : ft_strlen(str);
	padlen = pf->format.width > len ? pf->format.width - len : 0;
	if (!padlen)
		pf->len += send_to_buffer(pf, str, len);
	if (!padlen)
		return ;
	if (!(pf->format.flags & MINUS))
		while (padlen--)
			pf->len += send_to_buffer(pf, " ", 1);
	pf->len += send_to_buffer(pf, str, len);
	if (pf->format.flags & MINUS)
		while (padlen--)
			pf->len += send_to_buffer(pf, " ", 1);
}

void	conv_s(t_printf *pf, va_list args)
{
	size_t	len;
	size_t	padlen;
	char	*str;

	str = va_arg(args, char *);
	str = str ? str : NULL_STR;
	len = pf->format.precision < ft_strlen(str) ?
		pf->format.precision : ft_strlen(str);
	padlen = pf->format.width > len ? pf->format.width - len : 0;
	if (!padlen)
		pf->len += send_to_buffer(pf, str, len);
	if (!padlen)
		return ;
	if (!(pf->format.flags & MINUS))
		while (padlen--)
			pf->len += send_to_buffer(pf, " ", 1);
	pf->len += send_to_buffer(pf, str, len);
	if (pf->format.flags & MINUS)
		while (padlen--)
			pf->len += send_to_buffer(pf, " ", 1);
}
