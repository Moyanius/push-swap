/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_act.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoyano- <jmoyano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:33:01 by jmoyano-          #+#    #+#             */
/*   Updated: 2022/08/22 18:26:28 by jmoyano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_size(t_stk *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->nxt;
	}
	return (i);
}

void	free_stk(t_stk **stk)
{
	t_stk	*tmp;

	if (*stk)
	{
		while (*stk)
		{
			tmp = (*stk)->nxt;
			free(*stk);
			*stk = NULL;
			(*stk) = tmp;
		}
		free(*stk);
		*stk = NULL;
	}
}

void	add_bottom(t_stk **top, t_stk *new)
{
	t_stk	*tmp;

	if (*top == NULL)
		*top = new;
	else
	{
		tmp = *top;
		while (tmp->nxt)
			tmp = tmp->nxt;
		tmp->nxt = new;
		new->prv = tmp;
	}
}

void	add_top(t_stk **top, t_stk *new)
{
	new->nxt = (*top);
	new->prv = NULL;
	if ((*top) != NULL)
		(*top)->prv = new;
	(*top) = new;
}

t_stk	*dup_stk(t_stk *stk)
{
	t_stk	*tmp1;
	t_stk	*tmp2;

	tmp1 = ft_calloc(1, sizeof(t_stk));
	tmp2 = tmp1;
	while (stk)
	{
		tmp1->num = stk->num;
		if (stk->nxt)
		{
			tmp1->nxt = ft_calloc(1, sizeof(t_stk));
			tmp1 = tmp1->nxt;
		}
		stk = stk->nxt;
	}
	tmp1 = tmp2;
	return (tmp1);
}
