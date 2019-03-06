/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenlarh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 11:44:42 by hbenlarh          #+#    #+#             */
/*   Updated: 2018/10/22 18:36:26 by hbenlarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t n;

	i = ft_strlen(dest);
	j = ft_strlen(src);
	if (size < i)
	{
		n = size + j;
	}
	else
	{
		n = i + j;
	}
	j = 0;
	while (size > (i + 1) && src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		++i;
	}
	dest[i] = '\0';
	return (n);
}
