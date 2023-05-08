/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:20:26 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/08 16:10:22 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_no_numbers(int ac, char **av)
{
	int	i;
	int	tab;

	i = 0;
	tab = 1;
	while (tab < ac)
	{
		i = 0;
		while (av[tab][i])
		{
			if ((av[tab][i] < '0' || av[tab][i] > '9') &&
					(av[tab][i] != ' ' &&
					av[tab][i] != '-' &&
					av[tab][i] != '+' &&
					av[tab][i] != '\v' &&
					av[tab][i] != '\t'))
				exit(ft_printf("%s", MSG_NB));
			i++;
		}
		tab++;
	}
}



void	ft_check(t_stack *a)
{
	int	i;
	int	j;

	i = 1;
	while (i < a->len)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (a->list[i] == a->list[j])
			{
				free (a->list);
				free (a);
				exit(ft_printf("Error\n"));
			}
			j--;
		}
		i++;
	}
}

t_stack	*ft_split_int(char *av)
{
	char	**arg;
	int	i;
	t_stack	*res;

	arg = ft_split(av, ' ');
	if (!arg)
		exit (ft_printf("Memory error\n"));
	res = (t_stack *) ft_calloc (sizeof(t_stack), 1);
	if (!res)
		exit (ft_printf("Memory error\n"));
	while (arg[res->len])
		res->len++;
	res->list = (int *) malloc (sizeof(int) * res->len);
	if (!res->list)
		exit (ft_printf("Memory error\n"));
	i = 0;
	while (i < res->len)
		res->list[i++] = ft_atoi(arg[i]);
	i = 0;
	while (arg[i])
		free (arg[i++]);
	free (arg);
	return (res);
}

t_stack	*ft_put_in_tab(int ac, char **av)
{
	t_stack	*a;
	int	i;

	if (ac == 2)
		return (ft_split_int(av[1]));
	a = (t_stack *) malloc (sizeof(t_stack));
	if (!a)
		exit (ft_printf("Memory error\n"));
	a->list = (int *) malloc (sizeof(int) * ac - 1);
	if (!a->list)
                exit (ft_printf("Memory error\n"));
	i = 1;
	while (av[i])
	{
		a->list[i - 1] = ft_atoi(av[i]);
		i++;
	}
	a->len = i - 1;
	return (a);
}

t_stack	*ft_init_b(int len)
{
	t_stack	*b;

	b = (t_stack *) ft_calloc(sizeof(t_stack), 1);
	if (!b)
		exit (ft_printf("Memory error\n"));
	b->list = (int *) ft_calloc (sizeof(int), len);
	if (!b->list)
		exit (ft_printf("Memory error\n"));
	return (b);
}
