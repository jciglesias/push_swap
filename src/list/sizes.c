/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 20:38:31 by jiglesia          #+#    #+#             */
/*   Updated: 2021/11/21 11:16:56 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		pile_len(t_listi *head)
{
	int i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

int		pile_min(t_listi *p)
{
	int min;

	min = p->n;
	while (p)
	{
		if (p->n < min)
			min = p->n;
		p = p->next;
	}
	return (min);
}

int		pile_max(t_listi *p)
{
	int max;

	max = p->n;
	while (p)
	{
		if (p->n > max)
			max = p->n;
		p = p->next;
	}
	return (max);
}

int		closest_num(t_listi *p, int num)
{
	int pos;
	int cont;
	int dif;

	pos = 0;
	cont = 0;
	if (p)
		dif = ft_abs(p->n - num);
	while (p)
	{
		if (ft_abs(p->n - num) < dif)
		{
			dif = ft_abs(p->n - num);
			pos = cont;
		}
		cont++;
		p = p->next;
	}
	return (pos);
}

int		islarger(char *nb)
{
	int i;
	int pos;

	if (ft_strcmp(nb, "-") == 0)
		return (0);
	pos = (nb[0] != '-');
	if ((int)ft_strlen(nb) < 11 - pos)
		return (0);
	if ((int)ft_strlen(nb) > 11 - pos)
		return (1);
	if (nb[1 - pos] < 50)
		return (0);
	if (nb[1 - pos] > 50)
		return (1);
	if (nb[2 - pos])
	{
		i = ft_atoi(&nb[2 - pos]);
		if (i > 147483648 - pos)
			return (1);
	}
	return (0);
}
