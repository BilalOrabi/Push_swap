/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borabi <bilal.orabi@learner.42.tech>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:35:18 by borabi            #+#    #+#             */
/*   Updated: 2026/01/09 19:35:18 by borabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_data *data)
{
	if (data->a->top->index > data->a->top->next->index)
		sa(data, 1);
}
void	sort_three(t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->a->top->index;
	b = data->a->top->next->index;
	c = data->a->bottom->index;
	if(a > b && b < c && a < c)
		sa(data, 1);
	else if(a > b && b > c)
	{
		sa(data, 1);
		rra(data, 1);
	}
	else if(a > b && b < c && a > c)
		ra(data, 1);
	else if(a < b && b > c && a < c)
	{
		sa(data, 1);
		ra(data, 1);
	}
	else if(a < b && b > c && a > c)
		rra(data, 1);
}

void	sort_four(t_data *data)
{
	int min_pos;

	min_pos = get_position(data->a, stack_min_index(data->a));
	rotate_to_top(data, data->a, min_pos, 'a');
	pb(data, 1);
	sort_three(data);
	pa(data, 1);
}

void	sort_five(t_data *data)
{
	int min_pos;

	min_pos = get_position(data->a, stack_min_index(data->a));
	rotate_to_top(data, data->a, min_pos, 'a');
	pb(data, 1);
	min_pos = get_position(data->a, stack_min_index(data->a));
	rotate_to_top(data, data->a, min_pos, 'a');
	pb(data, 1);
	sort_three(data);
	pa(data, 1);
	pa(data, 1);
}