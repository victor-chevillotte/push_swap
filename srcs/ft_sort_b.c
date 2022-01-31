/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:17:42 by vchevill          #+#    #+#             */
/*   Updated: 2022/01/31 23:24:12 by vchevill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	ft_both_low(t_pile *pila, t_pile *pilb,
	t_extrem *min, t_extrem *max)
{
	if (min->index < max->index)
	{
		min->chosen = 1;
		while (--(min->index) >= 0)
			ft_rotate_reverse_pile(pila, pilb, b);
	}
	else
	{
		min->chosen = 0;
		while (--(max->index) >= 0)
			ft_rotate_reverse_pile(pila, pilb, b);
	}
	ft_rotate_reverse_pile(pila, pilb, b);
}

void static	ft_one_low(t_pile *pila, t_pile *pilb, t_extrem *min, t_extrem *max)
{
	if (min->index > max->index)
	{
		min->chosen = 1;
		while (++(min->index) <= pilb->piletop)
			ft_rotate_pile(pila, pilb, b);
	}
	else
	{
		min->chosen = 0;
		while (++(max->index) <= pilb->piletop)
			ft_rotate_pile(pila, pilb, b);
	}
}

void static	ft_both_high(t_pile *pila, t_pile *pilb,
	t_extrem *min, t_extrem *max)
{
	if (min->index > max->index)
	{
		min->chosen = 1;
		while (++(min->index) <= pilb->piletop)
			ft_rotate_pile(pila, pilb, b);
	}
	else
	{
		min->chosen = 0;
		while (++(max->index) <= pilb->piletop)
			ft_rotate_pile(pila, pilb, b);
	}
}

void static	ft_one_high(t_pile *pila, t_pile *pilb,
	t_extrem *min, t_extrem *max)
{
	if (min->index < max->index)
	{
		min->chosen = 1;
		while (--(min->index) >= 0)
			ft_rotate_reverse_pile(pila, pilb, b);
	}
	else
	{
		min->chosen = 0;
		while (--(max->index) >= 0)
			ft_rotate_reverse_pile(pila, pilb, b);
	}
	ft_rotate_reverse_pile(pila, pilb, b);
}

void	ft_sort_chunk_in_b(t_pile *pila, t_pile	*pilb)
{
	int			med_b;
	t_extrem	min;
	t_extrem	max;

	while (pilb->piletop >= 0)
	{
		med_b = ft_get_min_max(&min, &max, pilb);
		if (min.index <= med_b && max.index <= med_b)
			ft_both_low(pila, pilb, &min, &max);
		else if ((min.index > med_b && pilb->piletop - min.index <= max.index)
			|| (max.index >= med_b && pilb->piletop - max.index <= min.index))
			ft_one_low(pila, pilb, &min, &max);
		else if (min.index > med_b && max.index > med_b)
			ft_both_high(pila, pilb, &min, &max);
		else if ((min.index <= med_b && min.index < pilb->piletop - max.index)
			|| (max.index <= med_b && max.index < pilb->piletop - min.index))
			ft_one_high(pila, pilb, &min, &max);
		ft_push_pile(pila, pilb, a);
		if (min.chosen == 1)
			ft_rotate_pile(pila, pilb, a);
	}
}
