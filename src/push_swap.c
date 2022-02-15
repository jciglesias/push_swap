/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:16:51 by jiglesia          #+#    #+#             */
/*   Updated: 2022/02/15 18:43:53 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	q_sort(t_listi **a, t_listi **b, int isa, t_pivot v)
{
	int	tmp;

	if (ordered(*a, 1) && !(*b))
		return ;
	if (isa)
		tmp = count_between(*a, v.min, v.max);
	else
		tmp = count_between(*b, v.min, v.max);
	if (tmp > 2)
		ft_sort(a, b, isa, v);
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

static int	parsing(char **num, t_listi **a, int size)
{
	while (num[size])
		size++;
	if (!size)
		return (1);
	if (!valid_input(size, num) || !ft_fillist(a, num, size))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

int	main(int argv, char **argc)
{
	char	**num;
	t_listi	*a;

	a = NULL;
	if (argv == 2)
	{
		num = ft_split(argc[1], ' ');
		if (!ft_strcmp(argc[1], ""))
			ft_putstr_fd("Error\n", 2);
		if (parsing(num, &a, 0))
		{
			ft_freesplit(num);
			return (1);
		}
		push_swap(a, NULL);
	}
	else if (argv > 2)
	{
		if (parsing(&argc[1], &a, 0))
			return (1);
		push_swap(a, NULL);
	}
	return (0);
}
