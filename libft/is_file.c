/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 22:52:43 by jiglesia          #+#    #+#             */
/*   Updated: 2021/06/04 22:52:43 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	can_openf(char *filename)
{
	struct stat	buf;
	int			exist;

	ft_memset(&exist, 0, sizeof(struct stat));
	exist = lstat(filename, &buf);
	if (exist == 0)
		return (1);
	return (0);
}

int	is_file(char *filename)
{
	struct stat	buf;

	if (lstat(filename, &buf) == -1)
		return (0);
	if (S_ISLNK(buf.st_mode))
		return (1);
	if (S_ISREG(buf.st_mode))
		return (1);
	if (S_ISCHR(buf.st_mode))
		return (1);
	if (S_ISSOCK(buf.st_mode))
		return (1);
	if (S_ISFIFO(buf.st_mode))
		return (1);
	if (can_openf(filename))
		return (1);
	return (0);
}
