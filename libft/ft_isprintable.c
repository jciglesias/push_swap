/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprintable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 22:53:59 by jiglesia          #+#    #+#             */
/*   Updated: 2021/06/04 22:54:00 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprintable(char *str)
{
	int	i;

	i = 0;
	while (str[i] && 32 <= str[i] && str[i] < 127)
		i++;
	if (str[i])
		return (0);
	return (1);
}
