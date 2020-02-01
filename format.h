/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:02:11 by crebert           #+#    #+#             */
/*   Updated: 2020/02/01 19:24:24 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H
# include <stddef.h>

enum	e_flag
{
	MINUS = (1u << 0),
	PLUS = (1u << 1),
	SPACE = (1u << 2),
	ZERO = (1u << 3),
	APOSTROPHE = (1u << 4),
	HASH = (1u << 5)
};

enum	e_len
{
	CHAR_HH,
	SHORT_H,
	LONGLONG_LL,
	LONG_L,
	LONG_DOUBLE_L,
	SIZE_T_Z,
	INTMAX_J,
	PTRDIFF_T
};

enum	e_type
{
	INT_D,
	INT_I,
	UNSIGNED_U,
	DOUBLE_NORMAL_F,
	DOUBLE_NORMAL_F_CAPITAL,
	DOUBLE_EXPONENT_E,
	DOUBLE_EXPONENT_E_CAPITAL,
	DOUGLE_G,
	DOUBLE_G_CAPITAL,
	DOUBLE_HEX_A,
	DOUBLE_HEX_A_CAPITAL,
	UNSIGNED_HEX_X,
	UNSIGNED_HEX_X_CQPITAL,
	UNSIGNED_OCTAL_O,
	STRING_S,
	CHAR_C,
	POINTER_P
};

/*
** Flqgs
** df
*/
typedef struct	s_format
{
	unsigned int	flags;
	unsigned int	width;
	unsigned int	precision;
	enum e_len		len;
	enum e_type		type;

}				t_format;

#endif
