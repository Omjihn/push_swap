/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:59:24 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/13 15:21:03 by gbricot          ###   ########.fr       */
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
					av[tab][i] != '\t') &&
					av[tab][i] != '\n')
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
			if (a->list[i]->nb == a->list[j]->nb)
			{
				ft_printf("Error\n");
				ft_free_all(a, NULL);
			}
			j--;
		}
		i++;
	}
}
