#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	rra(t_info *info)
{
	t_stack	*tmp;

	if (info->size_a < 2)
		return;
	tmp = info->bottom_a;
	info->bottom_a->next = NULL;
	tmp->next = info->top_a;
	info->top_a = tmp;
	write(1, "rra\n", 4);
	// test_print(info);
}

void	rrb(t_info *info)
{
	t_stack	*tmp;

	if (info->size_b < 2)
		return;
	tmp = info->bottom_b;
	info->bottom_b->next = NULL;
	tmp->next = info->top_b;
	info->top_b = tmp;
	write(1, "rrb\n", 4);
	// test_print(info);
}

void	rrr(t_info *info)
{
	t_stack	*tmp;

	if (info->size_a < 2)
		return;
	tmp = info->bottom_a;
	info->bottom_a->next = NULL;
	tmp->next = info->top_a;
	info->top_a = tmp;
	if (info->size_b < 2)
		return;
	tmp = info->bottom_b;
	info->bottom_b->next = NULL;
	tmp->next = info->top_b;
	info->top_b = tmp;
	write(1, "rrr\n", 4);
}