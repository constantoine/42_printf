/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 13:13:31 by crebert           #+#    #+#             */
/*   Updated: 2019/11/16 13:49:33 by crebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list	*start;

	if (!alst)
	{
		alst = &new;
		return ;
	}
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	if (!new)
		return ;
	start = *alst;
	new->next = start;
	*alst = new;
}
