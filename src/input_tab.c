#include "push_swap.h"

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	is_number(char *av)
{
	int	i;

	i = 0;
	if (is_sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && !ft_isdigit(av[i]))
		return (0);
	return (1);
}

int	check_vide(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!ft_strlen(av[i]))
			return (1);
		i++;
	}
	return (0);
}

char **get_tab(int ac, char **av)
{
	char	**tab;

	if (ac < 2 || check_vide(ac, av))
		return (NULL);
	if (ac == 2)
	{
		tab = ft_split(av[1], ' ');
		if (!tab)
			return (NULL);
	}
	else
	{
		tab = copy_tab(av + 1);
		if (!tab)
			return (NULL);
	}
	return (tab);
}

char	**get_input_tab(int ac, char **av)
{
	int		i;
	char	**tab;	
	long	tmp;

	tab = get_tab(ac, av);
	if (!tab)
		return (NULL);
	i = (ac == 2) ? 0 : 1;
	while (tab[i])
	{
		tmp = ft_atoi(tab[i]);
		if (!is_number(tab[i]) || tmp < INT_MIN || tmp > INT_MAX)
		{
			tab_free(tab);
			return (NULL);
		}
		i++;
	}
	return (tab);
}