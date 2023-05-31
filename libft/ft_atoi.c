/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:20:22 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/31 17:05:36 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	ft_will_of(int total, int sign, int add)
{
	int	temp;

	if (total == 0 && add == 0)
		return (0);
	temp = (total * 10) + add;
	if (sign > 0)
	{
		if ((temp - add) / 10 == total && temp > 0)
			return (0);
		else
			return (1);
	}
	temp *= -1;
	if ((temp + add) / 10 == total * -1 && temp < 0)
		return (0);
	else
		return (1);
	return (0);
}

int	ft_pre_atoi(const char *nptr, t_stack *a)
{
	int	i;

	i = 0;
	while (nptr[i])
	{
		if (i > 0 && nptr[i] == '-')
		{
			a->len = -2;
			return (0);
		}
		i++;
	}
	return (ft_atoi(nptr, a));
}

int	ft_atoi(const char *nptr, t_stack *a)
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
		if (ft_will_of(result, sign, nptr[i] - 48) == 1 && a->len > 0)
			a->len = -1;
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	return (result * sign);
}
