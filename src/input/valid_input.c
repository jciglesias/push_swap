/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:36:23 by jiglesia          #+#    #+#             */
/*   Updated: 2021/11/21 15:26:13 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cmp_nmb(char *n, char *tmp)
{
	int	i;

	i = 0;
	while (n[i])
	{
		if ((n[i] - tmp[i]) > 0)
			return (0);
		else if ((n[i] - tmp[i]) < 0)
			return (1);
		i++;
	}
	return (1);
}

static int	check_intlim(char *n)
{
	if ((ft_strlen(n) > 10 && n[0] != '-') || ft_strlen(n) > 11)
		return (0);
	else if (ft_strlen(n) == 11)
	{
		if (!cmp_nmb(n, "-2147483648"))
			return (0);
		return (1);
	}
	else if (ft_strlen(n) == 10)
	{
		if (!cmp_nmb(n, "2147483647"))
			return (0);
		return (1);
	}
	return (1);
}

static	int	check_doubles(char **num)
{
	int	i;
	int	j;

	i = 0;
	while (num[i + 1])
	{
		if (!check_intlim(num[i]))
			return (0);
		j = i + 1;
		while (num[j])
			if (!ft_strcmp(num[i], num[j++]))
				return (0);
		i++;
	}
	if (!check_intlim(num[i]))
		return (0);
	return (1);
}

int	valid_input(int i, char **num)
{
	int	j;

	while (i--)
	{
		j = -1;
		while (num[i][++j])
			if ((num[i][j] < '0' || num[i][j] > '9') && num[i][j] != '-')
				return (0);
	}
	if (!check_doubles(num))
		return (0);
	return (1);
}
