/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoyano- <jmoyano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 11:02:50 by jmoyano-          #+#    #+#             */
/*   Updated: 2022/08/22 18:48:12 by jmoyano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**fill_args(t_board *board, char **argv, int argc)
{
	board->fd = 1;
	if (argc == 2)
		board->split = ft_split(argv[1], ' ');
	else
		board->split = &argv[1];
	return (board->split);
}

void	swapping_time(t_board *board, int argc, char **argv)
{
	t_stk	*stk;

	stk = NULL;
	board->split = fill_args(board, argv, argc);
	check_dup(board->split);
	check_numbers(board->split);
	board->a = fill_stack(board, board->split, stk);
	if (sort_checker(&board->a, list_size(board->a)) == 1)
		exit(1);
	board->len = list_size(board->a);
	free_stk(&stk);
	if (board->len <= 10)
		short_sort(board, &(board->a), &(board->b), board->len);
	else if (board->len <= 100)
		long_sort(&(board->a), &(board->b), board->len, board);
	else
		radix_sort(&board->a, &board->b, board);
}

int	main(int argc, char **argv)
{
	t_board	*board;

	board = NULL;
	if (argc < 2)
		exit(1);
	else
	{
		board = mount_board(board);
		swapping_time(board, argc, argv);
		free(board);
	}
}
