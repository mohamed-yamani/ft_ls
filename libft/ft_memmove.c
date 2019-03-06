/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenlarh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 15:02:10 by hbenlarh          #+#    #+#             */
/*   Updated: 2018/10/22 16:10:09 by hbenlarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str_src;
	char	*str_dst;
	size_t	i;

	str_src = (char *)src;
	str_dst = (char *)dst;
	if (str_src < str_dst)
	{
		len -= 1;
		while ((int)len >= 0)
		{
			str_dst[len] = str_src[len];
			len--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			str_dst[i] = str_src[i];
			i++;
		}
	}
	return (dst);
}
