/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:43:10 by jiglesia          #+#    #+#             */
/*   Updated: 2021/07/23 19:27:16 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_list(t_listi *a, t_listi *b)
{
	t_listi	*tmp;

	if (b)
	{
		write(1, "KO\n", 3);
		return ;
	}
	tmp = a;
	while (tmp)
	{
		if (tmp->next && tmp->next->n < tmp->n)
		{
			write(1, "KO\n", 3);
			return ;
		}
		tmp = tmp->next;
	}
	write(1, "OK\n", 3);
}

int	ft_commands(char *line, t_listi **a, t_listi **b)
{
	if (!ft_strncmp(line, "sa", 2))
		return (ft_sab(a));
	else if (!ft_strncmp(line, "sb", 2))
		return (ft_sab(b));
	else if (!ft_strncmp(line, "ss", 2))
		return (ft_ss(a, b));
	else if (!ft_strncmp(line, "pa", 2))
		return (ft_pab(a, b));
	else if (!ft_strncmp(line, "pb", 2))
		return (ft_pab(b, a));
	else if (!ft_strncmp(line, "ra", 2))
		return (ft_rab(a));
	else if (!ft_strncmp(line, "rb", 2))
		return (ft_rab(b));
	else if (!ft_strncmp(line, "rra", 3))
		return (ft_rrab(a));
	else if (!ft_strncmp(line, "rrb", 3))
		return (ft_rrab(b));
	else if (!ft_strncmp(line, "rrr", 3))
		return (ft_rrr(a, b));
	else if (!ft_strncmp(line, "rr", 2))
		return (ft_rr(a, b));
	return (0);
}

void	ft_checker(t_listi *a, char *line)
{
	t_listi	*b;

	b = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_commands(line, &a, &b))
		{
			write(1, "Error\n", 6);
			free(line);
			break ;
		}
		if (line)
			free(line);
		line = NULL;
	}
	ft_check_list(a, b);
}

int	main(int argv, char **argc)
{
	char	**num;
	int		i;
	t_listi	*a;

	if (argv == 2)
	{
		i = 0;
		num = ft_split(argc[1], ' ');
		a = NULL;
		while (num[i])
			i++;
		if (!i)
		{
			ft_freesplit(num);
			return (1);
		}
		if (!valid_input(i, num) || !ft_fillist(&a, num, i))
		{
			ft_freesplit(num);
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		ft_checker(a, NULL);
	}
	return (0);
}