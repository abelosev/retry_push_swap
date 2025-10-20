/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbelose <anbelose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:48:38 by anbelose          #+#    #+#             */
/*   Updated: 2025/10/20 21:49:00 by anbelose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotrev(t_node **node)
{
	t_node	*temp;
	t_node	*prev_last;
	t_node	*last;

	temp = *node;
	prev_last = *node;
	while (prev_last && prev_last->next && prev_last->next->next)
		prev_last = prev_last->next;
	last = prev_last->next;
	*node = last;
	(*node)->next = temp;
	prev_last->next = NULL;
}

void	do_rr(t_node **a, t_node **b)
{
	if (a && b)
	{
		do_rotrev(a);
		do_rotrev(b);
		ft_putstr_fd("rrr\n", 1);
	}
	else if (a)
	{
		do_rotrev(a);
		ft_putstr_fd("rra\n", 1);
	}
	else
	{
		do_rotrev(b);
		ft_putstr_fd("rrb\n", 1);
	}
}
