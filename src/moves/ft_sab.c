/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:58:13 by jiglesia          #+#    #+#             */
/*   Updated: 2021/07/23 19:27:51 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sab(t_listi **a)
{
	t_listi	*tmp;

	if (!*a || !(*a)->next)
		return (1);
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
	return (1);
}

int	ft_ss(t_listi **a, t_listi **b)
{
	ft_sab(a);
	ft_sab(b);
	return (1);
}

int	ft_pab(t_listi **a, t_listi **b)
{
	t_listi	*tmp;

	if (!*b)
		return (1);
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	return (1);
}

int	ft_rab(t_listi **a)
{
	t_listi	*tmp;

	if (!*a || !(*a)->next)
		return (1);
	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *a;
	*a = (*a)->next;
	tmp = tmp->next;
	tmp->next = NULL;
	return (1);
}

int	ft_rr(t_listi **a, t_listi **b)
{
	ft_rab(a);
	ft_rab(b);
	return (1);
}
