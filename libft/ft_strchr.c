/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenlarh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:08:02 by hbenlarh          #+#    #+#             */
/*   Updated: 2018/10/17 18:19:55 by hbenlarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == c)
		{
			return ((char *)src + i);
		}
		i++;
	}
	if (!c)
	{
		return ((char *)src + i);
	}
	return (NULL);
}
