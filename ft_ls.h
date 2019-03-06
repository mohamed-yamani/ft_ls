/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <myamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 20:01:34 by myamani           #+#    #+#             */
/*   Updated: 2019/03/05 18:43:59 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H


# include <stdio.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/stat.h>
# include "libft/libft.h"
# include <pwd.h>
# include <grp.h>
# include <time.h>

typedef struct	s_args
{
	char		*name;
	char		*chemain;
	int			type;
	int			num_args;
}				t_args;
typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
typedef struct	s_flags
{
	int		a;
	int		l;
	int		t;
	int		r;
	int		gr;
	int		ttl;
	int		index;
}				t_flags;
typedef struct	s_file
{
	char	*name;
	char	*chemain;
	char	*dir;
	mode_t  mode;
	char	*user_name;
	char 	*group_name;
	char	*month;
	char	*day;
	char	*hour;
	char	*year;
	int		size;
	int		nlink;
	int		time;
	int		m_time;
	int		is_dir;
}				t_file;
typedef struct	s_params
{
	t_list		*files;
	t_flags		flags;
	t_list		*args;
}				t_params;
void		manageArg(int argc, char **argv, t_params *params);
void		getfiles(t_params *params);
int			verify_type(char *name ,int l_flag);
t_list		*ft_lstnew(void *content);
void		ft_lstadd(t_list **list, t_list *newl);
void		get_stat(char *file, t_params *params);
void		ft_folders(t_params *params);
void		ft_print(t_params	*params);
void		sortfiles(t_params *params);
void 		sort_args(t_params *params);
#endif

