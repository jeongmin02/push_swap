#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	fill_stack(char *argv[], t_info *info)
{
	t_stack	*stack_a;
	t_stack *copy_a;
	t_stack	*tmp;
	char	**split_num;
	
	int i;
	int j;

	i = 1;	
	while (argv[i])
	{
		split_num = ft_split(argv[i], ' ');
		j = 0;
		while (split_num[j])
		{
			stack_a = stack_push_a(ft_atoi(split_num[j]), info);
			copy_a = stack_push_copy_a(ft_atoi(split_num[j]), info);
			info->size_a++;
			j++;
		}
		i++;
	}
	// while (info->top_a)
	// {
	// 	printf("%d\n", info->top_a->num);
	// 	info->top_a = info->top_a->next;
	// }
	// printf("------\n");
	// printf("%d\n", info->size_a);
	// while (info->top_sort_a)
	// {
	// 	printf("%d\n", info->top_sort_a->num);
	// 	info->top_sort_a = info->top_sort_a->next;
	// }
}

t_stack	*stack_push_a(int split_num, t_info *info)
{
	t_stack	*stack_a;
	t_stack *tmp;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	stack_a->num = split_num;
	stack_a->next = NULL;
	if (!info->top_a)
	{
		info->top_a = stack_a;
		info->bottom_a = stack_a;
	}
	else
	{
		tmp = info->top_a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = stack_a;
		info->bottom_a = stack_a;
	}
}

t_stack	*stack_push_copy_a(int split_num, t_info *info)
{
	t_stack	*copy_a;
	t_stack *tmp;

	copy_a = (t_stack *)malloc(sizeof(t_stack));
	if (!copy_a)
		return (NULL);
	copy_a->num = split_num;
	copy_a->next = NULL;
	if (!info->top_copy_a)
	{
		info->top_copy_a = copy_a;
		info->bottom_copy_a = copy_a;
	}
	else
	{
		tmp = info->top_copy_a;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = copy_a;
		info->bottom_copy_a = copy_a;
	}
}

void	sort_stack(t_info *info)
{
	t_stack	*s_tmp;
	int		tmp;
	int		i;
	int		j;

	i = 0;
	while (i < info->size_a - 1)
	{
		s_tmp = info->top_copy_a;
		j = 0;
		while (j < info->size_a - 1)
		{
			if (s_tmp->num > s_tmp->next->num)
			{
				tmp = s_tmp->num;
				s_tmp->num = s_tmp->next->num;
				s_tmp->next->num = tmp;
			}
			j++;
			s_tmp = s_tmp->next;
		}
		i++;
	}
	// while (info->top_copy_a)
	// {
	// 	printf("%d\n", info->top_copy_a->num);
	// 	info->top_copy_a = info->top_copy_a->next;
	// }
}

void	indexing_sort_stack(t_info *info)
{
	t_stack	*a_tmp;
	t_stack	*copy_a_tmp;
	int		i;
	int		j;

	i = 0;
	a_tmp = info->top_a;
	while(i < info->size_a)
	{
		copy_a_tmp = info->top_copy_a;
		j = 0;
		while (j < info->size_a)
		{
			if (a_tmp->num == copy_a_tmp->num)
			{
				a_tmp->num = j;
				break;
			}
			j++;
			copy_a_tmp = copy_a_tmp->next;
		}
		a_tmp = a_tmp->next;
		i++;
	}
	free(info->top_copy_a);
	// while (info->top_a)
	// {
	// 	printf("%d\n", info->top_a->num);
	// 	info->top_a = info->top_a->next;
	// }
}