#include "push_swap.h"
#include <stdlib.h>

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	free_stack(t_info *info)
{
	t_stack	*tmp;

	while (info->top_copy_a)
	{
		tmp = info->top_copy_a;
		info->top_copy_a = tmp->next;
		free(tmp);
		tmp = NULL;
	}
	info->top_copy_a = NULL;
	info->bottom_copy_a = NULL;
	while (info->top_a)
	{
		tmp = info->top_a;
		info->top_a = tmp->next;
		free(tmp);
		tmp = NULL;
	}
	info->top_a = NULL;
	info->bottom_a = NULL;
	free(info);
}
