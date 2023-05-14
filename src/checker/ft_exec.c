/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:17:20 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/14 15:45:09 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error_checker(t_stack *a, t_stack *b, char **actions, int i)
{
	ft_printf(MSG_CHK, actions[i]);
	i = 0;
	while (actions[i])
	{
		free(actions[i]);
		i++;
	}
	free (actions);
	ft_free_all(a, b);
}

static void	ft_exec_r(t_stack *a, t_stack *b, char **actions, int i)
{
	if (!actions[i][1])
		ft_error_checker(a, b ,actions, i);
	if (actions[i][1] == 'a')
		ft_ra(a);
	else if (actions[i][1] == 'b')
		ft_rb(b);
	else if (actions[i][1] == 'r' && actions[i][2] == '\0')
		ft_rr(a, b);
	else if (actions[i][1] == 'r' && actions[i][2] == 'a')
		ft_rra(a);
	else if (actions[i][1] == 'r' && actions[i][2] == 'b')
		ft_rrb(b);
	else if (actions[i][1] == 'r' && actions[i][2] == 'r')
		ft_rrr(a, b);
	else
		ft_error_checker(a, b ,actions, i);
}

static void	ft_exec_p(t_stack *a, t_stack *b, char **actions, int i)
{
	if (!actions[i][1])
		ft_error_checker(a, b ,actions, i);
	if (actions[i][1] == 'a')
		ft_pa(a, b);
	else if (actions[i][1] == 'b')
		ft_pb(a, b);
	else
		ft_error_checker(a, b ,actions, i);
}

static void	ft_exec_s(t_stack *a, t_stack *b, char **actions, int i)
{
	if (!actions[i][1])
		ft_error_checker(a, b ,actions, i);
	if (actions[i][1] == 'a')
		ft_sa(a);
	else if (actions[i][1] == 'b')
		ft_sb(b);
	else if (actions[i][1] == 's')
		ft_ss(a, b);
	else
		ft_error_checker(a, b ,actions, i);
}

void	ft_exec(t_stack *a, t_stack *b, char **actions)
{
	int	i;

	i = 0;
	while (actions[i])
	{
		if (actions[i][0] && actions[i][0] == 's')
			ft_exec_s(a, b, actions, i);
		else if (actions[i][0] && actions[i][0] == 'p')
			ft_exec_p(a, b, actions, i);
		else if (actions[i][0] && actions[i][0] == 'r')
			ft_exec_r(a, b, actions, i);
		else
			ft_error_checker(a, b ,actions, i);
		i++;
	}
}
