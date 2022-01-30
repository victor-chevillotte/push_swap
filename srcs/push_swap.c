/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:06:39 by vchevill          #+#    #+#             */
/*   Updated: 2022/01/30 19:03:30 by vchevill         ###   ########.fr       */
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

int	ft_is_sorted(t_pile *pila)
{
	int	i;

	i = 0;
	while (pila->list[i] > pila->list[i + 1] && i < pila->piletop)
		i++;
	if (i == pila->piletop)
		return (1);
	else
		return (0);
}

int main(int argc, char **argv)
{
	t_pile	*pila;
	t_pile	*pilb;

	if (argc == 1)
		return (0);
	argc--;
	pila = malloc(sizeof(t_pile));
	if (!pila)
		return (ft_pushswap_error());
	pilb = malloc(sizeof(t_pile));
	if (!pilb)
		return (ft_pushswap_error());
	if (ft_init_pushswap(argc, argv, pila, pilb))
		return (ft_pushswap_error());
	/*ft_putstr_fd("<---pile A-->\n", 1);
	ft_printpile(pila);
	ft_putstr_fd("<---pile B-->\n", 1);
	ft_printpile(pilb);*/
	if (!ft_is_sorted(pila))
	{
		if (pila->piletop < 3)
			ft_sort_0_3(pila, pilb);
		else if (pila->piletop < 5)
			ft_sort_4_5(pila, pilb);
	}
	
	/*ft_putstr_fd("<---pile A-->\n", 1);
	ft_printpile(pila);
	ft_putstr_fd("<---pile B-->\n", 1);
	ft_printpile(pilb);*/
	free(pila->list);
	free(pilb->list);
	free(pila);
	free(pilb);
	return (0);
}
