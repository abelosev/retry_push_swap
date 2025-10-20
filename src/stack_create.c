/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbelose <anbelose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:50:33 by anbelose          #+#    #+#             */
/*   Updated: 2025/10/20 21:50:45 by anbelose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\n' || c == '\f');
}

long	ft_atoi_modif(const char *s)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (!s || !(*s))
		return (0);
	while (s[i] && ft_isspace(s[i]))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] && ft_isdigit(s[i]))
	{
		res = res * 10 + s[i] - '0';
		i++;
	}
	return (res * sign);
}

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

t_node	*create_stack(int ac, char **av)
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
