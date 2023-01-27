#include "push_swap.h"
#include <unistd.h>

void	sa(t_info *info)
{
	int	tmp;

	tmp = info->top_a->num;
	info->top_a->num = info->top_a->next->num;
	info->top_a->next->num = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_info *info)
{
	int	tmp;

	tmp = info->top_b->num;
	info->top_b->num = info->top_b->next->num;
	info->top_b->next->num = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_info *info)
{
	int	tmp;

	tmp = info->top_a->num;
	info->top_a->num = info->top_a->next->num;
	info->top_a->next->num = tmp;
	tmp = info->top_b->num;
	info->top_b->num = info->top_b->next->num;
	info->top_b->next->num = tmp;
	write(1, "ss\n", 3);
}
