/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenlarh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 15:16:42 by hbenlarh          #+#    #+#             */
/*   Updated: 2018/10/22 17:15:11 by hbenlarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int c;

	if (s1 == NULL || s2 == NULL)
	{
		return (0);
	}
	c = ft_strncmp(s1, s2, n);
	if (c == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
