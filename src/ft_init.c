/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:20:26 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/13 15:56:53 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_list(t_stack *stack, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		stack->list[i] = (t_nb *) malloc (sizeof(t_nb) * 1);
		stack->list[i]->nb = 0;
		stack->list[i]->index = 0;
		i++;
	}
}

t_stack	*ft_split_int(char *av)
{
	char	*arg;
	int	i;
	t_stack	*res;

	arg = ft_split(av);
	if (!arg)
		exit (ft_printf("Memory error\n"));
	res = (t_stack *) ft_calloc (sizeof(t_stack), 1);
	if (!res)
		exit (ft_printf("Memory error\n"));
	while (arg[res->len])
		res->len++;
	res->list = (t_nb **) ft_calloc (sizeof(t_nb *), res->len);
	if (!res->list)
		exit (ft_printf("Memory error\n"));
	i = -1;
	ft_init_list(res, res->len);
	while (++i < res->len)
		res->list[i]->nb = ft_atoi(arg[i]);
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
	a->list = (t_nb **) ft_calloc (sizeof(t_nb *), ac - 1);
	if (!a->list)
                exit (ft_printf("Memory error\n"));
	ft_init_list(a, ac - 1);
	i = 1;
	while (av[i])
	{
		a->list[i - 1]->nb = ft_atoi(av[i]);
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
	b->list = (t_nb **) ft_calloc (sizeof(t_nb *), len);
	if (!b->list)
		exit (ft_printf("Memory error\n"));
	return (b);
}
