/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <crebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:35:44 by crebert           #+#    #+#             */
/*   Updated: 2020/02/18 10:37:39 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "libft.h"

char	*ft_itoa(int nb)
{
	int		index;
	int		nbcpy;
	char	num[12];

	nbcpy = nb;
	index = 10;
	num[11] = 0;
	num[10] = '0';
	if (nb == -2147483648)
		num[index--] = '8';
	if (nb == -2147483648)
		nb /= 10;
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		num[index--] = nb % 10 + '0';
		nb /= 10;
	}
	if (nbcpy < 0)
		num[index] = '-';
	else if (nbcpy != 0)
		index++;
	return (ft_strdup(&num[index]));
}
