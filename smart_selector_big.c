/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_selector_big.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoyano- <jmoyano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:31:52 by jmoyano-          #+#    #+#             */
/*   Updated: 2022/08/22 18:03:28 by jmoyano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smart_selector_a(t_stk **a, t_stk **b, t_board *board, int pivot)
{
	int	base;
	int	num;

	base = search_base((*a), pivot, 1);
	num = (list_size((*a)) / 2);
	if (base < num)
		select_action(a, b, 5, board);
	else
		select_action(a, b, 7, board);
}

void	smart_selector_b(t_stk **a, t_stk **b, t_board *board, int pivot)
{
	int	base;
	int	num;

	base = search_base((*b), pivot, 2);
	num = ftoi((list_size((*b)) / 2));
	if (base < num && *b)
		select_action(a, b, 6, board);
	else
		select_action(a, b, 8, board);
}
