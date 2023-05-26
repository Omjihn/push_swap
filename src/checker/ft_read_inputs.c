/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:46:41 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/26 15:42:05 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*ft_add_buffer(char *buffer, char *actions, int len)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (actions[i])
		i++;
	res = (char *) ft_calloc (i + len + 1, 1);
	if (!res)
		return (NULL);
	j = 0;
	while (i > j)
	{
		res[j] = actions[j];
		j++;
	}
	i = 0;
	while (buffer[i])
	{
		res[j] = buffer[i];
		i++;
		j++;
	}
	free (actions);
	return (res);
}

char	**ft_read_inputs(t_stack *a)
{
	int		nb_read;
	char	*buffer;
	char	*actions;
	char	**res;

	actions = (char *) ft_calloc(1, 1);
	buffer = (char *) ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		ft_free_all(a, NULL);
	while (1)
	{
		nb_read = read(0, buffer, BUFFER_SIZE);
		//ft_printf("%d", nb_read);
			if (nb_read == -1)
				exit(42);
			if (nb_read > 1)
			{
				buffer[nb_read - 1] = '\0';
				actions = ft_add_buffer(buffer, actions, nb_read);
				//ft_printf("%s\n", actions);
			}
			if (nb_read == 0 || nb_read == 1)
				break ;
	}
	//ft_printf("Exit\n");
	res = ft_split(actions);
	free (actions);
	return (res);
}
