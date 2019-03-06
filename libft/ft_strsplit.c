/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenlarh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 11:34:34 by hbenlarh          #+#    #+#             */
/*   Updated: 2018/10/22 17:01:55 by hbenlarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i] != c && s[i] != '\0')
		{
			count++;
		}
		while (s[i] != c && s[i] != '\0')
		{
			i++;
		}
	}
	return (count);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**t;
	int		i;
	int		col;
	int		row;

	i = 0;
	row = 0;
	if (!s || (!(t = (char **)malloc(sizeof(*t) * (count(s, c) + 1)))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			col = 0;
			while (s[i + col] != '\0' && (s[i + col] != c))
				col++;
			t[row] = ft_strsub(s, i, col);
			row++;
			i = i + col;
		}
	}
	t[row] = NULL;
	return (t);
}
