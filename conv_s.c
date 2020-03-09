/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:46:16 by crebert           #+#    #+#             */
/*   Updated: 2020/03/09 23:15:03 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "ft_printf.h"
#include "buffer.h"

void	conv_s(t_printf *pf, char *str)
{
	size_t	len;
	size_t	padlen;

	str = str ?: NULL_STR;
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
