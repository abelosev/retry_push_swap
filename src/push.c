/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbelose <anbelose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:48:19 by anbelose          #+#    #+#             */
/*   Updated: 2025/10/20 21:48:22 by anbelose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_p(t_node **p_from, t_node **p_to)
{
	t_node	*temp;

	if (!(*p_from))
		return ;
	temp = (*p_from)->next;
	(*p_from)->next = *p_to;
	*p_to = *p_from;
	*p_from = temp;
}

void	do_pa(t_node **b, t_node **a)
{
	do_p(b, a);
	ft_putstr_fd("pa\n", 1);
}

void	do_pb(t_node **a, t_node **b)
{
	do_p(a, b);
	ft_putstr_fd("pb\n", 1);
}
