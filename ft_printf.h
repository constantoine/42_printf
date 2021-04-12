/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 13:45:06 by crebert           #+#    #+#             */
/*   Updated: 2020/03/10 09:12:42 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>

int				ft_printf(
	const char *str, ...);
int				ft_dprintf
	(int fd, const char *str, ...);
int				ft_vdprintf
	(int fd, const char *str, va_list args);
int				ft_sprintf
	(char *dst, const char *str, ...);
int				ft_ssprintf
	(char **dst, const char *str, ...);
int				ft_snprintf
	(char *dst, size_t limit, const char *str, ...);
int				ft_vsprintf
	(char *dst, const char *str, va_list args);
int				ft_vsnprintf
	(char *dst, size_t limit, const char *str, va_list args);

#endif
