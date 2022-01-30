/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6_500.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:06:36 by vchevill          #+#    #+#             */
/*   Updated: 2022/01/31 00:09:11 by vchevill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_sort_6_100(t_pile *pila, t_pile	*pilb, int size_of_pile)
{
	int			mediane;
	int			is_chunk;
	int			i;
	int 		med_b;
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
	while (++i <= size_of_pile)
	{
		if (pila->list[pila->piletop] <= mediane)
			ft_push_pile(pila, pilb, b);
		else
			ft_rotate_pile(pila, pilb, a);
	}
	while (pilb->piletop >= 0)
	{
		i = -1;
		min.value = pilb->piletop + 1;
		max.value = -1;
		while (++i <= pilb->piletop)
		{
			if (pilb->list[i] <= min.value)
			{
				min.value = pilb->list[i];
				min.index = i;
			}
			if (pilb->list[i] >= max.value)
			{
				max.value = pilb->list[i];
				max.index = i;
			}
		}
		if (pilb->piletop % 2 == 0)
			med_b = pilb->piletop / 2;
		else
			med_b = pilb->piletop / 2 + 1;
		/*ft_putstr_fd("<---pile B-->\n", 1);
		ft_printpile(pilb);
		dprintf(1, "max index=%i, min index=%i, med_b =%i \n", max.index, min.index, med_b );*/
		if (min.index <= med_b && max.index <= med_b )
		{
			if (min.index < max.index)
			{
				min.chosen = 1;
				dprintf(2, "bas min 1\n");
				while (--min.index >= 0)
					ft_rotate_reverse_pile(pila, pilb, b);
			}
			else
			{
				min.chosen = 0;
				dprintf(2, "bas max 1\n");
				while (--max.index >= 0)
					ft_rotate_reverse_pile(pila, pilb, b);
			}
			ft_rotate_reverse_pile(pila, pilb, b);
			//dprintf(1, "%i \n", min.index);
		}
		else if ((min.index > med_b  && min.index - med_b > max.index)|| (max.index >= med_b  && max.index - med_b <= min.index))
		{
			if (min.index > max.index)
			{
				min.chosen = 1;
				dprintf(2, "haut min\n");
				while (++min.index < pilb->piletop)
					ft_rotate_pile(pila, pilb, b);
			}
			else
			{
				min.chosen = 0;
				dprintf(2, "haut max\n");
				while (++max.index < pilb->piletop)
					ft_rotate_pile(pila, pilb, b);
			}
		}
		else if (min.index > med_b  && max.index > med_b )
		{
			if (min.index > max.index)
			{
				min.chosen = 1;
				dprintf(2, "haut min 1\n");
				while (++min.index < pilb->piletop)
					ft_rotate_pile(pila, pilb, b);
			}
			else
			{
				min.chosen = 0;
				dprintf(2, "haut max 1\n");
				while (++max.index < pilb->piletop)
					ft_rotate_pile(pila, pilb, b);
			}
		}
		else if ((min.index <= med_b  && min.index <= max.index - med_b) || (max.index <= med_b  && max.index <= min.index - med_b))
		{
		if (min.index < max.index)
			{
				min.chosen = 1;
				dprintf(2, "bas min\n");
				while (--min.index >= 0)
					ft_rotate_reverse_pile(pila, pilb, b);
			}
			else
			{
				min.chosen = 0;
				dprintf(2, "bas max\n");
				while (--max.index >= 0)
					ft_rotate_reverse_pile(pila, pilb, b);
			}
			ft_rotate_reverse_pile(pila, pilb, b);
		}
		ft_push_pile(pila, pilb, a);
		if (min.chosen == 1)
			ft_rotate_pile(pila, pilb, a);
	}
}
