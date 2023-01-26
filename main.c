#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

t_info	*ft_info_new()
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
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

void	test_print(t_info *info)
{
	t_stack	*tmp;

	tmp = info->top_a;
	printf("A | ");
	while (tmp)
	{
		printf("%d ", tmp->num);
		tmp = tmp->next;
	}
	printf("\n");
	tmp = info->top_b;
	printf("B | ");
	while (tmp)
	{
		printf("%d ", tmp->num);
		tmp = tmp->next;
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	t_info	*info;

	if (argc < 2)
		print_error(-1);
	info = ft_info_new();
	check_argv(argv);
	fill_stack(argv, info);
	sort_stack(info);
	indexing_sort_stack(info);
	sand_watch(info);
	test_print(info);
	return (0);
}