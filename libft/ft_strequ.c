/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strqu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenlarh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 13:04:11 by hbenlarh          #+#    #+#             */
/*   Updated: 2018/10/22 17:15:36 by hbenlarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int c;

	if (s1 == NULL || s2 == NULL)
	{
		return (0);
	}
	c = ft_strcmp(s1, s2);
	if (c == 0)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
