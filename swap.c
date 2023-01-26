#include "push_swap.h"
#include <unistd.h>

void	sa(t_info *info)
{
	t_stack	*tmp;

	tmp = info->top_a;
	info->top_a = info->top_a->next;
	info->top_a->next = tmp;
	write(1, "sa\n", 3);
	// test_print(info);
}

void	sb(t_info *info)
{
	t_stack	*tmp;

	tmp = info->top_b;
	info->top_b = info->top_b->next;
	info->top_b->next = tmp;
	write(1, "sb\n", 3);
	// test_print(info);
}

void	ss(t_info *info)
{
	t_stack	*tmp;

	tmp = info->top_a;
	info->top_a = info->top_a->next;
	info->top_a->next = tmp;
	tmp = info->top_b;
	info->top_b = info->top_b->next;
	info->top_b->next = tmp;
	write(1, "ss\n", 3);
}