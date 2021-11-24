/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:06:39 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/24 10:24:31 by vchevill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_pile(t_pile *pile_rem, t_pile *pile_add)
{
	int	num_to_swap;

	if (pile_rem->piletop < 1)
		return ;
	num_to_swap = pile_rem->list[pile_rem->piletop];
	pile_rem->piletop--;
	pile_add->piletop++;
	pile_add->list[pile_add->piletop] = num_to_swap;
}

void	ft_printpile(t_pile *pile)
{
	int	i;

	i = -1;
	while (++i <= pile->piletop)
	{
		ft_putnbr_fd(pile->list[i], 1);
		ft_putchar_fd('\n', 1);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_pile	*pilea;
	t_pile	*pileb;

	i = 0;
	argc--;
	if (ft_checkargs(argc, argv) == 1)
		return (1);
	pilea = malloc(sizeof(t_pile));
	if (!pilea)
		return (1);
	pilea->piletop = argc - 1;
	pilea->list = malloc(sizeof(int) * (pilea->piletop + 1));
	if (!(pilea->list))
		return (1);
	pileb = malloc(sizeof(t_pile));
	if (!pileb)
		return (1);
	pileb->piletop = -1;
	pileb->list = malloc(pilea->piletop + 1);
	if (!(pileb->list))
		return (1);
	while (i < argc)
	{
		pilea->list[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	ft_printpile(pilea);
	/*ft_rotate_reverse_pile(pilea);
	ft_putstr_fd("<---rotate a-->\n", 1);
	ft_printpile(pilea);
	ft_swap_pile(pileb);
	ft_putstr_fd("<---swap b-->\n", 1);
	ft_printpile(pilea);
	ft_swap_pile(pilea);
	ft_swap_pile(pileb);
	ft_putstr_fd("<---swap a et swap b-->\n", 1);
	ft_printpile(pilea);
	ft_printpile(pileb);*/
	ft_putstr_fd("<---pushB-->\n", 1);
	ft_push_pile(pilea, pileb);
	ft_putstr_fd("<---pile A-->\n", 1);
	ft_printpile(pilea);
	ft_putstr_fd("<---pile B-->\n", 1);
	ft_printpile(pileb);
	ft_putstr_fd("<---pushB-->\n", 1);
	ft_push_pile(pilea, pileb);
	ft_putstr_fd("<---pile A-->\n", 1);
	ft_printpile(pilea);
	ft_putstr_fd("<---pile B-->\n", 1);
	ft_printpile(pileb);
	ft_putstr_fd("<---pushA-->\n", 1);
	ft_push_pile(pileb, pilea);
	ft_putstr_fd("<---pile A-->\n", 1);
	ft_printpile(pilea);
	ft_putstr_fd("<---pile B-->\n", 1);
	ft_printpile(pileb);
	return (0);
}
