/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:38:16 by jiglesia          #+#    #+#             */
/*   Updated: 2021/11/20 11:46:04 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_fillist(t_listi **l, char **num, int size)
{
	t_listi	*tmp;
	size_t	i;

	i = 1;
	tmp = NULL;
	if (!size)
		return (0);
	while (size--)
	{
		tmp = ft_newlisti(ft_atoi(num[size]), i++);
		tmp->next = *l;
		*l = tmp;
	}
	return (1);
}
