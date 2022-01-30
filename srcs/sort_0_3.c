/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_0_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:55:10 by vchevill          #+#    #+#             */
/*   Updated: 2022/01/30 15:57:22 by vchevill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3_part2(t_pile *pila, t_pile	*pilb)
{
	if ((pila->list[2] < pila->list[1])
		&& (pila->list[1] > pila->list[0]) 
		&& (pila->list[2] > pila->list[0]))
		ft_rotate_reverse_pile(pila, pilb, a);
}

void	ft_sort_3(t_pile *pila, t_pile	*pilb)
{
	if ((pila->list[2] > pila->list[1])
		&& (pila->list[1] < pila->list[0])
		&& (pila->list[2] < pila->list[0]))
		ft_swap_pile(pila, pilb, a);
	else if ((pila->list[2] > pila->list[1])
		&& (pila->list[1] > pila->list[0])
		&& (pila->list[2] > pila->list[0]))
	{
		ft_swap_pile(pila, pilb, a);
		ft_rotate_reverse_pile(pila, pilb, a);
	}
	else if ((pila->list[2] > pila->list[1])
		&& (pila->list[1] < pila->list[0]) 
		&& (pila->list[2] > pila->list[0]))
		ft_rotate_pile(pila, pilb, a);
	else if ((pila->list[2] < pila->list[1])
		&& (pila->list[1] > pila->list[0])
		&& (pila->list[2] < pila->list[0]))
	{
		ft_swap_pile(pila, pilb, a);
		ft_rotate_pile(pila, pilb, a);
	}
	ft_sort_3_part2(pila, pilb);
}

void	ft_sort_0_3(t_pile	*pila, t_pile	*pilb)
{
	if (pila->piletop == 0)
		return ;
	if ((pila->piletop == 1) && (pila->list[1] < pila->list[0]))
		return ;
	else if (pila->piletop == 1)
		ft_swap_pile(pila, pilb, a);
	else
		ft_sort_3(pila, pilb);
}
