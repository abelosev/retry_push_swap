/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbelose <anbelose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:50:11 by anbelose          #+#    #+#             */
/*   Updated: 2025/10/20 21:50:17 by anbelose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_size(t_node *node)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = node;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	is_sorted(t_node **node)
{
	t_node	*current;

	current = *node;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_doubled(t_node **node)
{
	t_node	*to_compare;
	t_node	*current;

	if (!(*node))
		return (1);
	to_compare = *node;
	current = (*node)->next;
	while (to_compare->next && current)
	{
		while (current)
		{
			if (current->value == to_compare->value)
				return (1);
			current = current->next;
		}
		to_compare = to_compare->next;
		current = to_compare->next;
	}
	return (0);
}

void	indexation(t_node **node)
{
	t_node	*current;
	int		i;

	i = 0;
	current = find_next_min(node);
	while (current)
	{
		current->index = i++;
		current = find_next_min(node);
	}
}
