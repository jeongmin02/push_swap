#include "push_swap.h"

void	a_to_b(t_info *info, int num, int chunk)
{
	int	i;
	int	stack_a_size;

	i = 0;
	stack_a_size = info->size_a;
	while (i < stack_a_size)
	{
		if (info->top_a->num <= num)
			pb(info);
		else if (info->top_a->num > num && info->top_a->num <= num + chunk)
		{
			pb(info);
			rb(info);
		}
		else if (info->top_a->num > num + chunk)
			ra(info);
		i++;
	}
}

void	sort_b(t_info *info, int num)
{
	int		i;
	int		b_stack_size;
	t_stack	*tmp;

	i = 0;
	b_stack_size = info->size_b;
	tmp = info->top_b;
	while (tmp->num != num)
	{
		tmp = tmp->next;
		i++;
	}
	while (i > 0 && i < b_stack_size)
	{
		if (i <= b_stack_size / 2)
		{
			rb(info);
			i--;
		}
		else
		{
			rrb(info);
			i++;
		}
	}
}

void	b_to_a(t_info *info)
{
	int	i;

	i = info->size_b - 1;
	while (i >= 0)
	{
		sort_b(info, i);
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
	if (stack_a_size < 500)
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
	{
		a_to_b(info, num, chunk);
		num += chunk;
	}
	b_to_a(info);
}