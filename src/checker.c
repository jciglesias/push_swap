/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:43:10 by jiglesia          #+#    #+#             */
/*   Updated: 2021/05/08 21:32:26 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		valid_input(int i, char **num)
{
	int j;

	while (i--)
	{
		j = -1;
		while (num[i][++j])
			if ((num[i][j] < '0' || num[i][j] > '9') && num[i][j] != '-')
				return (0);
	}
	return (1);
}

int		ft_freesplit(char **splt)
{
	int i;

	i = -1;
	while (splt[++i]);
	if (!i)
		return (0);
	while (--i >= 0)
		free(splt[i]);
	return (1);
}

int		ft_fillist(t_listi *l, char **num, int size)
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
		tmp->next = l;
		l = tmp;
	}
	tmp = ft_newlisti(ft_atoi(num[0]), i);
	tmp->next = l;
	l = tmp;
	return (1);
}

void	ft_check_list(t_listi *a, t_listi *b)
{
	t_listi *tmp;

	if (b)
	{
		write(1, "KO\n", 3);
		return ;
	}
	tmp = a;
	while (tmp)
	{
		if (tmp->next->n < tmp->n)
		{
			write(1, "KO\n", 3);
			return ;
		}
		tmp = tmp->next;
	}
	write(1, "OK\n", 3);
}

int	ft_commands(char *line, t_listi *a, t_listi *b)
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
	else if (!ft_strncmp(line, "rr", 2))
		return (ft_rr(a, b));
	else if (!ft_strncmp(line, "rra", 3))
		return (ft_rrab(a));
	else if (!ft_strncmp(line, "rrb", 3))
		return (ft_rrab(b));
	else if (!ft_strncmp(line, "rrr", 3))
		return (ft_rrr(a, b));
	return (0);
}

void	ft_checker(t_listi *a, char *line)
{
	char	**bowl;
	t_listi	*b;

	b = NULL;
	while (get_next_line(0, &line) > 0)
	{
		write(1, "hi\n", 3);
		if (!ft_commands(line, a, b))
		{
			write(1, "Error\n", 6);
			break ;
		}
		free(line);
	}
	//get_next_line(-1, &line);
	ft_check_list(a, b);
}

int		main(int argv, char **argc)
{
	char	**num;
	int		i;
	t_listi	*a;

	if (argv == 2)
	{
		i = -1;
		num = ft_split(argc[1], ' ');
		a = NULL;
		while (num[++i]);
		if (!i)
			return (ft_freesplit(num));
		if (!valid_input(i, num) || !ft_fillist(a, num, i))
		{
			ft_freesplit(num);
			return(ft_puterror("Error\n", 0));
		}
		ft_checker(a, NULL);
	}
	return (0);
}
