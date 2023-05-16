/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:20:22 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/16 13:47:47 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

int	ft_will_of(int total, int sign, int add)
{
	int	temp;

	temp = (total * 10) + add;
	if (sign > 0)
	{
		if ((temp - add) / 10 == total)
			return (0);
		else
			return (1);
	}
	temp *= -1;
	if ((temp - add) / 10 == total * -1)
		return (1);
	else
		return (0);
	return (0);
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
		if (ft_will_of(result, sign, nptr[i] - 48) == 1)
			a->len = 0;
		result *= 10;
		result += nptr[i] - 48;
		i++;
	}
	return (result * sign);
}
