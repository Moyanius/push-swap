/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoyano- <jmoyano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 09:50:41 by jmoyano-          #+#    #+#             */
/*   Updated: 2022/08/22 18:26:37 by jmoyano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*fill_stack(t_board *b, char **split, t_stk *tmp)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		tmp = malloc(sizeof(t_stk));
		if (!tmp)
			return (NULL);
		tmp->num = ft_atoll(split[i]);
		tmp->index = -1;
		tmp->nxt = NULL;
		tmp->prv = NULL;
		add_bottom(&b->a, tmp);
		tmp = NULL;
	}
	tmp = b->a;
	index_stack(&tmp);
	b->a = tmp;
	return (b->a);
}
