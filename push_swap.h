/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vchevill <vchevill@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 15:16:13 by vchevill          #+#    #+#             */
/*   Updated: 2021/11/23 14:07:03 by vchevill         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_pile
{
	int			piletop;
	int			*list;
}				t_pile;

int	ft_findnum(char **numlist, char *num, int piletop);
int	ft_isnum(char *num);
int	ft_checkargs(int argc, char **argv);

#endif
