#include "push_swap.h"

int	get_min(t_node **node, int value_index)
{
	t_node	*current;
	int		min;

	current = *node;
	min = current->index;
	while (current->next)
	{
		current = current->next;
		if ((current->index < min) && current->index != value_index)
			min = current->index;
	}
	return (min);
}

int	get_gap(t_node **node, int index)
{
	t_node	*current;
	int		gap;

	gap = 0;
	current = *node;
	while (current)
	{
		if (current->index == index)
			break ;
		gap++;
		current = current->next;
	}
	return (gap);
}