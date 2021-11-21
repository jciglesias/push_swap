/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:59:26 by jiglesia          #+#    #+#             */
/*   Updated: 2021/11/21 17:05:20 by jiglesia         ###   ########.fr       */
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

void	move_down(int minpos, t_listi **a)
{
	while (minpos != 0)
	{
		if (minpos < 0)
			ft_rrab(a, "rra\n");
		else
			ft_rab(a, "ra\n");
		if (minpos < 0)
			++minpos;
		else
			--minpos;
	}
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
	if (ft_abs(maxpos - i) < maxpos)
		maxpos = -ft_abs(maxpos - i);
	if (ft_abs(minpos - i) < minpos)
		minpos = -ft_abs(minpos - i);
	if (ft_abs(minpos) > ft_abs(maxpos))
		minpos = maxpos;
	move_down(minpos, a);
	ft_pab(b, a, "pb\n");
	if (pile_len(*a) == 4)
		pass_limits(a, b, 0);
}

void	insert_listi(t_listi **a, t_listi **b)
{
	ft_pab(a, b, "pa\n");
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
