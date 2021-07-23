/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avjoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 22:53:33 by jiglesia          #+#    #+#             */
/*   Updated: 2021/06/04 22:53:34 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_avjoin(char **av, int *ac, char *str)
{
	char	**new;
	int		i;

	if (av && *ac && str)
	{
		new = malloc(sizeof(char *) * (*ac + 2));
		i = 0;
		while (i < *ac)
		{
			new[i] = av[i];
			i++;
		}
		new[(*ac)++] = str;
		new[*ac] = NULL;
		free(av);
		return (new);
	}
	return (NULL);
}
