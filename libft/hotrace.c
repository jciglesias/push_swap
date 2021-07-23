/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiglesia <jiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 22:51:38 by jiglesia          #+#    #+#             */
/*   Updated: 2021/06/04 22:51:59 by jiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_trie	*new_node(void)
{
	t_trie	*new;

	new = (t_trie *)malloc(sizeof(t_trie));
	if (!new)
		return (NULL);
	new->map = (t_trie **)malloc(sizeof(t_trie *) * 127);
	if (!new->map)
		return (NULL);
	ft_memset(new->map, 0, sizeof(t_trie *) * 127);
	new->end = 0;
	new->children = 0;
	new->value = NULL;
	return (new);
}

void	insert_trie(t_trie **root, char *cmd, int eq)
{
	t_trie	*temp;
	int		i;
	char	x;

	if (*root == NULL)
		*root = new_node();
	i = 0;
	temp = *root;
	while (cmd[i] && i < eq)
	{
		x = cmd[i++];
		if (temp->map[(int)x] == NULL)
		{
			temp->map[(int)x] = new_node();
			temp->children++;
		}
		temp = temp->map[(int)x];
	}
	if (temp->end)
		return ;
	temp->end = 1;
	if (cmd[eq + 1])
		temp->value = ft_strdup(&cmd[eq + 1]);
	else
		temp->value = ft_strdup("");
}

char	*get_value(t_trie *root, char *cmd)
{
	t_trie	*temp;
	int		i;
	char	x;

	if (root == NULL)
		return (NULL);
	i = 0;
	temp = root;
	while (cmd[i])
	{
		x = cmd[i];
		temp = temp->map[(int)x];
		if (temp == NULL)
			return (NULL);
		i++;
	}
	if (temp->end)
		return (temp->value);
	return (NULL);
}

void	delete_node(t_trie **node)
{
	if ((*node)->value)
	{
		free((*node)->value);
		(*node)->value = NULL;
	}
	if ((*node)->map)
		free((*node)->map);
	(*node)->map = NULL;
	if (*node)
		free(*node);
	*node = NULL;
}

t_trie	**delete_value(t_trie **root, char *key, int len, int depth)
{
	if (*root == NULL)
		return (NULL);
	if (depth == len)
	{
		if ((*root)->end)
			(*root)->end = 0;
		if ((*root)->value)
		{
			free((*root)->value);
			(*root)->value = NULL;
		}
		if ((*root)->children == 0)
			delete_node(root);
		return (root);
	}
	if ((*root)->map[(int)key[depth]])
	{
		(*root)->map[(int)key[depth]] = *delete_value(
				&(*root)->map[(int)key[depth]], key, len, depth + 1);
		if ((*root)->map[(int)key[depth]] == NULL)
			(*root)->children--;
	}
	if ((*root)->children == 0 && (*root)->end == 0)
		delete_node(root);
	return (root);
}
