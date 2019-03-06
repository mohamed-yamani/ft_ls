/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manageArgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myamani <myamani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:15:37 by myamani           #+#    #+#             */
/*   Updated: 2019/02/27 18:22:02 by myamani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_ls.h"

int		ft_isvalid(char c)
{
	if (!(strchr("-lartR",c) != NULL))
		return(1);
	return (0);
}

void	ft_getflags(char *argv,t_flags *flags)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (ft_isvalid(argv[i]))
	    {
			ft_putendl("ls: illegal option -- - \nusage: ls [-lartR] [file ...]");
			exit(1);
		}
		flags->a = (argv[i] == 'a') ? 1 : flags->a;
		flags->r = (argv[i] == 'r') ? -1 : flags->r;
		flags->l = (argv[i] == 'l') ? 1 : flags->l;
		flags->t = (argv[i] == 't') ? 1 : flags->t;
		flags->gr = (argv[i] == 'R') ? 1 : flags->gr;
		i++;
	}
}

void	initial_stc(t_flags *flags)
{
	flags->a = 0;
	flags->l = 0;
	flags->t = 0;
	flags->r = 1;
	flags->gr = 0;
}

void	ft_add_arg(char *name, t_params *params)
{
	t_args	*arg;
	t_list	*list;

	arg = (t_args *)malloc(sizeof(t_args));
	arg->name = ft_strdup(name);
	arg->type = verify_type(name, params->flags.l);
	list = ft_lstnew(arg);
	ft_lstadd(&params->args, list);
}

void	manageArg(int argc, char **argv, t_params *params)
{
	int 	i;
	int		stop;
	
	i = 0;
	initial_stc(&params->flags);
	stop = 0;
	while (++i < argc)
	{
		if (!ft_strcmp("--", argv[i]))
		{
			stop = 1;
			continue ;
		}
		if (!stop && argv[i][0] == '-')
			ft_getflags(argv[i], &params->flags);
		else
		{
			stop = 1;
			ft_add_arg(argv[i], params);
		}
	}
	if (argv[i - 1][0] == '-' || argc == 1)
		ft_add_arg(".", params);
}
