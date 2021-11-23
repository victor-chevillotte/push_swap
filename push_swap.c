/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:06:39 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/23 16:20:20 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_pile(t_pile *pile)
{
	int	tmp;

	if (pile->piletop < 2)
		return ;
	tmp = pile->list[0];
	pile->list[0] = pile->list[1];
	pile->list[1] = tmp;
}

void	ft_rotate_pile(t_pile *pile)
{
	int	tmp;
	int	i;

	if (pile->piletop < 1)
		return ;
	tmp = pile->list[0];
	i = -1;
	while (++i < pile->piletop)
		pile->list[i] = pile->list[i + 1];
	pile->list[i] = tmp;
}

void	ft_rotate_reverse_pile(t_pile *pile)
{
	int	tmp;
	int	i;

	if (pile->piletop < 1)
		return ;
	tmp = pile->list[pile->piletop];
	i = pile->piletop + 1;
	while (--i > 0)
		pile->list[i] = pile->list[i - 1];
	pile->list[0] = tmp;
}

void	ft_push_pile(t_pile *pile_rem, t_pile *pile_add)
{
	int	*tmp;
	int	i;
	int num_to_swap;

	if (pile_rem->piletop < 1)
		return ;
	pile_rem->piletop--;
	tmp = malloc(sizeof(int) * pile_rem->piletop + 1);
	if (!tmp)
		return ;
	i = -1;
	while (++i <= pile_rem->piletop)
		tmp[i] = pile_rem->list[i];
	dprintf(1,"--%i\n", tmp[i - 1]);
	num_to_swap = pile_rem->list[i];
	pile_rem->list = malloc(sizeof(int) * pile_rem->piletop + 1);
	if (!(pile_rem->list))
		return ;
	i = -1;
	while (++i <= pile_rem->piletop)
		pile_rem->list[i] = tmp[i];
	i = -1;
	free(tmp);
	tmp = malloc(sizeof(int) * pile_rem->piletop + 2);
	if (!tmp)
		return ;
	while (++i <= pile_add->piletop)
		tmp[i] = pile_add->list[i];
	pile_add->piletop++;
	tmp[i] = num_to_swap;
	pile_add->list = malloc(sizeof(int) * pile_add->piletop + 1);
	if (!(pile_add->list))
		return ;
	i = -1;
	while (++i <= pile_add->piletop)
		pile_add->list[i] = tmp[i];
	free(tmp);
}

void ft_printpile(t_pile *pile)
{
	int i;

	i = -1;

	while (++i <= pile->piletop)
	{
		ft_putnbr_fd(pile->list[i], 1);
		ft_putchar_fd('\n', 1);
	}
}

int main(int argc, char **argv)
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
	pileb->list = malloc(0);
	if (!(pileb->list))
		return (1);
	while (i < argc)
	{
		pilea->list[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	ft_printpile(pilea);
	ft_rotate_reverse_pile(pilea);
	ft_putstr_fd("<---rotate a-->\n", 1);
	ft_printpile(pilea);
	ft_swap_pile(pileb);
	ft_putstr_fd("<---swap b-->\n", 1);
	ft_printpile(pilea);
	ft_swap_pile(pilea);
	ft_swap_pile(pileb);
	ft_putstr_fd("<---swap a et swap b-->\n", 1);
	ft_printpile(pilea);
	ft_printpile(pileb);
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
