#include "push_swap.h"

t_node	*create_new_node(int new_value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = new_value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

void	insert_end(t_node **node, t_node *to_insert)
{
	t_node	*last;

	if (!to_insert)
		return ;
	if (!(*node))
	{
		*node = to_insert;
		return ;
	}
	last = find_last(*node);
	last->next = to_insert;
}

t_node *create_stack(int ac, char **av)
{
	t_node	*a;
	t_node	*new_node;
	char	**tab;
	int		i;

	a = NULL;
	tab = get_input_tab(ac, av);
	if (!tab)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		new_node = create_new_node(ft_atoi(tab[i]));
		if (!new_node)
		{
			tab_free(tab);
			del_stack(&a);
			return (NULL);
		}
		insert_end(&a, new_node);
		i++;
	}
	tab_free(tab);
	return (a);
}
