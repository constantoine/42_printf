/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 16:42:14 by crebert           #+#    #+#             */
/*   Updated: 2020/03/09 23:21:54 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H


# include <stddef.h>
# include "ft_printf.h"

int		buffer_flush(t_printf *pf);
int		send_to_buffer(t_printf *pf, const char *str, size_t len);

# endif
