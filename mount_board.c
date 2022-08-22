/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mount_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoyano- <jmoyano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:08:29 by jmoyano-          #+#    #+#             */
/*   Updated: 2022/08/22 18:02:43 by jmoyano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_board	*mount_board(t_board *b)
{
	b = (t_board *)malloc(sizeof(t_board));
	if (!b)
		error_display();
	b->a = NULL;
	b->b = NULL;
	b->len = 0;
	b->line = NULL;
	b->split = NULL;
	b->print = 0;
	return (b);
}
