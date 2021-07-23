/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:38:22 by jiglesia          #+#    #+#             */
/*   Updated: 2021/07/22 18:49:18 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PUSH_SWAP_H
# define	PUSH_SWAP_H

# include <unistd.h>
# include "libft.h"

int	ft_sab(t_listi **a);
int	ft_ss(t_listi **a, t_listi **b);
int	ft_rab(t_listi **a);
int	ft_rr(t_listi **a, t_listi **b);
int	ft_pab(t_listi **a, t_listi **b);
int	ft_rrab(t_listi **a);
int	ft_rrr(t_listi **a, t_listi **b);
int	ft_fillist(t_listi **l, char **num, int size);
int	valid_input(int i, char **num);

#endif
