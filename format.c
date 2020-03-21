/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 19:21:51 by crebert           #+#    #+#             */
/*   Updated: 2020/03/10 10:23:51 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format.h"
#include <limits.h>

int parse_flags(t_format *format, const char *str_format)
{
    int index;
    size_t flag_pos;

    index = 0;
    format->flags = 0;
    if (str_format[0] == '%')
        format->flags |= PERCENT;
    if (str_format[0] == '%')
        return (1);
    while (str_format[index] &&
           (flag_pos = (size_t)ft_strchr(FLAGS, str_format[index])))
    {
        format->flags |= 1 << (flag_pos - (size_t)FLAGS);
        index++;
    }
    if ((format->flags >> 1) & 1u)
        format->flags &= ~SPACE;
    if ((format->flags >> 0) & 1u)
        format->flags &= ~ZERO;
    return (index);
}

int parse_width(t_format *format, const char *str_format, va_list args)
{
    int index;
    int tmp;

    format->width = 0;
    if ((index = 0) == 0 && str_format[0] == '*')
    {
        if ((tmp = va_arg(args, int)) < 0)
        {
            if (tmp == INT_MIN)
                format->width = INT_MAX;
            else
                format->width = tmp * -1;
            format->flags |= MINUS;
        }
        else
            format->width = tmp;
        index++;
    }
    else
    {
        format->width = ft_atoi(str_format);
        while (ft_strchr(BASE_DEC, str_format[index]) && str_format[index])
            index++;
    }
    return (index);
}

int parse_prec(t_format *format, const char *s, va_list args)
{
    int index;
    int tmp;

    format->precision = UINT_MAX;
    index = 0;
    while (s[index] == '.')
    {
        if ((format->precision = 0) == 0 && s[++index] == '*')
        {
            if ((++index) && (tmp = va_arg(args, int)) < 0)
            {
                if (tmp == INT_MIN)
                    format->precision = INT_MAX;
                else
                    format->precision = tmp * -1;
            }
        }
        else
        {
            format->precision = ft_atoi(&s[index]) > 0 ? ft_atoi(&s[index]) : 0;
            while (ft_strchr(BASE_DEC, s[index]) && s[index])
                index++;
        }
    }
    return (index);
}

int parse_len(t_format *format, const char *str_format)
{
    size_t len;
    int index;

    index = 0;
    if (str_format && str_format[index] == 'h' && str_format[index + 1] == 'h')
    {
        format->len |= CHAR_HH;
        index += 2;
    }
    if (str_format && str_format[index] == 'l' && str_format[index + 1] == 'l')
    {
        format->len |= LONGLONG_LL;
        index += 2;
    }
    if ((len = (size_t)ft_strchr(LEN, str_format[index])))
        format->len |= 1 << (len - (size_t)LEN);
    return (index);
}

int parse_type(t_format *format, const char *str_format)
{
    size_t len;
    int index;

    index = 0;
    if ((len = (size_t)ft_strchr(TYPE, str_format[index++])))
        format->type |= (1 << (len - (size_t)TYPE));
    else
        index = -1;
    return (index);
}
