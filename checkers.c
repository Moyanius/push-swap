/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoyano- <jmoyano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:15:37 by jmoyano-          #+#    #+#             */
/*   Updated: 2022/08/22 19:10:46 by jmoyano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoll(const char *str)
{
	int			sign;
	long long	int_to_return;
	int			i;

	i = 0;
	sign = 1;
	int_to_return = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		int_to_return = (int_to_return * 10) + (str[i] - '0');
		i++;
	}
	int_to_return *= sign;
	return (int_to_return);
}

int	check_int(char *argv)
{
	long	tmp;

	tmp = ft_atoll(argv);
	if (tmp >= INT_MAX && tmp <= INT_MIN && ft_strlen(argv) < 12)
		return (1);
	return (0);
}

int	check_numbers(char **argv)
{
	int	i;
	int	j;

	i = -1;
	if (!argv[0])
		error_display();
	while (argv[++i])
	{
		j = -1;
		if (check_int(argv[i]) == 1)
			error_display();
		while (argv[i][++j])
		{
			if (ft_isalpha(argv[i][j]) == 1 || argv[i][j] == '.'
			|| ((argv[i][j]) == '-' && (argv[i][j +1]) == '\0')
			|| ((argv[i][j]) == '+' && (argv[i][j + 1]) == '\0'))
				error_display();
		}
	}
	return (1);
}

int	sort_checker(t_stk **a, int len)
{
	t_stk	*tmp;

	if (list_size(*a) != len)
		return (0);
	tmp = *a;
	while (tmp && tmp->nxt)
	{
		if ((tmp)->nxt != NULL && ((tmp)->num < (tmp)->nxt->num))
			(tmp) = tmp->nxt;
		else
			return (0);
	}
	return (1);
}

void	check_dup(char **argv)
{
	int		i;
	int		j;
	char	*dup;

	i = 0;
	while (argv[i])
	{
		dup = ft_strdup(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			if (j == 0)
				j++;
			else if (ft_strcmp(dup, argv[j]) == 0)
			{
				free(dup);
				error_display();
			}
			else
				j++;
		}
		free(dup);
		dup = NULL;
		i++;
	}
}
