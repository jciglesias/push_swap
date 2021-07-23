/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 22:52:57 by jiglesia          #+#    #+#             */
/*   Updated: 2021/06/04 22:52:57 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpop(char *str, size_t i)
{
	if (str && i <= ft_strlen(str))
	{
		str[i] = 0;
		if (str[i + 1])
			str = ft_fstrjoin(str, &str[i + 1]);
	}
	return (str);
}
