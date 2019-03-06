/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <myamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:58:34 by myamani           #+#    #+#             */
/*   Updated: 2019/03/04 14:39:39 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 	sortascii(t_params *params)
{
	t_file *head;
	t_file *file;
	t_list *list;
	t_list *head_list;
	t_flags flags;

	flags = params->flags;
	list = params->files;
	head_list = list;

	while (list)
	{
		file = (t_file *)list->content;
		if (list->next)
		{
			head = (t_file *)(list->next->content);
			if (ft_strcmp(head->name , file->name) * flags.r < 0)
			{
				list->content = head;
				list->next->content = file;
				list = head_list;
				continue ;
			}
		}
		list = list->next;
	}
}

void 	sort_args(t_params *params)
{
	t_args *head;
	t_args *file;
	t_list *list;
	t_list *head_list;

	list = params->args;
	head_list = list;

	while (list)
	{
		file = (t_args *)list->content;
		if (list->next)
		{
			head = (t_args *)(list->next->content);
			if (ft_strcmp(head->name , file->name) < 0)
			{
				list->content = head;
				list->next->content = file;
				list = head_list;
				continue ;
			}
		}
		list = list->next;
	}
}

void		sort_times(t_params *params)
{
	t_file *head;
	t_file *file;
	t_list *list;
	t_list *head_list;
	t_flags flags;

	flags = params->flags;
	list = params->files;
	head_list = list;
	sortascii(params);
	while (list)
	{
		file = (t_file *)list->content;
		if (list->next)
		{
			head = (t_file *)(list->next->content);
			if ((head->time - file->time) * flags.r > 0)
			{
				list->content = head;
				list->next->content = file;
				list = head_list;
				continue ;
			}
		}
		list = list->next;
	}
}

void		sortfiles(t_params	*params)
{
	t_flags flags; 
	flags = params->flags;
	if (flags.t)
		sort_times(params);
	else
		sortascii(params);
}