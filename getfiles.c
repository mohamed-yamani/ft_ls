/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getfiles.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <myamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 11:03:50 by myamani           #+#    #+#             */
/*   Updated: 2019/03/05 18:45:12 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_ls.h"


int		verify_type(char *name ,int l_flag)
 {
	struct stat stt;

	if (l_flag && (!lstat(name, &stt)))
		return ((S_ISDIR(stt.st_mode)) ? 1 : 0);
	else if (!l_flag && !stat(name, &stt))
		return ((S_ISDIR(stt.st_mode)) ? 1 : 0);
	return (0);
}

void	get_date(char *date, t_file *fileparams)
{ 
	char **splite_space;
	char **splite_points;

	fileparams->hour = (char *)malloc(sizeof(char) * 3);
	splite_space = ft_strsplit(date, ' ');
	fileparams->month = splite_space[1];
	fileparams->day = splite_space[2];
	splite_points = ft_strsplit(splite_space[3], ':');
	fileparams->hour = splite_points[0];
	fileparams->hour = ft_strcat(fileparams->hour, ":");
	fileparams->hour = ft_strcat(fileparams->hour, splite_points[1]);	
	fileparams->year = splite_space[4];
}

void	get_stat2(t_file *fileparams, struct stat filestat)
{
	struct passwd *usr;
	struct group *grp;

	grp = getgrgid(filestat.st_gid);
	usr = getpwuid(filestat.st_uid);
	fileparams->user_name = usr->pw_name;
	fileparams->group_name = grp->gr_name;
	fileparams->size = filestat.st_size;
	fileparams->mode = filestat.st_mode;
	fileparams->nlink = filestat.st_nlink;
	fileparams->time = filestat.st_mtime;
	fileparams->is_dir = S_ISDIR(filestat.st_mode) ? 1 : 0;
	//fileparams->m_time = filestat.st_mtimespec.tv_sec;
	get_date(ctime(&filestat.st_mtime), fileparams);
}

void	get_stat(char *file, t_params *params)
{
	struct stat filestat;
	t_list	*list;
	t_file	*fileparams;

	if (!lstat(file, &filestat))
	{
		fileparams = (t_file *)malloc(sizeof(t_file));
		fileparams->name = ft_strdup(file);
		get_stat2(fileparams, filestat);
		list = ft_lstnew(fileparams);
		ft_lstadd(&params->files, list);
	}
}

void	getfiles(t_params *params)
{
	struct stat filestat;
	t_list	*args;
	t_args	*arg;

	args = params->args;
	while (args)
	{
		arg = (t_args *)args->content;
		if (!arg->type)
		{
			if (!lstat(arg->name, &filestat))
			{
				get_stat(arg->name, params);
			}
			else
				printf("error : %s\n", arg->name);
		}
		args = args->next;
	}
	sortfiles(params);
}
