/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenlarh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 13:43:05 by hbenlarh          #+#    #+#             */
/*   Updated: 2018/10/22 18:31:34 by hbenlarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(small);
	j = 0;
	k = 0;
	if (i == 0)
		return ((char *)big);
	while (big[j] != '\0' && (i + j) <= n)
	{
		while (small[k] == big[j + k])
		{
			if (k == i - 1)
				return ((char *)big + j);
			k++;
		}
		k = 0;
		j++;
	}
	return (NULL);
}
