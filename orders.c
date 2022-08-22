/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoyano- <jmoyano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:52:07 by jmoyano-          #+#    #+#             */
/*   Updated: 2022/08/22 18:03:01 by jmoyano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stk **stk)
{
	int		i;
	int		j;
	int		indx;

	if ((*stk) && (*stk)->nxt)
	{
		i = (*stk)->num;
		j = (*stk)->nxt->num;
		indx = (*stk)->index;
		(*stk)->index = (*stk)->nxt->index;
		(*stk)->nxt->index = indx;
		(*stk)->num = j;
		(*stk)->nxt->num = i;
	}
}

void	push(t_stk **giver, t_stk **receiver, t_stk *tmp)
{
	tmp = NULL;
	if (*receiver == NULL && *giver)
	{
		*receiver = (t_stk *)malloc(sizeof(t_stk));
		(*receiver)->prv = NULL;
		(*receiver)->num = (*giver)->num;
		(*receiver)->index = (*giver)->index;
		(*receiver)->nxt = NULL;
		(*giver) = (*giver)->nxt;
		(*giver)->prv = NULL;
	}
	else
	{
		if (*giver)
		{
			tmp = (t_stk *)malloc(sizeof(t_stk));
			tmp->num = (*giver)->num;
			tmp->index = (*giver)->index;
			tmp->nxt = NULL;
			tmp->prv = NULL;
			add_top(receiver, tmp);
			(*giver) = (*giver)->nxt;
		}
	}
}

t_stk	*get_to_bottom(t_stk *stk)
{
	t_stk	*tmp;

	tmp = stk;
	while ((tmp)->nxt)
		(tmp) = (tmp)->nxt;
	return (tmp);
}
