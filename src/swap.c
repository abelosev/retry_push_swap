/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbelose <anbelose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:51:01 by anbelose          #+#    #+#             */
/*   Updated: 2025/10/20 21:51:04 by anbelose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_swap(t_node *node)
{
	int	temp;

	if (node == NULL || node->next == NULL)
		return ;
	temp = node->value;
	node->value = node->next->value;
	node->next->value = temp;
	temp = node->index;
	node->index = node->next->index;
	node->next->index = temp;
}

void	do_s(t_node **a, t_node **b)
{
	if (a && b)
	{
		do_swap(*a);
		do_swap(*b);
		ft_putstr_fd("ss\n", 1);
	}
	else if (a)
	{
		do_swap(*a);
		ft_putstr_fd("sa\n", 1);
	}
	else
	{
		do_swap(*b);
		ft_putstr_fd("sb\n", 1);
	}
}
