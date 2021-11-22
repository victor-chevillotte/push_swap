/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:10:09 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/08 10:28:17 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*lst;

	lst = *alst;
	if (!(*alst))
	{
		(*alst) = new ;
		return ;
	}
	while ((*alst)->next)
		(*alst) = (*alst)->next;
	(*alst)->next = new;
	*alst = lst;
}
