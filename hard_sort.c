/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changhle <changhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:08:17 by jerhee            #+#    #+#             */
/*   Updated: 2023/01/28 17:46:34 by changhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	tmp = info->top_a;
	while (info->top_a && info->size_a > 3)
	{
		if (info->top_a->num < info->size_a + info->size_b - 3)
			pb(info);
		else
			ra(info);
	}
	if (info->size_a == 2)
		sa(info);
	else
		sort_a(info);
	if (info->size_b > 0)
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
