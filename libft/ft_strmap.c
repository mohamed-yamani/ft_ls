/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenlarh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:27:43 by hbenlarh          #+#    #+#             */
/*   Updated: 2018/10/22 17:17:00 by hbenlarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*t;
	int		i;

	i = 0;
	if (s == NULL)
	{
		return (NULL);
	}
	t = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (t == NULL)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		t[i] = f(s[i]);
		i++;
	}
	t[i] = '\0';
	return (t);
}
