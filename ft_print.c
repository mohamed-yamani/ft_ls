/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <myamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:58:34 by myamani           #+#    #+#             */
/*   Updated: 2019/03/05 12:59:31 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_ls.h"

void	ft_print(t_params *params)
{
	t_file	*file;
	t_list	*list;

	list = params->files;
	while(list)
	{
		file = (t_file *)list->content;
		printf("\nfile->time : %d - file->hour %s name : %s", file->time, file->hour, file->name);
		//printf(" --- %s --- - %d - %d - %s - %s - %d - hour %s \n", file->chemain, file->nlink, file->size, file->group_name, file->user_name, file->time, file->hour);
		list = list->next;
	}
}
