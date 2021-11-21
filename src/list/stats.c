/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:14:24 by jiglesia          #+#    #+#             */
/*   Updated: 2021/11/21 17:38:30 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ordered(t_listi *head, int ascendant)
{
	if (head && head->next)
	{
		if (head->n < head->next->n || ascendant)
		{
			while (head->next)
			{
				if (head->n > head->next->n)
					return (0);
				head = head->next;
			}
		}
		else if (head->n > head->next->n)
		{
			while (head->next)
			{
				if (head->n < head->next->n)
					return (0);
				head = head->next;
			}
		}
		else
			ordered(head->next, ascendant);
	}
	return (1);
}

int	count_between(t_listi *p, int min, int max)
{
	int	count;

	count = 0;
	while (p)
	{
		if (min <= p->n && p->n <= max)
			count++;
		p = p->next;
	}
	return (count);
}

int	median_between(t_listi *p, int min, int max)
{
	t_listi	*copy;
	int		size;
	int		x;

	copy = NULL;
	size = 0;
	while (p)
	{
		if (min <= p->n && p->n < max)
		{
			size++;
			push(&copy, p->n);
		}
		p = p->next;
	}
	x = find_median(copy, size / 2 + 1);
	free_listi(&copy);
	return (x);
}

int	find_median(t_listi *head, int k)
{
	t_listi	*l;
	t_listi	*r;
	int		median;

	l = NULL;
	r = NULL;
	median = head->n;
	if (pile_len(head) == 1)
		return (median);
	head = head->next;
	while (head)
	{
		if (head->n < median)
			push(&l, head->n);
		else
			push(&r, head->n);
		head = head->next;
	}
	if (pile_len(l) > k - 1)
		median = find_median(l, k);
	else if (pile_len(l) != k - 1)
		median = find_median(r, k - pile_len(l) - 1);
	free_listi(&l);
	free_listi(&r);
	return (median);
}
