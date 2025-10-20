/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbelose <anbelose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:49:09 by anbelose          #+#    #+#             */
/*   Updated: 2025/10/20 21:49:11 by anbelose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rot(t_node **node)
{
	t_node	*last;
	t_node	*temp;
	t_node	*temp2;

	temp = *node;
	temp2 = (*node)->next;
	last = *node;
	while (last->next != NULL)
		last = last->next;
	last->next = temp;
	temp->next = NULL;
	*node = temp2;
}

void	do_r(t_node **a, t_node **b)
{
	if (a && b)
	{
		do_rot(a);
		do_rot(b);
		ft_putstr_fd("rr\n", 1);
	}
	else if (a)
	{
		do_rot(a);
		ft_putstr_fd("ra\n", 1);
	}
	else
	{
		do_rot(b);
		ft_putstr_fd("rb\n", 1);
	}
}
