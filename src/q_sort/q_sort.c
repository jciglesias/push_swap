/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:59:26 by jiglesia          #+#    #+#             */
/*   Updated: 2021/11/21 00:07:32 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_pivot(t_listi **a, t_listi **b, int isa, t_pivot v)
{
	int	pivot;

	pivot = median_between(*a, v.min, v.max);
	while (*a && are_left(*a, pivot, isa, v))
	{
		if (isa)
		{
			if (v.min <= (*a)->n && (*a)->n < pivot)
				ft_pab(b, a, "pb\n");
			else
				ft_rab(a, "ra\n");
		}
		else
		{
			if ((*a)->n >= pivot)
				ft_pab(b, a, "pa\n");
			else
				ft_rab(a, "rb\n");
		}
	}
	return (pivot);
}

void	quick_return(t_listi **p, t_pivot v)
{
	while (last_between(*p, v.min, v.max))
		ft_rrab(p, "rra\n");
}

void	pass_limits(t_listi **a, t_listi **b, int i)
{
	int		minpos;
	int		maxpos;
	t_listi	*p;

	p = *a;
	while (p)
	{
		if (p->n == pile_max(*a))
			maxpos = i;
		if (p->n == pile_min(*a))
			minpos = i;
		i++;
		p = p->next;
	}
	i = pile_len(*a);
	maxpos = (ft_abs(maxpos - i) < maxpos) ? -ft_abs(maxpos - i) : maxpos;
	minpos = (ft_abs(minpos - i) < minpos) ? -ft_abs(minpos - i) : minpos;
	minpos = (ft_abs(minpos) > ft_abs(maxpos)) ? maxpos : minpos;
	while (minpos != 0)
	{
		(minpos < 0) ? ft_rrab(a, "rra\n") : ft_rab(a, "ra\n");
		minpos += (minpos < 0) ? 1 : -1;
	}
	ft_pab(b, a, "pb\n");
	(pile_len(*a) == 4) ? pass_limits(a, b, 0) : 0;
}

void	insert_listi(t_listi **a, t_listi **b)
{
	ft_pab(b, a, "pa\n");
	if (ordered(*a, 1) && (*b))
		insert_listi(a, b);
	else
	{
		if (!ordered(*a, 1))
			ft_rab(a, "ra\n");
		if (*b)
			insert_listi(a, b);
	}
}

void	mini_solve(t_listi **pa, t_listi **pb)
{
	int a;
	int b;

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
