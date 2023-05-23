/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:46:41 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/23 18:20:02 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*ft_add_str(char *all, char *add, int len)
{
	int		j;
	int		i;
	char	*res;

	i = 0;
	while (all[i])
		i++;
	if (i + len == 0)
		return (NULL);
	res = (char *) ft_calloc(1, i + len + 1);
	if (!res)
	{
		free (all);
		return (0);
	}
	i = 0;
	while (all[i])
	{
		res[i] = all[i];
		i++;
	}
	j = 0;
	while (add[j])
	{
		res[i + j] = add[j];
		j++;
	}
	free (all);
	return (res);
}

char	**ft_read_inputs(t_stack *a)
{
	int		nb_read;
	char	*all;
	char	str[BUFFER_SIZE];
	char	**res;

	while (1)
	{
		if ((nb_read = read(0, str, BUFFER_SIZE)) == -1)
			ft_free_all(a, NULL);
		if (nb_read == 0)
			break ;
		str[nb_read] = '\0';
		all = ft_add_str(all, str, nb_read);
		if (!all)
			ft_free_all(a, NULL);
		ft_printf("%d", all);
	}
	res = ft_split(all);
	free (all);
	return (res);
}
