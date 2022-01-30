/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:06:41 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/24 21:09:29 by vchevill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_4_5_part2(t_pile *pila, t_pile *pilb)
{
	if (pila->list[0] < pilb->list[pilb->piletop])
	{
		ft_push_pile(pila, pilb, a);
		ft_rotate_pile(pila, pilb, a);
	}
	else if (pila->list[1] < pilb->list[pilb->piletop])
	{
		ft_rotate_reverse_pile(pila, pilb, a);
		ft_push_pile(pila, pilb, a);
		ft_rotate_pile(pila, pilb, a);
		ft_rotate_pile(pila, pilb, a);
	}
	else if (pilb->piletop >= 0 && pila->list[2] < pilb->list[pilb->piletop])
	{
		ft_rotate_pile(pila, pilb, a);
		ft_push_pile(pila, pilb, a);
		ft_rotate_reverse_pile(pila, pilb, a);
	}
	else if (pilb->piletop >= 0)
		ft_push_pile(pila, pilb, a);
}

void	ft_sort_4_5(t_pile *pila, t_pile *pilb)
{
	ft_push_pile(pila, pilb, b);
	ft_push_pile(pila, pilb, b);
	ft_sort_0_3(pila, pilb);
	if (pila->list[0] < pilb->list[pilb->piletop])
	{
		ft_push_pile(pila, pilb, a);
		ft_rotate_pile(pila, pilb, a);
	}
	else if (pila->list[1] < pilb->list[pilb->piletop])
	{
		ft_rotate_reverse_pile(pila, pilb, a);
		ft_push_pile(pila, pilb, a);
		ft_rotate_pile(pila, pilb, a);
		ft_rotate_pile(pila, pilb, a);
	}
	else if (pila->list[2] < pilb->list[pilb->piletop])
	{
		ft_rotate_pile(pila, pilb, a);
		ft_push_pile(pila, pilb, a);
		ft_rotate_reverse_pile(pila, pilb, a);
	}
	else
		ft_push_pile(pila, pilb, a);
	if (pilb->piletop >= 0)
		ft_sort_4_5_part2(pila, pilb);
}
