/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbelose <anbelose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:49:48 by anbelose          #+#    #+#             */
/*   Updated: 2025/10/20 21:49:53 by anbelose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bits(t_node **node)
{
	t_node	*first;
	int		bits_max;
	int		max_index;

	first = *node;
	max_index = first->index;
	bits_max = 0;
	while (first != NULL)
	{
		if (first->index > max_index)
			max_index = first->index;
		first = first->next;
	}
	while ((max_index >> bits_max) != 0)
		bits_max++;
	return (bits_max);
}

void	radix_suppl(t_node **a, t_node **b, t_node *first_a, int i)
{
	if (((first_a->index >> i) & 1) == 1)
		do_r(a, NULL);
	else
		do_pb(a, b);
}

void	sort_radix(t_node **a, t_node **b)
{
	t_node	*first_a;
	int		i;
	int		k;
	int		size;
	int		bits_max;

	if (is_sorted(a))
		return ;
	i = 0;
	first_a = *a;
	size = list_size(first_a);
	bits_max = max_bits(a);
	while (i < bits_max)
	{
		k = 0;
		while (k++ < size)
		{
			first_a = *a;
			radix_suppl(a, b, first_a, i);
		}
		while (list_size(*b))
			do_pa(b, a);
		i++;
	}
}
