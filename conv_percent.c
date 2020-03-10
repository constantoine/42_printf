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
	pf->format.precision = 1;
	pf->format.width = 0;
	conv_c(pf, args);
}
