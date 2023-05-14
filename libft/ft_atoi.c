/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:20:22 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/14 17:36:42 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	ft_will_of(int total, int sign, int add)
{
	int	max_add;

	if (sign > 0)
	{
		max_add = 2147483647 - total;
		if (max_add > add)
			return (1);
		else
			return (0);
	}
	else
	{
		max_add = 2147483648 - total;
		if (max_add > add)
			return (1);
		else
			return (0);
	}
}

void	ft_free_tab(t_stack *a, char **arg, int tabs)
{
	int	i;

	i = 0;
	if (arg)
	{
		while (arg[i])
		{
			free(arg[i]);
			i++:
		}
		free(arg);
	}
}

int	ft_atoi(const char *nptr, t_stack *a, int tabs, char **arg)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	i = 0;
	result = 0;
	while (nptr[i] == ' ' || nptr[i] == '\v' || nptr[i] == '\t' 
			|| nptr[i] == '\n')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] && nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (ft_will_of(result, sign, nptr[i] - 48) == 1)
			ft_free_tab(a, arg, tabs)
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	return (result * sign);
}
