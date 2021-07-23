/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:16:51 by jiglesia          #+#    #+#             */
/*   Updated: 2021/07/23 17:17:38 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_middle(t_listi *a)
{
	long long		m;
	unsigned int	i;

	m = 0;
	i = 0;
	while (a)
	{
		m += a->n;
		a = a->next;
		i++;
	}
	return (m / i);
}

void	push_swap(t_listi *a, int size)
{
	t_listi	*b;
	int		m;

	if (size > 1)
	{
		b = NULL;
		m = find_middle(a);
	}
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
		push_swap(a, i);
	}
	return (0);
}
