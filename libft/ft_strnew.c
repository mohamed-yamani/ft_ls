/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenlarh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:54:38 by hbenlarh          #+#    #+#             */
/*   Updated: 2018/10/20 15:03:42 by hbenlarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*t;

	t = (char *)malloc(sizeof(char) * size + 1);
	if (t == NULL)
	{
		return (NULL);
	}
	ft_bzero(t, size + 1);
	return (t);
}
