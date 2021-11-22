/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 10:33:02 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/08 10:48:02 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*start;

	if (!lst || !del)
		return ;
	start = *lst;
	while ((*lst)->next)
	{
		del((*lst)->content);
		tmp = (*lst)->next;
		free (*lst);
		*lst = NULL;
		(*lst) = tmp;
	}
	del((*lst)->content);
	free (*lst);
	*lst = NULL;
}
