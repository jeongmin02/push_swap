/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:08:41 by jerhee            #+#    #+#             */
/*   Updated: 2023/01/28 15:08:41 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	ra(t_info *info)
{
	t_stack	*tmp;

	if (info->size_a < 2)
		return ;
	tmp = info->top_a;
	info->top_a = info->top_a->next;
	info->bottom_a->next = tmp;
	info->bottom_a = tmp;
	info->bottom_a->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_info *info)
{
	t_stack	*tmp;

	if (info->size_b < 2)
		return ;
	tmp = info->top_b;
	info->top_b = info->top_b->next;
	info->bottom_b->next = tmp;
	info->bottom_b = tmp;
	info->bottom_b->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_info *info)
{
	t_stack	*tmp;

	if (info->size_a < 2 || info->size_b < 2)
		return ;
	tmp = info->top_a;
	info->top_a = info->top_a->next;
	info->bottom_a->next = tmp;
	info->bottom_a = tmp;
	info->bottom_a->next = NULL;
	tmp = info->top_b;
	info->top_b = info->top_b->next;
	info->bottom_b->next = tmp;
	info->bottom_b = tmp;
	info->bottom_b->next = NULL;
	write(1, "rr\n", 3);
}
