/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:08:39 by jerhee            #+#    #+#             */
/*   Updated: 2023/01/28 15:08:39 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	rra(t_info *info)
{
	t_stack	*tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->top_a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	info->bottom_a->next = info->top_a;
	info->top_a = info->bottom_a;
	info->bottom_a = tmp;
	write(1, "rra\n", 4);
}

void	rrb(t_info *info)
{
	t_stack	*tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->top_b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	info->bottom_b->next = info->top_b;
	info->top_b = info->bottom_b;
	info->bottom_b = tmp;
	write(1, "rrb\n", 4);
}

void	rrr(t_info *info)
{
	t_stack	*tmp;

	if (info->size_a < 2 || info->size_b < 2)
		return ;
	tmp = info->top_a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	info->bottom_a->next = info->top_a;
	info->top_a = info->bottom_a;
	info->bottom_a = tmp;
	tmp = info->top_b;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	info->bottom_b->next = info->top_b;
	info->top_b = info->bottom_b;
	info->bottom_b = tmp;
	write(1, "rrr\n", 4);
}
