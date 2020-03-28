/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 15:11:19 by cleo              #+#    #+#             */
/*   Updated: 2020/03/28 16:17:46 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
#include "format.h"

static int	check_base(char *str)
{
	int		index;
	int		index_char;
	char	tmp;

	index = -1;
	while (str[++index])
	{
		tmp = str[index];
		index_char = -1;
		while (str[++index_char])
			if (str[index_char] == tmp && index != index_char)
				return (0);
		if (str[index] == '%')
			return (0);
		if (str[index] < 32 || str[index] > 126)
			return (0);
		if (str[index] >= 42 && str[index] <= 47)
			return (0);
	}
	if (index < 2)
		return (0);
	return (index);
}

static char	*ft_putnbr_base_plus(int nbr, int index, char *num, char *base)
{
	int				nbcpy;
	int				base_len;
	unsigned	int	nb_tmp;

	base_len = check_base(base);
	nbcpy = nbr;
	if (nbr == -2147483648)
	{
		nb_tmp = nbr * -1;
		num[index--] = base[nb_tmp % base_len];
		nbr /= base_len;
	}
	nbr = nbr < 0 ? nbr * -1 : nbr;
	while (nbr > 0)
	{
		num[index--] = base[nbr % base_len];
		nbr /= base_len;
	}
	if (nbcpy < 0)
		num[index] = '-';
	else if (nbcpy != 0)
		num[index] = '+';
	else
		num[--index] = '+';
	return (&num[index]);
}

static char	*ft_putnbr_base_space(int nbr, int index, char *num, char *base)
{
	int				nbcpy;
	int				base_len;
	unsigned	int	nb_tmp;

	base_len = check_base(base);
	nbcpy = nbr;
	if (nbr == -2147483648)
	{
		nb_tmp = nbr * -1;
		num[index--] = base[nb_tmp % base_len];
		nbr /= base_len;
	}
	nbr = nbr < 0 ? nbr * -1 : nbr;
	while (nbr > 0)
	{
		num[index--] = base[nbr % base_len];
		nbr /= base_len;
	}
	if (nbcpy < 0)
		num[index] = '-';
	else if (nbcpy != 0)
		num[index] = ' ';
	else
		num[--index] = ' ';
	return (&num[index]);
}

static char	*ft_putnbr_base_vanilla(int nbr, int index, char *num, char *base)
{
	int				nbcpy;
	int				base_len;
	unsigned	int	nb_tmp;

	base_len = check_base(base);
	nbcpy = nbr;
	if (nbr == -2147483648)
	{
		nb_tmp = nbr * -1;
		num[index--] = base[nb_tmp % base_len];
		nbr /= base_len;
	}
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		num[index--] = base[nbr % base_len];
		nbr /= base_len;
	}
	if (nbcpy < 0)
		num[index] = '-';
	else if (nbcpy != 0)
		index++;
	return (&num[index]);
}

char		*ft_itoa_base_pf_signed
	(int nbr, char *base, char *dst, t_format *format)
{
	int		base_len;
	uint8_t	len;

	len = *(uint8_t*)(format->infos);
	base_len = check_base(base);
	if (base_len == 0)
		return (NULL);
	dst[len] = 0;
	dst[len - 1] = base[0];
	if (format->precision == 0 && nbr == 0)
		dst[0] = 0;
	if (format->precision == 0 && nbr == 0)
		return (dst);
	if (format->flags & PLUS)
		return (ft_putnbr_base_plus(nbr, len - 1, dst, base));
	else if (format->flags & SPACE)
		return (ft_putnbr_base_space(nbr, len - 1, dst, base));
	return (ft_putnbr_base_vanilla(nbr, len - 1, dst, base));
}
