/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoyano- <jmoyano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:04:41 by jmoyano-          #+#    #+#             */
/*   Updated: 2022/08/22 19:07:21 by jmoyano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>
# include "Moyano_library/libft.h"

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*nxt;
	struct s_stack	*prv;
}	t_stk;

typedef struct s_board
{
	char	*line;
	char	**split;
	char	**av;
	int		ac;
	int		len;
	int		print;
	int		color;
	int		fd;
	t_stk	*a;
	t_stk	*b;
}	t_board;

void		error_display();
void		check_dup(char **argv);
int			check_numbers(char **argv);
long long	ft_atoll(const char *str);

t_board		*mount_board(t_board *b);
t_stk		*fill_stack(t_board *b, char **split, t_stk *tmp);
void		index_stack(t_stk **stack);

t_stk		*sorter(t_stk *stk);
int			sort_checker(t_stk **a, int len);
void		short_sort(t_board *board, t_stk **a, t_stk **b, int len);
void		sort_3(t_stk **a, t_stk **b, int len, t_board *board);
void		sort_3_actions(t_stk **a, t_stk **b, int act, t_board *board);
void		smart_selector(t_stk **a, t_stk **b, t_board *board, int min);
void		sort_over_3(t_stk **a, t_stk **b, int len, t_board *board);
void		long_sort(t_stk **a, t_stk **b, int len, t_board *board);
void		radix_sort(t_stk **a, t_stk **b, t_board *board);

int			list_size(t_stk *a);
void		add_bottom(t_stk **top, t_stk *new);
void		add_top(t_stk **top, t_stk *new);
void		add_exs(t_stk **stk);
t_stk		*get_to_bottom(t_stk *stk);
void		free_bottom(t_stk **stk);
int			lst_nbr(t_stk **stk, int base);
t_stk		*dup_stk(t_stk *stk);

int			search_min(t_stk *stk);
int			search_max(t_stk *stk);
int			search_pivot(t_stk *stk);
int			search_base(t_stk *stk, int num, int option);
int			ftoi(float num);

void		select_action(t_stk **a, t_stk **b, int act, t_board *board);
void		smart_selector_a(t_stk **a, t_stk **b, t_board *board, int pivot);
void		smart_selector_b(t_stk **a, t_stk **b, t_board *board, int pivot);
void		push(t_stk **a, t_stk **b, t_stk *tmp);
void		swap(t_stk **stk);
void		nbr_swap(t_stk *a, t_stk *b);
void		r(t_stk **stk);
void		rr(t_stk **stk, t_stk *tmp);
t_stk		*rr_swap(t_stk *stk, t_stk *tmp);

void		free_stk(t_stk **stk);
void		int_validation(int total_arg, char **nums);

#endif