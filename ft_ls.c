/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <myamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:58:34 by myamani           #+#    #+#             */
/*   Updated: 2019/03/04 21:43:45 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_ls.h"

int		main(int argc, char **argv)
{
	t_params	params;

	params.args = NULL;
	params.files = NULL;
	manageArg(argc, argv, &params);
	sort_args(&params);
	getfiles(&params);	
	ft_print(&params);
	ft_folders(&params);
	return (0);
}
