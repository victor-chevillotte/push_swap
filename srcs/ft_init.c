/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:03:02 by vchevill          #+#    #+#             */
/*   Updated: 2022/02/03 13:04:21 by vchevill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_init_3(int argc, char **tab, t_pile *pila)
{
	int		*tmp;
	int		*tmpnotsorted;
	int		i;

	i = argc - 1;
	tmpnotsorted = malloc(sizeof(int) * (argc));
	if (!tmpnotsorted)
		return (1);
	tmp = malloc(sizeof(int) * (argc));
	if (!tmp)
		return (1);
	while (i >= 0)
	{
		tmp[argc - i - 1] = ft_atoi(tab[i]);
		tmpnotsorted[argc - i - 1] = ft_atoi(tab[i]);
		i--;
	}
	quick_sort(tmp, argc);
	ft_match_index(argc, tmp, tmpnotsorted, pila);
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free (tab);
	return (0);
}

int	ft_init_2(int argc, char **tab, t_pile *pila, t_pile *pilb)
{
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
	if (ft_init_3(argc, tab, pila) == 1)
		return (1);
	return (0);
}

int static	ft_join(char *tmp, char *argv_s)
{
	if (argv_s[0] != '\0')
	{
		tmp = ft_strjoin_free_s1(tmp, argv_s);
		tmp = ft_strjoin_free_s1(tmp, " ");
		argv_s = ft_strtrim(argv_s, " ");
		if (!tmp || !argv_s
			|| ft_strncmp(argv_s, "", ft_strlen(argv_s) == 0))
		{
			if (tmp)
				free(tmp);
			return (1);
		}
	}
	return (0);
}

int	ft_init_pushswap(int argc, char **argv, t_pile *pila, t_pile *pilb)
{
	int		i;
	char	**tab;
	char	*tmp;
	int		j;

	i = 0;
	j = 0;
	tmp = NULL;
	while (++i <= argc)
		if (ft_join(tmp, argv[i]) == 1)
			return (1);
	tab = ft_split(tmp, ' ');
	free(tmp);
	if (ft_checkargs(tab) == 1
		|| ft_init_2(ft_sizeof(tab), tab, pila, pilb) == 1)
	{
		i = -1;
		while (tab[++i])
			free(tab[i]);
		free (tab);
		return (1);
	}
	return (0);
}
