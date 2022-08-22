/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoyano- <jmoyano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 09:24:02 by jmoyano-          #+#    #+#             */
/*   Updated: 2022/08/22 18:46:05 by jmoyano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stk	*get_next_min(t_stk **stack)
{
	t_stk	*tmp;
	t_stk	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	tmp = *stack;
	if (tmp)
	{
		while (tmp)
		{
			if ((tmp->index == -1) && (!has_min || tmp->num < min->num))
			{
				min = tmp;
				has_min = 1;
			}
			tmp = tmp->nxt;
		}
	}
	return (min);
}

void	index_stack(t_stk **stack)
{
	t_stk	*tmp;
	int		index;

	index = 0;
	tmp = get_next_min(stack);
	while (tmp)
	{
		tmp->index = index++;
		tmp = get_next_min(stack);
	}
}

static int	get_max_bits(t_stk **stack)
{
	t_stk	*tmp;
	int		max;
	int		max_bits;

	tmp = *stack;
	max = tmp->index;
	max_bits = 0;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->nxt;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stk **a, t_stk **b, t_board *board)
{
	t_stk	*top_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	top_a = *a;
	size = list_size(top_a);
	max_bits = get_max_bits(a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			top_a = *a;
			if (((top_a->index >> i) & 1) == 1)
				smart_selector_a(a, b, board, top_a->num);
			else
				select_action(a, b, 4, board);
		}
		while (list_size(*b) != 0)
			select_action(a, b, 3, board);
		i++;
	}
}
