/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:08:23 by jerhee            #+#    #+#             */
/*   Updated: 2023/01/28 15:08:23 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

t_info	*ft_info_new(void)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		print_error(-1);
	info->size_a = 0;
	info->top_a = NULL;
	info->bottom_a = NULL;
	info->size_b = 0;
	info->top_b = NULL;
	info->bottom_b = NULL;
	return (info);
}

void	check_argv(char *argv[])
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isspace(argv[i][j]) && !ft_isdigit(argv[i][j])
				&& !ft_issign(argv[i][j]))
			{
				print_error(1);
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

void	check_duplicate(char *argv[])
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	flag = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				print_error(1);
			else if (ft_atoi(argv[i]) > ft_atoi(argv[j]))
				flag++;
			j++;
		}
		i++;
	}
	if (flag == 0)
		print_error(-1);
	return ;
}

void	print_error(int num)
{
	if (num == 1)
		write(1, "ERROR\n", 6);
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_info	*info;

	if (argc < 2)
		print_error(-1);
	info = ft_info_new();
	check_argv(argv);
	check_duplicate(argv);
	fill_stack(argv, info);
	sort_stack(info);
	indexing_sort_stack(info);
	sand_watch(info);
	free_stack(info);
	return (0);
}
