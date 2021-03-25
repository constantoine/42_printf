/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 23:00:32 by crebert           #+#    #+#             */
/*   Updated: 2020/03/28 16:24:36 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONV_H
# define CONV_H

void	conv_d(t_printf *pf, va_list args);
void	conv_i(t_printf *pf, va_list args);
void	conv_u(t_printf *pf, va_list args);
void	conv_x(t_printf *pf, va_list args);
void	conv_x_capital(t_printf *pf, va_list args);
void	conv_n(t_printf *pf, va_list args);
void	conv_o(t_printf *pf, va_list args);
void	conv_s(t_printf *pf, va_list args);
void	conv_c(t_printf *pf, va_list args);
void	conv_p(t_printf *pf, va_list args);
void	conv_percent(t_printf *pf, va_list args);

uintmax_t		ft_abs(int num);
void			conv_num(t_printf *pf, char *str, char sign);
void			conv_s_str(t_printf *pf, char *str);
char			*ft_itoa_base_pf
	(uintmax_t nbr, char *base, char *dst, t_format *format);
char			*ft_itoa_noalloc(uintmax_t nb, char *num, size_t size);

#endif
