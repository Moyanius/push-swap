/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoyano- <jmoyano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 09:49:25 by jmoyano-          #+#    #+#             */
/*   Updated: 2022/08/22 18:03:37 by jmoyano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smart_selector(t_stk **a, t_stk **b, t_board *board, int min)
{
	int	i;
	int	num;

	i = search_base((*a), min, 1);
	num = (list_size((*a)) / 2);
	if (num > i)
		select_action(a, b, 5, board);
	else
		select_action(a, b, 7, board);
}

void	sort_over_3(t_stk **a, t_stk **b, int len, t_board *board)
{
	int		i;
	int		min;
	t_stk	*tmp1;

	i = len;
	while (i > 3)
	{
		min = search_min(*a);
		tmp1 = (*a)->nxt;
		if ((*a)->num != min && tmp1 && tmp1->num == min)
			select_action(a, b, 1, board);
		while (min != (*a)->num)
			smart_selector(a, b, board, min);
		if (min == (*a)->num)
		{
			select_action(a, b, 4, board);
			i--;
		}
	}
}

void	sort_3_actions(t_stk **a, t_stk **b, int act, t_board *board)
{
	select_action(a, b, 1, board);
	select_action(a, b, act, board);
}

void	sort_3(t_stk **a, t_stk **b, int len, t_board *board)
{
	t_stk	*tmp;
	int		min;

	tmp = get_to_bottom(*a);
	min = search_min(*a);
	while (sort_checker(a, len) == 0)
	{
		if ((*a)->num < (*a)->nxt->num && tmp->num == min)
			select_action(a, b, 7, board);
		else if ((*a)->num > (*a)->nxt->num && tmp->num == min)
			sort_3_actions(a, b, 7, board);
		else if ((*a)->nxt->num == min)
		{
			if ((*a)->num < tmp->num)
				select_action(a, b, 1, board);
			else if ((*a)->num > tmp->num)
				select_action(a, b, 5, board);
		}
		else if ((*a)->num == min && (*a)->nxt->num > tmp->num)
			sort_3_actions(a, b, 5, board);
	}
}
