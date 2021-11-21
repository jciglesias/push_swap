/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:16:51 by jiglesia          #+#    #+#             */
/*   Updated: 2021/11/21 10:52:52 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void q_sort(t_listi **a, t_listi **b, int isa, t_pivot v)
{
	int pivot;
	int tmp;

	if (ordered(*a, 1) && !(*b))
		return ;
	if (count_between((isa) ? *a : *b, v.min, v.max) > 2)
	{
		pivot = (isa) ? move_pivot(a, b, 1, v) : 0;
		(isa == 2) ? quick_return(a, v) : 0;
		pivot = (!isa) ? move_pivot(b, a, 0, v) : pivot;
		tmp = v.max;
		v.max = pivot;
		q_sort(a, b, 0, v);
		v.max = tmp;
		v.min = pivot;
		q_sort(a, b, 2, v);
	}
	else
	{
		if (pile_len(*b) > 1 && ((*b)->n < (*b)->next->n))
			ft_sab(b, "sb\n");
		ft_pab(a, b, "pa\n");
		if (*b)
			ft_pab(a, b, "pa\n");
	}
}

void	push_swap(t_listi *a, t_listi *b)
{
	t_pivot	v;

	v.min = pile_min(a);
	v.max = pile_max(a);
	if (ordered(a, 1))
	{
		free_listi(&a);
		free_listi(&b);
		return ;
	}
	if (pile_len(a) > 5 || pile_len(a) < 3)
	{
		q_sort(&a, &b, 1, v);
		while (a && a->n != v.min)
		{
			if (a->next && a->next->n != v.min && a->next->n < a->n)
				ft_sab(&a, "sa\n");
			ft_rab(&a, "ra\n");
		}
	}
	else
		mini_solve(&a, &b);
	free_listi(&a);
	free_listi(&b);
}

int	main(int argv, char **argc)
{
	char	**num;
	int		i;
	t_listi	*a;

	if (argv == 2)
	{
		i = 0;
		num = ft_split(argc[1], ' ');
		a = NULL;
		while (num[i])
			i++;
		if (!i)
		{
			ft_freesplit(num);
			return (1);
		}
		if (!valid_input(i, num) || !ft_fillist(&a, num, i))
		{
			ft_freesplit(num);
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		push_swap(a, NULL);
		return (0);
	}
	else if (argv > 2)
	{
		a = NULL;
		i = 1;
		while (argc[i])
			i++;
		if (!valid_input(i - 1, &argc[1]) || !ft_fillist(&a, &argc[1], i - 1))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		push_swap(a, NULL);
		return (0);
	}
	return (1);
}
