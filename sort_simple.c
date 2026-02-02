/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borabi <bilal.orabi@learner.42.tech>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:35:40 by borabi            #+#    #+#             */
/*   Updated: 2026/01/15 14:49:11 by borabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_all_back(t_data *data)
{
	while (data->b->size > 0)
		pa(data, 1);
}

void	sort_simple(t_data *data)
{
	int	size;
	int	min_pos;
	int	i;

	if (stack_is_sorted(data->a))
		return ;
	size = data->a->size;
	if (size == 2)
		return (sort_two(data));
	if (size == 3)
		return (sort_three(data));
	i = 0;
	while (i < size)
	{
		min_pos = get_position(data->a, stack_min_index(data->a));
		rotate_to_top(data, data->a, min_pos, 'a');
		pb(data, 1);
		i++;
	}
	push_all_back(data);
}
