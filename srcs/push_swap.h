/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:16:13 by vchevill          #+#    #+#             */
/*   Updated: 2022/02/03 13:00:37 by vchevill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_pile
{
	int			piletop;
	int			*list;
	char		letter;
}				t_pile;

typedef struct s_extrem
{
	int			value;
	int			index;
	int			chosen;
}				t_extrem;

typedef enum e_letter
{
	a,
	b,
	ab
}			t_letter;

/* INIT */
int		ft_init_pushswap(int argc, char **argv, t_pile *pila, t_pile *pilb);
void	ft_match_index(int argc, int *tmp, int *tmpnotsorted, t_pile *pila);
int		ft_sizeof(char **num_tab);
int		ft_findnum(char **num_tab, char *num);
int		ft_isnum(char *num);
int		ft_checkargs(char **num_tab);
int		ft_pushswap_error(t_pile *pila, t_pile *pilb);

/* QUICK_SORT */
void	quick_sort(int *tab, int size);
int		swap_from_left(int *tab, int i, int j);
int		swap_from_right(int *tab, int i, int j);

/* OPERATIONS */
void	ft_swap_pile(t_pile *pila, t_pile *pilb, t_letter letter);
void	ft_rotate_pile(t_pile *pila, t_pile *pilb, t_letter letter);
void	ft_rotate_reverse_pile(t_pile *pila, t_pile *pilb, t_letter letter);
void	ft_push_pile(t_pile *pila, t_pile *pilb, t_letter letter);

/* SORT */
void	ft_sort_0_3(t_pile	*pila, t_pile	*pilb);
void	ft_sort_4_5(t_pile *pila, t_pile *pilb);

/* SORT 6->500*/
void	ft_sort_6_500(t_pile *pila, t_pile	*pilb, int size_of_pile);
void	ft_put_min_to_top_end(t_pile *pila, t_pile	*pilb);
void	ft_put_in_b_last(t_pile *pila, t_pile	*pilb, int size_of_pile);
int		set_mediane(t_pile *pila, int chunk);
void	ft_put_min_to_top(t_pile *pila, t_pile	*pilb, int chunk_num);
void	ft_sort_chunk_in_b(t_pile *pila, t_pile	*pilb);
int		ft_get_min_max(t_extrem	*min, t_extrem	*max, t_pile	*pilb);

/*QUICK SORT */
int		swap_from_right(int *tab, int i, int j);
int		swap_from_left(int *tab, int i, int j);
int		ft_is_sorted(t_pile *pila);
void	ft_printpile(t_pile *pile);

#endif
