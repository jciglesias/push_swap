/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:38:22 by jiglesia          #+#    #+#             */
/*   Updated: 2021/11/21 16:09:42 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PUSH_SWAP_H
# define	PUSH_SWAP_H

# include <unistd.h>
# include "libft.h"
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct		s_pivot
{
	int				min;
	int				max;
}					t_pivot;

void	q_sort(t_listi **a, t_listi **b, int isa, t_pivot v);

/*
** moves
*/

int		ft_sab(t_listi **a, char *cout);
int		ft_rab(t_listi **a, char *cout);
int		ft_pab(t_listi **a, t_listi **b, char *cout);
int		ft_rrab(t_listi **a, char *cout);
void	pop(t_listi **head);
void	push(t_listi **head, int val);

int	valid_input(int i, char **num);

/*
** list
*/

void	free_listi(t_listi **a);
int		ft_fillist(t_listi **l, char **num, int size);
int		ordered(t_listi *head, int ascendant);
int		count_between(t_listi *p, int min, int max);
int		median_between(t_listi *p, int min, int max);
int		find_median(t_listi *head, int k);
int		islarger(char *nb);
int		closest_num(t_listi *p, int num);
int		pile_max(t_listi *p);
int		pile_min(t_listi *p);
int		pile_len(t_listi *head);
t_listi	*end_node(t_listi *head);
void	pass_pile(t_listi **p1, t_listi **p2, int side);
void	free_pile(t_listi **p);
int		are_left(t_listi *p, int pivot, int ispa, t_pivot v);
int		last_between(t_listi *p, int min, int max);

/*
** q_sort
*/

int		move_pivot(t_listi **a, t_listi **b, int isa, t_pivot v);
void	quick_return(t_listi **p, t_pivot v);
void	pass_limits(t_listi **a, t_listi **b, int i);
void	insert_listi(t_listi **a, t_listi **b);
void	mini_solve(t_listi **pa, t_listi **pb);
void	ft_sort(t_listi **a, t_listi **b, int isa, t_pivot v);

#endif
