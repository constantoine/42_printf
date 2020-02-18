/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:19:16 by crebert           #+#    #+#             */
/*   Updated: 2019/11/16 14:37:12 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t					index;
	int						result;
	unsigned	char		tmp_a;
	unsigned	char		tmp_b;

	index = 0;
	result = 0;
	while (index < n)
	{
		tmp_a = (const unsigned char)s1[index];
		tmp_b = (const unsigned char)s2[index];
		result = tmp_a - tmp_b;
		if (result != 0)
			break ;
		if (s1[index] == 0 || s2[index] == 0)
			break ;
		index++;
	}
	return (result);
}
