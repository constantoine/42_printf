/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:02:11 by crebert           #+#    #+#             */
/*   Updated: 2020/03/30 12:00:57 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

/*
** Constant used to calculate argument lenght
*/
# define BASE_8_LEN 27
# define BASE_10_LEN 25
# define BASE_16_LEN 23

# define FLAGS	"-+ 0#"

# define BASE_OCT	"01234567"
# define BASE_DEC	"0123456789"
# define BASE_HEX_M	"0123456789abcdef"
# define BASE_HEX_C	"0123456789ABCDEF"

# define LEN	"hlLzjt"
# define TYPE	"diufFeEgGxXoscpaAn%%"

# define NULL_STR "(null)"
# define NIL_STR "(nil)"

enum	e_flag
{
	MINUS = (1u << 0),
	PLUS = (1u << 1),
	SPACE = (1u << 2),
	ZERO = (1u << 3),
	HASH = (1u << 4),
	PERCENT = (1u << 5),
	PRECISION = (1u << 6),
	ERROR = (1u << 7),
};

enum	e_len
{
	SHORT_H = (1u << 0),
	LONG_L = (1u << 1),
	LONG_DOUBLE_L = (1u << 2),
	SIZE_T_Z = (1u << 3),
	INTMAX_J = (1u << 4),
	PTRDIFF_T = (1u << 5),
	CHAR_HH = (1u << 6),
	LONGLONG_LL = (1u << 7),
};

enum	e_type
{
	INT_D = (1ul << 0),
	INT_I = (1ul << 1),
	UNSIGNED_U = (1ul << 2),
	DOUBLE_NORMAL_F = (1ul << 3),
	DOUBLE_NORMAL_F_CAPITAL = (1ul << 4),
	DOUBLE_EXPONENT_E = (1ul << 5),
	DOUBLE_EXPONENT_E_CAPITAL = (1ul << 6),
	DOUGLE_G = (1ul << 7),
	DOUBLE_G_CAPITAL = (1ul << 8),
	UNSIGNED_HEX_X = (1ul << 9),
	UNSIGNED_HEX_X_CAPITAL = (1ul << 10),
	UNSIGNED_OCTAL_O = (1ul << 11),
	STRING_S = (1ul << 12),
	CHAR_C = (1ul << 13),
	POINTER_P = (1ul << 14),
	DOUBLE_HEX_A = (1ul << 15),
	DOUBLE_HEX_A_CAPITAL = (1ul << 16),
	NOTHING_N = (1ul << 17),
	PERCENT_PERCENT = (1ul << 18)
};

typedef struct	s_format
{
	unsigned int	flags;
	unsigned int	width;
	unsigned int	precision;
	enum e_len		len;
	enum e_type		type;
	void			*infos;
}				t_format;

/*
** The following functions are only meant to be called by parse_format
** (parse_format.c/h)
*/

int				parse_type(t_format *format, const char *str_format);
int				parse_len(t_format *format, const char *str_format);
int				parse_prec
					(t_format *format, const char *str_format, va_list args);
int				parse_width
					(t_format *format, const char *str_format, va_list args);
int				parse_flags(t_format *format, const char *str_format);

#endif
