/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordering_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoyano- <jmoyano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 12:21:14 by jmoyano-          #+#    #+#             */
/*   Updated: 2022/08/22 18:02:55 by jmoyano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	third_actions(t_stk **a, t_stk **b, int act, t_board *board)
{
	t_stk	*tmp;

	tmp = NULL;
	if (act == 7 && list_size(*a) > 1)
	{
		ft_putstr_fd("rra\n", board->fd);
		rr(a, tmp);
	}
	else if (act == 8 && list_size(*b) > 1)
	{
		ft_putstr_fd("rrb\n", board->fd);
		rr(b, tmp);
		free(tmp);
	}
}

void	second_actions(t_stk **a, t_stk **b, int act, t_board *board)
{
	t_stk	*tmp;

	tmp = NULL;
	if (act == 4)
	{
		ft_putstr_fd("pb\n", board->fd);
		push(a, b, tmp);
		free(tmp);
	}
	else if (act == 5)
	{
		ft_putstr_fd("ra\n", board->fd);
		r(a);
		free(tmp);
	}
	else if (act == 6 && list_size(*b) > 1)
	{
		ft_putstr_fd("rb\n", board->fd);
		r(b);
		free(tmp);
	}
	else
		third_actions(a, b, act, board);
}

void	select_action(t_stk **a, t_stk **b, int act, t_board *board)
{
	t_stk	*tmp;

	tmp = NULL;
	if (act == 1 && list_size(*a) > 1)
	{
		ft_putstr_fd("sa\n", board->fd);
		swap(a);
	}
	else if (act == 2 && list_size(*b) > 1)
	{
		ft_putstr_fd("sb\n", board->fd);
		swap(b);
	}
	else if (act == 3)
	{
		ft_putstr_fd("pa\n", board->fd);
		push(b, a, tmp);
		free(tmp);
	}
	else
		second_actions(a, b, act, board);
}
