/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6_500_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:00:11 by vchevill          #+#    #+#             */
/*   Updated: 2022/01/31 23:26:32 by vchevill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_min_to_top_end(t_pile *pila, t_pile	*pilb)
{
	int			i;
	t_extrem	min;

	i = -1;
	min.value = -1 ;
	while (++i <= pila->piletop)
	{
		if (pila->list[i] <= min.value || min.value == -1)
		{
			min.value = pila->list[i];
			min.index = i;
		}
	}
	if (min.index > pila->piletop / 2)
		while (!ft_is_sorted(pila))
			ft_rotate_pile(pila, pilb, a);
	else if (min.index <= pila->piletop / 2)
		while (!ft_is_sorted(pila))
			ft_rotate_reverse_pile(pila, pilb, a);
}

void	ft_put_in_b_last(t_pile *pila, t_pile	*pilb, int size_of_pile)
{
	int	mediane ;

	mediane = size_of_pile / 2;
	while (pila->piletop >= mediane)
	{
		if (pila->list[pila->piletop] >= mediane)
			ft_push_pile(pila, pilb, b);
		else
			ft_rotate_pile(pila, pilb, a);
	}
}

int	set_mediane(t_pile *pila, int chunk)
{
	if (pila->piletop % 2 == 0)
		return (pila->piletop / chunk);
	else
		return ((pila->piletop + 1) / chunk);
}

void static	ft_put_min_to_top_2(t_pile *pila, t_pile *pilb, t_extrem *min)
{
	if (min->index > pila->piletop / 2)
	{
		while (min->index != pila->piletop)
		{
			ft_rotate_pile(pila, pilb, a);
			min->index++;
		}
	}
	else if (min->index <= pila->piletop / 2)
	{
		while (min->index >= 0)
		{
			ft_rotate_reverse_pile(pila, pilb, a);
			min->index--;
		}
	}
}

void	ft_put_min_to_top(t_pile *pila, t_pile	*pilb, int chunk_num)
{
	int			i;
	t_extrem	min;

	chunk_num = 0;
	i = -1;
	min.value = -1;
	while (++i <= pila->piletop)
	{
		if (pila->list[i] < min.value || min.value == -1)
		{
			min.value = pila->list[i];
			min.index = i;
		}
	}
	ft_put_min_to_top_2(pila, pilb, &min);
}
