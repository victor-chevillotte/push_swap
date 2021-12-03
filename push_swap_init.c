/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:03:02 by vchevill          #+#    #+#             */
/*   Updated: 2021/12/03 12:08:26 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findnum(char **numlist, char *num, int piletop)
{
	int	i;
	int	numberofnum;

	i = 1;
	numberofnum = 0;
	while (i < piletop)
	{
		if (ft_strncmp(numlist[i + 1], num, ft_strlen(num)) == 0)
			numberofnum++;
		i++;
	}
	return (numberofnum);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!ft_isprint(num[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_checkargs(int piletop, char **argv)
{
	int		i;
	char	*itoa;

	i = 1;
	while (argv[i])
	{
		itoa = ft_itoa(ft_atoi(argv[i]));
		if (ft_strncmp(argv[i], itoa, ft_strlen(itoa)) != 0
			|| ft_isnum(argv[i]) != 0 || ft_findnum(argv, argv[i], piletop) > 1)
		{
			free(itoa);
			return (1);
		}
		else
			free(itoa);
		i++;
	}
	return (0);
}

int	ft_init_pushswap(int argc, char **argv, t_pile *pila, t_pile *pilb)
{
	int	i;
	int	*tmp;
	int	*tmpnotsorted;
	int	j;

	i = 0;
	j = 0;
	if (ft_checkargs(argc, argv) == 1)
		return (1);
	tmp = malloc(sizeof(int) * (argc));
	if (!tmp)
		return (1);
	tmpnotsorted = malloc(sizeof(int) * (argc));
	if (!tmpnotsorted)
		return (1);
	pila->piletop = argc - 1;
	pila->letter = 'A';
	pila->list = malloc(sizeof(int) * (pila->piletop + 1));
	if (!(pila->list))
		return (1);
	pilb->piletop = -1;
	pilb->letter = 'B';
	pilb->list = malloc(sizeof(int) * (pila->piletop + 1));
	if (!(pilb->list))
		return (1);
	i = argc - 1;
	while (i >= 0)
	{
		tmp[argc - i - 1] = ft_atoi(argv[i + 1]);
		tmpnotsorted[argc - i - 1] = ft_atoi(argv[i + 1]);
		i--;
	}
	i = pila->piletop + 1;
	while (--i >= 0)//*int non triee
	{
		ft_putnbr_fd(tmpnotsorted[i], 1);
		ft_putchar_fd('\n', 1);
	}
		quick_sort(tmp, argc);

	i = 0;
	while (i < pila->piletop)//*int triee
	{
		ft_putnbr_fd(tmp[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	// jusau"ici c'est ok
	while (i < argc)
	{
		while (j < argc)
		{
			if (tmp[j] == tmpnotsorted[i])// pb ici
				pila->list[i] = j;
			j++;
		}
		i++;
	}	
	free(tmpnotsorted);
	free(tmp);
	return (0);
}
