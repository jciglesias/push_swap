/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushpop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:06:20 by jiglesia          #+#    #+#             */
/*   Updated: 2021/11/20 23:17:19 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_listi **head, int val)
{
	t_listi *new;

	new = ft_newlisti(val, pile_len(*head));
	new->next = *head;
	*head = new;
}

void	pop(t_listi **head)
{
	t_listi	*next_node;

	if (*head == NULL)
		return ;
	next_node = (*head)->next;
	free(*head);
	*head = next_node;
}
