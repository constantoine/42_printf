/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 23:00:32 by crebert           #+#    #+#             */
/*   Updated: 2020/03/10 12:14:46 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_H
#define CONV_H

void conv_u(t_printf *pf, va_list args);
void conv_x(t_printf *pf, va_list args);
void conv_x_capital(t_printf *pf, va_list args);
void conv_o(t_printf *pf, va_list args);
void conv_s(t_printf *pf, va_list args);
void conv_c(t_printf *pf, va_list args);
void conv_percent(t_printf *pf, va_list args);

void conv_s_str(t_printf *pf, char *str);
char *ft_itoa_base_pf(int nbr, char *base, char *dst, int len_dst);

#endif
