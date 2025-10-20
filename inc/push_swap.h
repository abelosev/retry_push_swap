/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anbelose <anbelose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 21:37:38 by anbelose          #+#    #+#             */
/*   Updated: 2025/10/20 21:42:42 by anbelose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

char	**get_input_tab(int ac, char **av);
t_node	*create_stack(int ac, char **av);
long	ft_atoi_modif(const char *s);
int		is_doubled(t_node **node);
void	indexation(t_node **node);
int		list_size(t_node *node);
int		is_sorted(t_node **node);
void	del_stack(t_node **node);
void	del_both_stacks(t_node **a, t_node **b);
char	**copy_tab(char **tab);
void	tab_free(char **tab);
t_node	*find_max(t_node **node);
t_node	*find_min(t_node **node);
t_node	*find_next_min(t_node **node);
t_node	*find_last(t_node *node);
void	mini_sort(t_node **a, t_node **b);
int		get_min(t_node **node, int value_index);
int		get_gap(t_node **node, int index);
void	sort_radix(t_node **a, t_node **b);
void	do_pa(t_node **b, t_node **a);
void	do_pb(t_node **a, t_node **b);
void	do_r(t_node **a, t_node **b);
void	do_rr(t_node **a, t_node **b);
void	do_s(t_node **a, t_node **b);

#endif
