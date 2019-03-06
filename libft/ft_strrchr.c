/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenlarh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:20:48 by hbenlarh          #+#    #+#             */
/*   Updated: 2018/10/17 18:59:29 by hbenlarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	int l;

	l = ft_strlen(src);
	while (l >= 0)
	{
		if (src[l] == c)
		{
			return ((char *)src + l);
		}
		l--;
	}
	return (NULL);
}
