/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:16:13 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/24 21:09:48 by vchevill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_pile
{
	int			piletop;
	int			*list;
	char		letter;
}				t_pile;

typedef enum e_letter
{
	a,
	b,
	ab
}			t_letter;

int		ft_findnum(char **numlist, char *num, int piletop);
int		ft_isnum(char *num);
int		ft_checkargs(int argc, char **argv);
void	ft_printpile(t_pile *pile);
int		ft_pushswap_error(void);
int		ft_init_pushswap(int argc, char **argv, t_pile *pila, t_pile *pilb);
void	ft_swap_pile(t_pile *pila, t_pile *pilb, t_letter letter);
void	ft_swap_pile_f(t_pile *pile);
void	ft_rotate_pile(t_pile *pila, t_pile *pilb, t_letter letter);
void	ft_rotate_pile_f(t_pile *pile);
void	ft_rotate_reverse_pile(t_pile *pila, t_pile *pilb, t_letter letter);
void	ft_rotate_reverse_pile_f(t_pile *pile);
void	ft_push_pile_f(t_pile *pile_rem, t_pile *pile_add);
void	ft_push_pile(t_pile *pila, t_pile *pilb, t_letter letter);
void	ft_sort_3_part2(t_pile *pila, t_pile	*pilb);
void	ft_sort_3(t_pile *pila, t_pile	*pilb);
void	ft_sort_0_3(t_pile	*pila, t_pile	*pilb);
void	ft_sort_4_5(t_pile *pila, t_pile *pilb);
void	ft_sort_4_5_part2(t_pile *pila, t_pile *pilb);

#endif
