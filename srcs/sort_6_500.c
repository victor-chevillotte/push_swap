/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6_500.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:06:36 by vchevill          #+#    #+#             */
/*   Updated: 2022/01/30 22:03:35 by vchevill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_sort_6_100(t_pile *pila, t_pile	*pilb, int size_of_pile)
{
	int			mediane;
	int			is_chunk;
	int			i;
	t_extrem	min;
	t_extrem	max;

	is_chunk = 0;
	if (size_of_pile < 100)
		mediane = size_of_pile / 2;
	else
	{
		mediane = size_of_pile / 2;
		is_chunk = 1;
	}
	i = -1;
	while (++i < size_of_pile)
	{
		if (pila->list[pila->piletop] < mediane)
			ft_push_pile(pila, pilb, b);
		else
			ft_rotate_pile(pila, pilb, a);
	}
	while (pilb->piletop > 0)
	{
		i = -1;
		while (++i <= pilb->piletop)
		{
			if (!min.value || pilb->list[i] < min.value)
			{
				min.value = pilb->list[i];
				min.index = i;
			}
			if (!max.value || pilb->list[i] > max.value)
			{
				max.value = pilb->list[i];
				max.index = i;
			}
		}
		if ((min.index < max.index && min.index < mediane) || (max.index < min.index && max.index < mediane))
		{
			i = -1;
			while (++i != min.index && i != max.index)
				ft_rotate_pile(pila, pilb, b);
		}
		else
		{
			i = pilb->piletop;
			while (--i != min.index && i != max.index)
				ft_rotate_reverse_pile(pila, pilb, b);
		}
		ft_push_pile(pila, pilb, a);
	}
}
