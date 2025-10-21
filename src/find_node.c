/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbelose <anbelose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:44:15 by anbelose          #+#    #+#             */
/*   Updated: 2025/10/20 21:44:37 by anbelose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max(t_node **node)
{
	t_node	*max;
	t_node	*current;

	max = *node;
	current = *node;
	while (current)
	{
		if (current->value > max->value)
			max = current;
		current = current->next;
	}
	return (max);
}

t_node	*find_min(t_node **node)
{
	t_node	*min;
	t_node	*current;

	min = *node;
	current = *node;
	while (current)
	{
		if (current->value < min->value)
			min = current;
		current = current->next;
	}
	return (min);
}

t_node	*find_next_min(t_node **node)
{
	t_node	*head;
	t_node	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *node;
	while (head)
	{
		if ((head->index == -1) && (!has_min || head->value < min->value))
		{
			min = head;
			has_min = 1;
		}
		head = head->next;
	}
	return (min);
}

t_node	*find_last(t_node *node)
{
	while (node && node->next)
		node = node->next;
	return (node);
}
