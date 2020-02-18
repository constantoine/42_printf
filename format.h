/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:02:11 by crebert           #+#    #+#             */
/*   Updated: 2020/02/18 00:35:15 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H
# include <stddef.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define FLAGS		" 0&-+#"
# define BASE_DEC	"0123456789"
# define BASE_HEX_M	"0123456789abcdef"
# define BASE_HEX_C	"0123456789ABCDEF"

enum	e_flag
{
	MINUS = (1u << 0),
	PLUS = (1u << 1),
	SPACE = (1u << 2),
	ZERO = (1u << 3),
	HASH = (1u << 4),
	PERCENT = (1u << 5),
	ERROR = (1u << 7)
};

enum	e_len
{
	CHAR_HH = (1u << 0),
	SHORT_H = (1u << 1),
	LONGLONG_LL = (1u << 2),
	LONG_L = (1u << 3),
	LONG_DOUBLE_L = (1u << 4),
	SIZE_T_Z = (1u << 5),
	INTMAX_J = (1u << 6),
	PTRDIFF_T = (1u << 7)
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
	DOUBLE_HEX_A = (1ul << 9),
	DOUBLE_HEX_A_CAPITAL = (1ul << 10),
	UNSIGNED_HEX_X = (1ul << 11),
	UNSIGNED_HEX_X_CQPITAL = (1ul << 12),
	UNSIGNED_OCTAL_O = (1ul << 13),
	STRING_S = (1ul << 14),
	CHAR_C = (1ul << 15),
	POINTER_P = (1ul << 16)
};

typedef struct	s_format
{
	unsigned int	flags;
	unsigned int	width;
	unsigned int	precision;
	enum e_len		len;
	enum e_type		type;

}				t_format;

#endif
