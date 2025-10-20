/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbelose <anbelose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:48:01 by anbelose          #+#    #+#             */
/*   Updated: 2025/10/20 21:48:07 by anbelose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_node **a)
{
	t_node	*max;

	max = find_max(a);
	if (*a == max)
		do_r(a, NULL);
	else if ((*a)->next == max)
		do_rr(a, NULL);
	else if ((*a)->next->next == max)
		do_s(a, NULL);
	if (is_sorted(a) == 0)
		do_s(a, NULL);
}

void	sort_4(t_node **a, t_node **b)
{
	t_node	*min;

	min = find_min(a);
	if ((*a)->next == min)
		do_s(a, NULL);
	else if ((*a)->next->next == min)
	{
		do_rr(a, NULL);
		do_rr(a, NULL);
	}
	else if ((*a)->next->next->next == min)
		do_rr(a, NULL);
	do_pb(a, b);
	sort_3(a);
	do_pa(b, a);
}

void	sort_5(t_node **a, t_node **b)
{
	int	gap;

	gap = get_gap(a, get_min(a, -1));
	if (gap == 1)
		do_r(a, NULL);
	else if (gap == 2)
	{
		do_r(a, NULL);
		do_r(a, NULL);
	}
	else if (gap == 3)
	{
		do_rr(a, NULL);
		do_rr(a, NULL);
	}
	else if (gap == 4)
		do_rr(a, NULL);
	if (is_sorted(a))
		return ;
	do_pb(a, b);
	sort_4(a, b);
	do_pa(b, a);
}

void	mini_sort(t_node **a, t_node **b)
{
	int	size;

	if (is_sorted(a) == 1 || list_size(*a) == 0
		|| list_size(*a) == 1)
		return ;
	size = list_size(*a);
	if (size == 2)
		do_s(a, NULL);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}
