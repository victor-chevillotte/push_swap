/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6_500.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:06:36 by vchevill          #+#    #+#             */
/*   Updated: 2022/02/04 11:11:19 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min_max(t_extrem	*min, t_extrem	*max, t_pile	*pilb)
{
	int	i;

	i = -1;
	min->value = -1;
	max->value = -1;
	while (++i <= pilb->piletop)
	{
		if (pilb->list[i] <= min->value || min->value == -1)
		{
			min->value = pilb->list[i];
			min->index = i;
		}
		if (pilb->list[i] >= max->value)
		{
			max->value = pilb->list[i];
			max->index = i;
		}
	}
	return (pilb->piletop / 2);
}

int static	ft_continue_pb(t_pile *pila, int chunk, int med_2, int size_of_pile)
{
	int	i;

	i = -1;
	while (pila->piletop >= ++i)
	{
		if ((pila->list[i] <= (med_2)
				+ (size_of_pile / chunk))
			&& (pila->list[i] >= med_2))
			return (1);
	}
	return (0);
}

void static	ft_put_in_b(t_pile *pila, t_pile	*pilb, int chunk_num, int chunk)
{
	int	mediane ;
	int	med_2 ;
	int	size_of_pile;

	mediane = pila->piletop / chunk;
	med_2 = set_mediane(pila, chunk);
	size_of_pile = pila->piletop;
	while (ft_continue_pb(pila, chunk, (med_2 * chunk_num), size_of_pile) == 1)
	{
		if ((pila->list[pila->piletop] <= (med_2 * chunk_num)
				+ (size_of_pile / chunk))
			&& (pila->list[pila->piletop] >= med_2 * chunk_num))
			ft_push_pile(pila, pilb, b);
		else
			ft_rotate_pile(pila, pilb, a);
	}
	if (chunk_num != 0)
		ft_put_min_to_top(pila, pilb, chunk_num);
}

void	ft_sort_6_500(t_pile *pila, t_pile	*pilb, int size_of_pile)
{
	int	chunk;
	int	chunk_num;

	if (size_of_pile <= 100)
		chunk = 2;
	else
		chunk = 4;
	chunk_num = 0;
	while (chunk_num < chunk)
	{
		ft_put_in_b(pila, pilb, chunk_num, chunk);
		ft_sort_chunk_in_b(pila, pilb);
		chunk_num++;
	}
	ft_put_min_to_top_end(pila, pilb);
}
