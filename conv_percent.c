/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:18:57 by crebert           #+#    #+#             */
/*   Updated: 2020/03/10 11:21:37 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include "ft_printf.h"
#include "conv.h"

void	conv_percent(t_printf *pf, va_list args)
{
	(void)args;
	pf->len += send_to_buffer(pf, "%", 1);
}
