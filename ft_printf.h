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

# include "parse_format.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef	struct	s_buffer
{
	char	buffer[BUFFER_SIZE];
	size_t	index;
	int		fd;
}				t_buffer;

typedef struct	s_printf
{
	int			len;
	char		*str;
	t_buffer	buffer;
	t_format	format;
	int			(*flush)(struct	s_printf *pf);
}				t_printf;

/*
** Buffer related functions
*/

int				buffer_flush(t_printf *pf);
int				buffer_flush_string_alloc(t_printf *pf);
int				buffer_flush_string_noalloc(t_printf *pf);
int				buffer_flush_string_noalloc_limit(t_printf *pf);
int				send_to_buffer(t_printf *pf, const char *str, size_t len);

int				ft_printf
	(const char *str, ...);
int				ft_vprintf
	(const char *str, va_list args);
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
