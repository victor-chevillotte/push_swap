/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_500.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:06:36 by vchevill          #+#    #+#             */
/*   Updated: 2022/01/30 20:06:45 by vchevill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_sort_6_100(t_pile *pila, t_pile	*pilb)
{
	//int	hold_first;
	//int	hold_second;
	int	i;

	i = pila->piletop + 1;
	i = pilb->piletop + 1;
	/*while (--i >= 0)
	{
		if (pila->list[i] < 19)
		{
			hold_first = i;
			break ;
		}
	}
	i = -1;
	while (++i >= 0)
	{
		if (pila->list[i] < 19)
		{
			hold_second = i;
			break ;
		}
	}
	i = -1;
	if (pila->piletop - hold_first <= hold_second)
		while (++i < pila->piletop - hold_first)
			ft_rotate_pile(pila, pilb, a);
	else
		while (++i < hold_second)
			ft_rotate_reverse_pile(pila, pilb, a);
	i = -1;
	ft_push_pile(pila, pilb, a);*/
	//while (++i < pilb->piletop)
	//	if
}