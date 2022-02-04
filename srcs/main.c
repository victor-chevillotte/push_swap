/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:06:39 by vchevill          #+#    #+#             */
/*   Updated: 2022/02/04 11:11:32 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_pile *pila)
{
	int	i;

	i = 0;
	while (i < pila->piletop && pila->list[i] > pila->list[i + 1])
		i++;
	if (i == pila->piletop)
		return (1);
	else
		return (0);
}

void static	ft_sort(t_pile *pila, t_pile *pilb)
{
	if (pila->piletop < 3)
		ft_sort_0_3(pila, pilb);
	else if (pila->piletop < 5)
		ft_sort_4_5(pila, pilb);
	else
		ft_sort_6_500(pila, pilb, pila->piletop);
}

int	main(int argc, char **argv)
{
	t_pile	*pila;
	t_pile	*pilb;

	if (argc == 1)
		return (0);
	argc--;
	pila = malloc(sizeof(t_pile));
	if (!pila)
		return (ft_pushswap_error(NULL, NULL));
	pilb = malloc(sizeof(t_pile));
	if (!pilb)
		return (ft_pushswap_error(pila, NULL));
	if (ft_init_pushswap(argc, argv, pila, pilb))
		return (ft_pushswap_error(pila, pilb));
	if (!ft_is_sorted(pila))
		ft_sort(pila, pilb);
	free(pila->list);
	free(pilb->list);
	free(pila);
	free(pilb);
	return (0);
}
