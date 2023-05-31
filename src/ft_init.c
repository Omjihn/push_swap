/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:20:26 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/31 09:54:44 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_overflow(t_stack *a)
{
	if (a->len == -1)
		ft_printf(MSG_OF);
	else
		ft_printf("Error please put '-' only before a number\n");
	ft_free_all(a, NULL);
}

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
	int		i;
	char	**arg;
	t_stack	*res;

	arg = ft_split(av);
	if (!arg)
		exit (ft_printf("Memory error\n"));
	res = (t_stack *) ft_calloc (sizeof(t_stack), 1);
	while (arg[res->len])
		res->len++;
	res->list = (t_nb **) ft_calloc (sizeof(t_nb *), res->len);
	i = -1;
	ft_init_list(res, res->len);
	while (++i < res->len)
		res->list[i]->nb = ft_pre_atoi(arg[i], res);
	i = 0;
	while (arg[i])
		free (arg[i++]);
	free (arg);
	if (res->len < 0)
		ft_overflow(res);
	return (res);
}

t_stack	*ft_put_in_tab(int ac, char **av)
{
	int		i;
	t_stack	*a;

	if (ac == 2)
		return (ft_split_int(av[1]));
	a = (t_stack *) malloc (sizeof(t_stack));
	if (!a)
		exit (ft_printf("Memory error\n"));
	a->list = (t_nb **) ft_calloc (sizeof(t_nb *), ac - 1);
	if (!a->list)
		exit (ft_printf("Memory error\n"));
	ft_init_list(a, ac - 1);
	a->len = ac - 1;
	i = 1;
	while (av[i])
	{
		a->list[i - 1]->nb = ft_pre_atoi(av[i], a);
		i++;
	}
	if (a->len < 0)
		ft_overflow(a);
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
