/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:36:23 by jiglesia          #+#    #+#             */
/*   Updated: 2021/07/22 18:37:17 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (1);
}