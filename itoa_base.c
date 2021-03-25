/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleo <cleo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:45:42 by crebert           #+#    #+#             */
/*   Updated: 2020/03/28 16:18:09 by cleo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
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

static char	*ft_putnbr_base2(uintmax_t nbr, int index, char *num, char *base)
{
	uintmax_t		nbcpy;
	int				base_len;

	base_len = check_base(base);
	nbcpy = nbr;
	while (nbr > 0)
	{
		num[index--] = base[nbr % base_len];
		nbr /= base_len;
	}
	if (nbcpy != 0)
		index++;
	return (&num[index]);
}

char	*ft_itoa_noalloc(uintmax_t nb, char *num, size_t size)
{
	int			index;
	uintmax_t	nbcpy;

	nbcpy = nb;
	index = size - 2;
	num[size - 1] = 0;
	num[index] = '0';
	while (nb > 0 && (num[index--] = nb % 10 + '0'))
		nb /= 10;
	if (nbcpy != 0)
		index++;
	return (&num[index]);
}

char		*ft_itoa_base_pf
	(uintmax_t nbr, char *base, char *dst, t_format *format)
{
	int		base_len;
	uint8_t	len;

	len = *(uint8_t*)(format->infos);
	base_len = check_base(base);
	if (base_len == 0)
		return (NULL);
	dst[len - 1] = 0;
	dst[len - 2] = base[0];
	return (ft_putnbr_base2(nbr, len - 2, dst, base));
}
