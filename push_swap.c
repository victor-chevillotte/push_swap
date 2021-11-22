/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:06:39 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/22 17:27:18 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findnum(char **numlist, char *num, int length)
{
	int	i;
	int	numberofnum;

	i = 0;
	numberofnum = 0;
	while (i < length)
	{
		if (ft_strcmp(numlist[i], num) == 0)
			numberofnum++;
		i++;
	}
	return (numberofnum);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] != ft_itoa(ft_atoi(argv[i])) || !ft_isnum(argv[i])
			|| ft_findnum(argv, argv[i], argc) > 1) // check le int overflow || check au'il y ai que des nombres || check au'il n'y ai pas de doublons
		{
			ft_putstr("Error\n");
			return (1);
		}
		i++;
	}
	return(0);
}
