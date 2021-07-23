/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:26:54 by jiglesia          #+#    #+#             */
/*   Updated: 2021/07/21 18:35:57 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rrab(t_listi **a)
{
	t_listi	*tmp;

	if (!*a)
		return (1);
	tmp = *a;
	while ((*a)->next)
		*a = (*a)->next;
	(*a)->next = tmp;
	while (tmp->next != *a)
		tmp = tmp->next;
	tmp->next = NULL;
	return (1);
}

int	ft_rrr(t_listi **a, t_listi **b)
{
	ft_rrab(a);
	ft_rrab(b);
	return (1);
}
