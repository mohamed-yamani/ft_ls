/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenlarh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:59:01 by hbenlarh          #+#    #+#             */
/*   Updated: 2018/10/17 16:20:32 by hbenlarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int sign;
	int nbr;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i] == '\n' || str[i] == '\t' ||
	str[i] == ' ' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	if (sign == 1)
		return (-nbr);
	else
		return (nbr);
}
