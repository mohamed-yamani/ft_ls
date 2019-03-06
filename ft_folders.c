/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_folders.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <myamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 11:03:50 by myamani           #+#    #+#             */
/*   Updated: 2019/03/05 21:52:20 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_ls.h"

void	ft_readdir(char *folder, DIR *dir, t_params *params)
{
	struct dirent *entry;
	char	*file1;
	char	*file2;
	t_file	*filep;

	file1 = ft_strjoin(folder, "/");
	while ((entry = readdir(dir)))
	{
		file2 = ft_strjoin(file1, entry->d_name);
		get_stat(file2, params);
		filep = ((t_file *)params->files->content);
		free(filep->name);
		filep->name = ft_strdup(entry->d_name);
		free(file2);
	}
	free(file1);
}

void	ft_opendir(char *name, t_params *params)
{
	DIR		*dir;
	t_file	*file;
	char	*path;
	t_list	*tmp;

	if ((dir = opendir(name)))
	{
		ft_readdir(name, dir, params);
		sortfiles(params);
		ft_print(params);
		while (params->flags.gr && params->files)
		{
			file = (t_file *)params->files->content;
			if (file->is_dir && ft_strcmp(file->name, ".") && ft_strcmp(file->name, ".."))
			{
				tmp = params->files;
				path = ft_strjoin(name, "/");
				path = ft_strjoin(path, file->name);
				params->files = NULL;
				ft_opendir(path, params);
				params->files = tmp;
			}
			params->files = params->files->next;
		}
	}
	else
		perror("ft_ls ");
}

void	ft_folders(t_params *params)
{
	t_list	*args;
	t_args	*arg;


	args = params->args;
	while (args)
	{
		arg = (t_args *)args->content;
		params->files = NULL;
		if (arg->type)
		{
			ft_opendir(arg->name, params);
		}
		args = args->next;
	}
}