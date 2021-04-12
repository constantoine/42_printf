/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 10:34:59 by crebert           #+#    #+#             */
/*   Updated: 2020/03/10 11:02:02 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "libft/libft.h"
#include "ft_printf_utils.h"

void	conv_c(t_printf *pf, va_list args)
{
	size_t	len;
	size_t	padlen;
	char	c;

	c = (char)va_arg(args, int);
	len = 1;
	padlen = pf->format.width > len ? pf->format.width - len : 0;
	if (!padlen)
		pf->len += send_to_buffer(pf, &c, len);
	if (!padlen)
		return ;
	if (!(pf->format.flags & MINUS))
		while (padlen--)
			pf->len += send_to_buffer(pf, " ", 1);
	pf->len += send_to_buffer(pf, &c, len);
	if (pf->format.flags & MINUS)
		while (padlen--)
			pf->len += send_to_buffer(pf, " ", 1);
}
