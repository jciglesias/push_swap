/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:07:48 by jiglesia          #+#    #+#             */
/*   Updated: 2021/11/21 17:07:04 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_listi **a, t_listi **b, int isa, t_pivot v)
{
	int	pivot;
	int	tmp;

	if (isa)
		pivot = move_pivot(a, b, 1, v);
	else
		pivot = move_pivot(b, a, 0, v);
	if (isa == 2)
		quick_return(a, v);
	tmp = v.max;
	v.max = pivot;
	q_sort(a, b, 0, v);
	v.max = tmp;
	v.min = pivot;
	q_sort(a, b, 2, v);
}

void	mini_solve(t_listi **pa, t_listi **pb)
{
	int	a;
	int	b;

	if (pile_len(*pa) <= 3)
	{
		a = (*pa)->n;
		b = (*pa)->next->n;
		if (a > b || (a == pile_min(*pa) && b == pile_max(*pa)))
		{
			if (a == pile_max(*pa) && b == pile_min(*pa))
				ft_rab(pa, "ra\n");
			else
				ft_sab(pa, "sa\n");
		}
		else
			ft_rrab(pa, "rra\n");
		if (!ordered(*pa, 1))
			mini_solve(pa, pb);
		return ;
	}
	pass_limits(pa, pb, 0);
	mini_solve(pa, pb);
	insert_listi(pa, pb);
}
