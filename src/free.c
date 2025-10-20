#include "push_swap.h"

void	del_stack(t_node **node)
{
	t_node	*current;
	t_node	*temp;

	if (!node || !(*node))
		return ;
	current = NULL;
	temp = NULL;
	current = *node;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*node = NULL;
}

void	del_both_stacks(t_node **a, t_node **b)
{
	del_stack(a);
	del_stack(b);
}

void	tab_free(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char **copy_tab(char **tab)
{
	int i;
	int len;
	char **res;

	len = 0;
	while(tab[len])
		len++;
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = ft_strdup(tab[i]);
		if (!res[i])
			return (tab_free(res), NULL);
		i++;
	}
	res[i] = NULL;
	return (res);
}