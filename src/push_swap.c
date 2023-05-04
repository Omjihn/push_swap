/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:40:50 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/04 16:53:57 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check(int *a)
{
	int	i;
	int	j;

	i = 1;
	while (a[i])
	{
		j = i - 1;
		while (j >= 0)
		{
			if (a[i] == a[j])
			{
				free (a);
				exit(ft_printf("Error\n"));
			}
			j--;
		}
		i++;
	}
}

int	*ft_split_arg(char *av)
{
	int	in_nb;
	int	i;
	int	len;

	i = 0;
	while (av[i])
	{
		if (' ' || '\t' || '\v')
			i++;


int	*ft_put_in_tab(int ac, char **av)
{
	char	**arg;
	int	*a;
	int	i;

	if (ac == 2)
		return (ft_one_arg(av[1]));
	a = (int *) ft_calloc (sizeof(int), ac - 1);
	if (!a)
		exit (ft_printf("Memory error\n"));
	i = 1;
	while (av[i])
	{
		a[i - 1] = ft_atoi(av[i]);
		i++;
	}
	return (a);
}

int	main(int ac, char **av)
{
	int	*a;
	int	i;

	if (ac == 1)
		exit (ft_printf("Error please enter numbers\n"));
	a = ft_put_in_tab(ac ,av);
	ft_check(a);
	i = 0;
	while (i < ac - 1)
	{
		ft_printf("%d\n", a[i]);
		i++;
	}
	return (0);
}
