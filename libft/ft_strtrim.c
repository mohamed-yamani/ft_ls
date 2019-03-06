/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenlarh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 12:55:44 by hbenlarh          #+#    #+#             */
/*   Updated: 2018/10/22 17:18:54 by hbenlarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int i;
	int size;
	int n_size;

	i = 0;
	size = 0;
	if (s == NULL)
		return (NULL);
	while (s[size] != '\0')
		size++;
	n_size = size;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		n_size--;
		i++;
	}
	if (i == size)
		return (ft_strdup(""));
	while (s[size - 1] == ' ' || s[size - 1] == '\t' || s[size - 1] == '\n')
	{
		size--;
		n_size--;
	}
	return (ft_strsub(s, i, n_size));
}
