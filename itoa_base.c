/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 11:45:42 by crebert           #+#    #+#             */
/*   Updated: 2020/03/10 12:18:39 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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

static char	*ft_putnbr_base2(int nbr, int index, char *num, char *base)
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
		num[index] = base[nbr % base_len];
		nbr /= base_len;
		index--;
	}
	if (nbcpy < 0)
		num[index] = '-';
	else if (nbcpy != 0)
		index++;
	return (&num[index]);
}

char		*ft_itoa_base_pf(int nbr, char *base, char *dst, int len_dst)
{
	int		base_len;

	base_len = check_base(base);
	if (base_len == 0)
		return (NULL);
	dst[len_dst] = 0;
	dst[len_dst - 1] = base[0];
	return (ft_putnbr_base2(nbr, len_dst - 1, dst, base));
}
