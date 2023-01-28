#include "push_swap.h"

static void	a_to_b(t_info *info, int num, int chunk)
{
	while (info->size_a > 0)
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
	}
}

static int	find_b(t_info *info, int num)
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

static void	sort_b(t_info *info, int num)
{
	while (num > 0 && num < info->size_b)
	{
		if (num <= info->size_b / 2)
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

static void	b_to_a(t_info *info)
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
	int	chunk;

	if (info->size_a < 6)
	{
		hard_sort(info);
		return ;
	}
	else if (info->size_a < 500)
		chunk = 15;
	else if (info->size_a < 1000)
		chunk = 30;
	else if (info->size_a < 2000)
		chunk = 45;
	else if (info->size_a < 5000)
		chunk = 60;
	else
		chunk = 150;
	a_to_b(info, 0, chunk);
	b_to_a(info);
}
