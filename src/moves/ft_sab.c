/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 19:58:13 by jiglesia          #+#    #+#             */
/*   Updated: 2021/11/20 19:31:39 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sab(t_listi **a, char *cout)
{
	t_listi	*tmp;

	if (!*a || !(*a)->next)
		return (1);
	ft_putstr(cout);
	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next = *a;
	*a = tmp;
	return (1);
}

int	ft_pab(t_listi **a, t_listi **b, char *cout)
{
	t_listi	*tmp;

	if (!*b)
		return (1);
	ft_putstr(cout);
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	return (1);
}

int	ft_rab(t_listi **a, char *cout)
{
	t_listi	*tmp;

	if (!*a || !(*a)->next)
		return (1);
	tmp = *a;
	ft_putstr(cout);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *a;
	*a = (*a)->next;
	tmp = tmp->next;
	tmp->next = NULL;
	return (1);
}

int	ft_rrab(t_listi **a, char *cout)
{
	t_listi	*tmp;

	if (!*a)
		return (1);
	ft_putstr(cout);
	tmp = *a;
	while ((*a)->next)
		*a = (*a)->next;
	(*a)->next = tmp;
	while (tmp->next != *a)
		tmp = tmp->next;
	tmp->next = NULL;
	return (1);
}
