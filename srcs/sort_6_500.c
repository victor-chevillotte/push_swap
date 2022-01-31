/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6_500.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 20:06:36 by vchevill          #+#    #+#             */
/*   Updated: 2022/01/31 22:31:44 by vchevill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int static ft_get_min_max(t_extrem	*min, t_extrem	*max, t_pile	*pilb)
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

void	ft_sort_chunk_in_b(t_pile *pila, t_pile	*pilb)
{
	int 		med_b;
	t_extrem	min;
	t_extrem	max;
	
	while (pilb->piletop >= 0)
	{
		med_b = ft_get_min_max(&min, &max, pilb);
		
		/*ft_putstr_fd("<---pile B-->\n", 2);
		ft_printpile(pilb);
		dprintf(2, "max index=%i, min index=%i, med_b =%i \n", max.index, min.index, med_b );*/
		
		if (min.index <= med_b && max.index <= med_b )
		{
			if (min.index < max.index)
			{
				min.chosen = 1;
				//dprintf(2, "bas min 1\n");
				while (--min.index >= 0)
					ft_rotate_reverse_pile(pila, pilb, b);
			}
			else
			{
				min.chosen = 0;
				//dprintf(2, "bas max 1\n");
				while (--max.index >= 0)
					ft_rotate_reverse_pile(pila, pilb, b);
			}
			ft_rotate_reverse_pile(pila, pilb, b);
		}
		else if ((min.index > med_b  && pilb->piletop - min.index <= max.index) || (max.index >= med_b  && pilb->piletop - max.index <= min.index))
		{
			if (min.index > max.index)
			{
				min.chosen = 1;
				//dprintf(2, "haut min\n");
				while (++min.index <= pilb->piletop)
					ft_rotate_pile(pila, pilb, b);
			}
			else
			{
				min.chosen = 0;
				//dprintf(2, "haut max\n");
				while (++max.index <= pilb->piletop)
					ft_rotate_pile(pila, pilb, b);
			}
		}
		else if (min.index > med_b  && max.index > med_b )
		{
			if (min.index > max.index)
			{
				min.chosen = 1;
				//dprintf(2, "haut min 1\n");
				while (++min.index <= pilb->piletop)
					ft_rotate_pile(pila, pilb, b);
			}
			else
			{
				min.chosen = 0;
				//dprintf(2, "haut max 1\n");
				while (++max.index <= pilb->piletop)
					ft_rotate_pile(pila, pilb, b);
			}
		}
		else if ((min.index <= med_b  && min.index < pilb->piletop - max.index) || (max.index <= med_b  && max.index < pilb->piletop - min.index))
		{
		if (min.index < max.index)
			{
				min.chosen = 1;
				//dprintf(2, "bas min\n");
				while (--min.index >= 0)
					ft_rotate_reverse_pile(pila, pilb, b);
			}
			else
			{
				min.chosen = 0;
				//dprintf(2, "bas max\n");
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

void ft_put_in_b_last(t_pile *pila, t_pile	*pilb, int size_of_pile)
{
	int mediane ;

	mediane = size_of_pile / 2;
	
	while (pila->piletop >= mediane)
	{
		if (pila->list[pila->piletop] >= mediane)
			ft_push_pile(pila, pilb, b);
		else
			ft_rotate_pile(pila, pilb, a);
	}
}

int set_mediane(t_pile *pila, int chunk)
{
	if (pila->piletop % 2 == 0)
		return (pila->piletop / chunk);
	else
		return ((pila->piletop + 1)/ chunk );
}

void ft_put_min_to_top(t_pile *pila, t_pile	*pilb, int chunk_num)
{
	int i;
	t_extrem min;
	
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
	//		dprintf(2, "%i", min.index);
	if (min.index > pila->piletop / 2)
	{
		while (min.index != pila->piletop)
		{
			ft_rotate_pile(pila, pilb, a);
			min.index++;
		}
	}
	
	else if (min.index <= pila->piletop / 2)
	{
		while (min.index >= 0)
		{
			ft_rotate_reverse_pile(pila, pilb, a);
			min.index--;
		}
	}
		
					
		//							dprintf(2, "%i", min.index);
			
}

void ft_put_in_b(t_pile *pila, t_pile	*pilb, int chunk_num, int chunk)
{
	int mediane ;
	int med_2 ;
	int size_of_pile;
	
	mediane = pila->piletop / chunk;
	med_2 = set_mediane(pila, chunk);
	
	size_of_pile = pila->piletop;
	
	/*ft_putstr_fd("<---pile A-->\n", 2);
	ft_printpile(pila);
		dprintf(2,"size_of_pile=%i mediane=%i chunk_num=%i chunk =%i med_2=%i size_of_pilecc - size_of_pile /chunk =%i,size_of_pile - size_of_pile / chunk=%i",size_of_pile, mediane, chunk_num, chunk, med_2, size_of_pile - size_of_pile / chunk, med_2);
	*///exit(0);
	while (pila->piletop >= size_of_pile - size_of_pile / chunk)
	{
		if ((pila->list[pila->piletop] <= (med_2 * chunk_num) + (size_of_pile / chunk)) && (pila->list[pila->piletop] >= med_2 * chunk_num))
			ft_push_pile(pila, pilb, b);
		else
			ft_rotate_pile(pila, pilb, a);
	}
	if (chunk_num != 0)
		ft_put_min_to_top(pila, pilb, chunk_num);
	//exit(0);
	/*ft_putstr_fd("<---pile A-->\n", 2);
	ft_printpile(pila);
		ft_putstr_fd("<---pile B-->\n", 2);
	ft_printpile(pilb);*/
	
}
			
void ft_put_min_to_top_end(t_pile *pila, t_pile	*pilb)
{
	int i;
	t_extrem min;
	
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

void	ft_sort_6_100(t_pile *pila, t_pile	*pilb, int size_of_pile)
{
	int chunk;
	int chunk_num;
	
	if (size_of_pile <= 100)
		chunk = 2;
	else
		chunk = 4;
	chunk_num = 0;
	while (chunk_num < chunk)
	{
		ft_put_in_b(pila, pilb, chunk_num, chunk);
		ft_sort_chunk_in_b(pila, pilb);
		//	if (chunk_num != chunk - 1)
		//ft_put_min_to_top(pila, pilb);
		/*ft_putstr_fd("<---pile A-->\n", 2);
		ft_printpile(pila);*/
		chunk_num++;
	}
	//ft_put_min_to_top_end(pila, pilb);
	
	ft_putstr_fd("<---pile A-->\n", 2);
	ft_printpile(pila);
}
