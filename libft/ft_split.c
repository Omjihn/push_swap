/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbricot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 12:30:47 by gbricot           #+#    #+#             */
/*   Updated: 2023/05/16 16:42:09 by gbricot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

static int	ft_tab_cnt(char const *s, char *c)
{
	int	i;
	int	tab;

	i = 0;
	tab = 0;
	while (s[i])
	{
		while ((s[i] && s[i] == c[0]) || (s[i] && s[i] == c[1])
			|| (s[i] && s[i] == c[2]))
			i++;
		if ((s[i] && s[i] != c[0]) && (s[i] && s[i] != c[1])
			&& (s[i] && s[i] != c[2]))
			tab++;
		while ((s[i] && s[i] != c[0]) && (s[i] && s[i] != c[1])
			&& (s[i] && s[i] != c[2]))
			i++;
	}
	return (tab);
}

static	void	ft_put_res(char **res, const char *s, char *c)
{
	int	i;
	int	size;
	int	tab;

	i = 0;
	tab = 0;
	while (s[i])
	{
		if ((s[i] && s[i] != c[0]) && (s[i] && s[i] != c[1])
			&& (s[i] && s[i] != c[2]))
		{
			size = i;
			while ((s[size] && s[size] != c[0])
				&& (s[size] && s[size] != c[1])
				&& (s[size] && s[size] != c[2]))
				size++;
			res[tab] = (char *) ft_calloc(1, size - i + 1);
			ft_memcpy(res[tab], s + i, size - i);
			i = size;
			tab++;
		}
		else
			i++;
	}
}

char	**ft_split(char const *s)
{
	char	**res;
	char	*c;
	int		tab;

	c = " \n\t";
	tab = ft_tab_cnt(s, c);
	res = (char **) ft_calloc(sizeof(char *), tab + 1);
	if (!res)
		return (NULL);
	ft_put_res(res, s, c);
	res[tab] = 0;
	return (res);
}
