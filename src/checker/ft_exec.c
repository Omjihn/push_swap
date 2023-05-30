/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:17:20 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/30 20:44:08 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error_checker(t_stack *a, t_stack *b, char *actions)
{
	ft_printf(MSG_CHK);
	free (actions);
	ft_free_all(a, b);
}

static void	ft_exec_r(t_stack *a, t_stack *b, char *actions, int i)
{
	if (!actions[i])
		ft_error_checker(a, b, actions);
	if (actions[i + 1] == 'a')
		ft_ra(a);
	else if (actions[i + 1] == 'b')
		ft_rb(b);
	else if (actions[i + 1] == 'r')
		ft_rr(a, b);
	else if (actions[i + 1] == 'r' && actions[i + 2] == 'a')
		ft_rra(a);
	else if (actions[i + 1] == 'r' && actions[i + 2] == 'b')
		ft_rrb(b);
	else if (actions[i + 1] == 'r' && actions[i + 2] == 'r')
		ft_rrr(a, b);
	else
		ft_error_checker(a, b, actions);
}

static int	ft_exec_p(t_stack *a, t_stack *b, char *actions, int i)
{
	if (!actions[i])
		ft_error_checker(a, b, actions);
	if (actions[i + 1] == 'a')
	{
		ft_pa(a, b);
		return (2);
	}
	else if (actions[i + 1] == 'b')
	{
		ft_pb(a, b);
		return (2);
	}
	ft_error_checker(a, b, actions);
	return (0);
}

static int	ft_exec_s(t_stack *a, t_stack *b, char *actions, int i)
{
	if (!actions[i])
		ft_error_checker(a, b, actions);
	if (actions[i + 1] == 'a')
	{
		ft_sa(a);
		return (2);
	}
	else if (actions[i + 1] == 'b')
	{
		ft_sb(b);
		return (2);
	}
	else if (actions[i + 1] == 's')
	{
		ft_ss(a, b);
		return (2);
	}
	ft_error_checker(a, b, actions);
	return (0);
}

void	ft_exec(t_stack *a, t_stack *b, char *actions)
{
	int	i;

	i = 0;
	while (actions[i])
	{
		if (actions[i] && actions[i] == 's')
			i += ft_exec_s(a, b, actions, i);
		else if (actions[i] && actions[i] == 'p')
			i += ft_exec_p(a, b, actions, i);
		else if (actions[i] && actions[i] == 'r')
		{
			ft_exec_r(a, b, actions, i);
			if ((actions[i + 1] == 'r' && actions[i + 2] == 'a')
				|| (actions[i + 1] == 'r'
					&& actions[i + 2] == 'b')
				|| (actions[i + 1] == 'r'
					&& actions[i + 2] == 'r'))
				i += 3;
			else
				i += 2;
		}
		else
			ft_error_checker(a, b, actions);
	}
}
