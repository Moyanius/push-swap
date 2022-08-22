/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoyano- <jmoyano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:30:09 by jmoyano-          #+#    #+#             */
/*   Updated: 2022/08/22 18:24:23 by jmoyano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_pivot(t_stk *a, int pivot, int opt)
{
	while (a)
	{
		if (opt == 1)
		{
			if (a->num <= pivot)
				return (1);
			a = a->nxt;
		}
		if (opt == 2)
		{
			if (a->num == pivot)
				return (1);
			a = a->nxt;
		}
	}
	return (0);
}

void	first_step(t_stk **a, t_stk **b, int len, t_board *board)
{
	int		i;
	int		pivot;
	t_stk	*tmp1;
	t_stk	*tmp2;

	i = len;
	while (i > ftoi(len / 32))
	{
		tmp1 = dup_stk(*a);
		pivot = search_pivot(tmp1);
		while (check_pivot((*a), pivot, 1) && (*a))
		{
			if ((*a)->num <= pivot)
			{
				tmp2 = *a;
				select_action(a, b, 4, board);
				i--;
				free(tmp2);
			}
			else
				smart_selector_a(a, b, board, pivot);
		}
		free_stk(&tmp1);
	}
}

void	second_step(t_stk **a, t_stk **b, int len, t_board *board)
{
	int		min;
	t_stk	*tmp;

	tmp = NULL;
	while (*a && !sort_checker(a, len))
	{
		min = search_min(*a);
		tmp = (*a)->nxt;
		while ((*a)->num != min && tmp && tmp->num == min)
			select_action(a, b, 1, board);
		while (list_size(*a) && check_pivot((*a), min, 1))
		{
			if ((*a)->num == min)
			{
				tmp = *a;
				select_action(a, b, 4, board);
				free(tmp);
				len--;
			}
			else
				smart_selector_a(a, b, board, min);
		}
	}
}

void	third_step(t_stk **a, t_stk **b, int max, t_board *board)
{
	t_stk	*tmp;

	tmp = NULL;
	while (*b)
	{
		max = search_max(*b);
		while (check_pivot((*b), max, 2))
		{
			max = search_max(*b);
			tmp = (*b)->nxt;
			while ((*b)->num != max && tmp && tmp->num == max)
				select_action(a, b, 2, board);
			while (((*b)->num != max) && *b)
				smart_selector_b(a, b, board, max);
			while (*b && (*b)->num == max)
			{
				tmp = *b;
				select_action(a, b, 3, board);
				max = search_max(*b);
				free(tmp);
			}
		}
	}
}

void	long_sort(t_stk **a, t_stk **b, int len, t_board *board)
{
	int	max;

	max = 0;
	first_step(a, b, len, board);
	second_step(a, b, len, board);
	third_step(a, b, max, board);
	free_stk(a);
	free_stk(b);
}
