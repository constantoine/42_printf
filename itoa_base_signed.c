/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 15:11:19 by cleo              #+#    #+#             */
/*   Updated: 2020/05/08 10:46:47 by cleo             ###   ########.fr       */
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

static char	*ft_putnbr_base(int nbr, int index, char *num, char *base)
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
	if (nbcpy != 0)
		index++;
	return (&num[index]);
}

size_t		get_uint_size(unsigned int num) {
	size_t	size;

	size = 1;
	while ((num /= 10))
		size++;
	return (size);
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
	return (ft_putnbr_base(nbr, len - 1, dst, base));
}
