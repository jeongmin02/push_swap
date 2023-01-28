#include "push_swap.h"

int	a_to_b(t_info *info, int num, int chunk)
{
	int	i;
	int	stack_a_size;

	i = 0;
	stack_a_size = info->size_a;
	while (i < stack_a_size)
	{
		if (info->top_a->num <= num)
		{
			pb(info);
			num++;
		}
		else if (info->top_a->num > num && info->top_a->num <= num + chunk)
		{
			pb(info);
			rb(info);
			num++;
		}
		else if (info->top_a->num > num + chunk)
		{
			if (info->bottom_a->num <= num + chunk)
				rra(info);
			else
				ra(info);
		}
		i++;
	}
	return (num);
}

int	find_b(t_info *info, int num)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = info->top_b;
	while (tmp)
	{
		if (tmp->num == num)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	sort_b(t_info *info, int num)
{
	int		b_stack_size;

	b_stack_size = info->size_b;
	while (num > 0 && num < b_stack_size)
	{
		if (num <= b_stack_size / 2)
		{
			rb(info);
			num--;
		}
		else
		{
			rrb(info);
			num++;
		}
	}
}

void	b_to_a(t_info *info)
{
	int	num;
	int	i;

	i = info->size_b - 1;
	while (i >= 0)
	{
		num = find_b(info, i);
		sort_b(info, num);
		pa(info);
		i--;
	}
}

void	sand_watch(t_info *info)
{
	int	num;
	int	chunk;
	int	stack_a_size;

	stack_a_size = info->size_a;
	if (stack_a_size < 6)
	{
		hard_sort(info);
		return ;
	}
	else if (stack_a_size < 500)
		chunk = 15;
	else if (stack_a_size < 1000)
		chunk = 30;
	else if (stack_a_size < 2000)
		chunk = 45;
	else if (stack_a_size < 5000)
		chunk = 60;
	else
		chunk = 150;
	num = 0;
	while (num < stack_a_size)
		num = a_to_b(info, num, chunk);
	b_to_a(info);
}
