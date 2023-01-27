#include "push_swap.h"

void	sort_a(t_info *info)
{
	int	a;
	int	b;
	int	c;

	a = info->top_a->num;
	b = info->top_a->next->num;
	c = info->top_a->next->next->num;
	if ((a < c && c < b) || (b < c && c < a))
		ra(info);
	if ((a < c && c < b) || (b < a && a < c) || (c < b && b < a))
		sa(info);
	if ((a < c && c < b) || (c < a && a < b) || (c < b && b < a))
		rra(info);
}

void	hard_sort(t_info *info)
{
	t_stack	*tmp;
	int		stack_a_size;

	tmp = info->top_a;
	stack_a_size = info->size_a;
	while (info->top_a && info->size_a > 3)
	{
		if (info->top_a->num < ((stack_a_size - 1) / 2))
			pb(info);
		else
			ra(info);
	}
	sort_a(info);
	if (stack_a_size > 3)
	{
		tmp = info->top_b;
		if (info->size_b > 1)
		{
			if (tmp->num < tmp->next->num)
				sb(info);
			pa(info);
		}
		pa(info);
	}
}
