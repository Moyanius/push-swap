/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoyano- <jmoyano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:13:59 by jmoyano-          #+#    #+#             */
/*   Updated: 2022/08/22 18:02:49 by jmoyano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_nbr(t_stk **stk, int base)
{
	t_stk	*tmp;
	int		i;

	i = 0;
	tmp = *stk;
	while (tmp != NULL)
	{
		if (i == base)
			return (tmp->num);
		i++;
		tmp = tmp->nxt;
	}
	return (1);
}

void	nbr_swap(t_stk *a, t_stk *b)
{
	int	tmp;

	tmp = a->num;
	a->num = b->num;
	b->num = tmp;
}

t_stk	*sorter(t_stk *stk)
{
	t_stk	*base;
	t_stk	*tmp;
	t_stk	*cmp;

	base = NULL;
	base = stk;
	tmp = NULL;
	cmp = NULL;
	while (base->nxt)
	{
		cmp = base;
		tmp = base->nxt;
		while (tmp)
		{
			if (cmp->num > tmp->num)
				cmp = tmp;
			tmp = tmp->nxt;
		}
		nbr_swap(base, cmp);
		base = base->nxt;
	}
	return (stk);
}
