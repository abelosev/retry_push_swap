#include "push_swap.h"

void	error_exit(t_node **a, t_node **b)
{
	del_both_stacks(a, b);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	b = NULL;
	a = create_stack(ac, av);
	if (!a || is_doubled(&a))
		error_exit(&a, &b);
	indexation(&a);
	if (list_size(a) <= 5)
		mini_sort(&a, &b);
	else
		sort_radix(&a, &b);
	del_both_stacks(&a, &b);
	return (0);
}
