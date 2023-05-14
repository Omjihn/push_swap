/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_inputs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:46:41 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/14 15:49:53 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*ft_add_space(char *old, int i, int buffer)
{
	char	*res;

	res = (char *) ft_calloc(1, i + buffer + 1);
	if (!res)
	{
		free (old);
		return (0);
	}
	i = 0;
	while (old[i])
	{
		res[i] = old[i];
		i++;
	}
	free (old);
	return (res);
}

char	**ft_read_inputs(void)
{
	int		i;
	int		buffer;
	char	*str;
	char	**res;

	buffer = 42;
	i = 1;
	str = (char *) malloc(2);
	str[1] = '\0';
	while (read(1, str, 1) == 0)
	{
	}
	str = ft_add_space(str, i, buffer);
	while (read(1, str + i, buffer) == 42)
	{
		ft_printf("read\n");
		i += buffer;
		str = ft_add_space(str, i, buffer);
	}
	res = ft_split(str);
	free(str);
	return (res);
}
