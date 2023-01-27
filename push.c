#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	pa(t_info *info)
{
	t_stack	*tmp;

	if (info->size_b < 1)
		return;
	tmp = info->top_b;
	info->top_b = info->top_b->next;
	if (info->size_a == 0)
	{
		if (info->size_b > 1)
			tmp->next = NULL;
		info->top_a = tmp;
		info->bottom_a = tmp;
	}
	else
	{
		tmp->next = info->top_a;
		info->top_a = tmp;
	}
	info->size_a += 1;
	info->size_b -= 1;
	write(1, "pa", 2);
	write(1, "\n", 1);
	// test_print(info);
}

void	pb(t_info *info)
{
	t_stack	*tmp;

	if (info->size_a < 1)
		return;
	tmp = info->top_a;
	info->top_a = info->top_a->next;
	if (info->size_b == 0)
	{
		if (info->size_a > 1)
			tmp->next = NULL;
		info->top_b = tmp;
		info->bottom_b = tmp;
	}
	else
	{
		tmp->next = info->top_b;
		info->top_b = tmp;
	}
	info->size_b += 1;
	info->size_a -= 1;
	write(1, "pb", 2);
	write(1, "\n", 1);
	// test_print(info);
}