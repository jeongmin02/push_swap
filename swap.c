/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerhee <jerhee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:08:47 by jerhee            #+#    #+#             */
/*   Updated: 2023/01/28 15:08:47 by jerhee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
