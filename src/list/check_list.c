/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 22:28:44 by jiglesia          #+#    #+#             */
/*   Updated: 2021/11/21 15:23:18 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_listi	*end_node(t_listi *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

void	pass_pile(t_listi **p1, t_listi **p2, int side)
{
	ft_pab(p1, p2, "pb\n");
	if (side > 0)
		ft_rrab(p2, "rrb\n");
}

void	free_pile(t_listi **p)
{
	while (*p)
		pop(p);
}

int	are_left(t_listi *p, int pivot, int ispa, t_pivot v)
{
	int	much;

	much = 0;
	while (p)
	{
		if (ispa && v.min <= p->n && p->n < pivot)
			much += 1;
		if (!ispa && p->n >= pivot)
			much += 1;
		p = p->next;
	}
	return (much);
}

int	last_between(t_listi *p, int min, int max)
{
	while (p->next)
		p = p->next;
	return (min < p->n && p->n <= max);
}
