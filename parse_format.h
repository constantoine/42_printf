/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:12:58 by crebert           #+#    #+#             */
/*   Updated: 2020/03/09 23:47:29 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_FORMAT_H
# define PARSE_FORMAT_H

# include "format.h"

int	parse_format(t_format *format, const char *str_format, va_list args);

#endif
