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

static char	*ft_putnbr_base2(unsigned int nbr, int index, char *num, char *base)
{
	unsigned int	nbcpy;
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

char		*ft_itoa_base_pf
	(unsigned int nbr, char *base, char *dst, t_format *format)
{
	int		base_len;
	uint8_t	len;

	len = *(uint8_t*)(format->infos);
	base_len = check_base(base);
	if (base_len == 0)
		return (NULL);
	if (format->precision == 0 && nbr == 0)
		dst[0] = 0;
	if (format->precision == 0 && nbr == 0)
		return (dst);
	dst[len] = 0;
	dst[len - 1] = base[0];
	return (ft_putnbr_base2(nbr, len - 1, dst, base));
}
