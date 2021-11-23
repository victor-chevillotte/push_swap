/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:06:39 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/23 13:39:14 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap_a(int *pilea, int length)
{
	return (0);
}

void	ft_printpile(int *pile, int length)
{
	int	i;

	i = -1;
	printf("%i",length);
	while (++i < length)
	{
		ft_putnbr_fd(pile[i], 1);
		ft_putchar_fd('\n', 1);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		*pilea;
	int		*pileb;

	i = 0;
	argc--;
	if (ft_checkargs(argc, argv) == 1)
		return (1);
	pilea = ft_calloc(sizeof(int), argc);
	if (!pilea)
		return (1);
	pileb = ft_calloc(sizeof(int), argc);
	if (!pileb)
		return (1);
	while (i < argc)
	{
		pilea[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	ft_printpile(pilea, argc);
	return (0);
}
