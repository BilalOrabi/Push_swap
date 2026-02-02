/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borabi <bilal.orabi@learner.42.tech>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:35:50 by borabi            #+#    #+#             */
/*   Updated: 2026/01/15 14:49:08 by borabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_from_top(t_data *data, int low, int high)
{
	t_node	*node;
	int		pos;

	pos = 0;
	node = data->a->top;
	while (node)
	{
		if (node->index >= low && node->index <= high)
			return (pos);
		pos++;
		node = node->next;
	}
	return (data->a->size);
}

static int	find_from_bottom(t_data *data, int low, int high)
{
	t_node	*node;
	int		pos;

	pos = 1;
	node = data->a->bottom;
	while (node)
	{
		if (node->index >= low && node->index <= high)
			return (pos);
		pos++;
		node = node->prev;
	}
	return (data->a->size);
}

static void	push_to_b(t_data *data)
{
	int	range;
	int	pushed;
	int	top_dst;
	int	bottom_dst;

	range = get_range(data->a->size);
	pushed = 0;
	while (data->a->size > 0)
	{
		top_dst = find_from_top(data, (pushed - range), (pushed + range));
		bottom_dst = find_from_bottom (data, (pushed - range),
				(pushed + range));
		if (top_dst <= bottom_dst)
			while (top_dst-- > 0)
				ra(data, 1);
		else
			while (bottom_dst-- > 0)
				rra(data, 1);
		pb(data, 1);
		if (data->b->size > 1 && data->b->top->index < pushed)
			rb(data, 1);
		pushed++;
	}
}

static void	push_back_to_a(t_data *data)
{
	int	pos;
	int	size;

	while (data->b->size > 0)
	{
		pos = get_position(data->b, stack_max_index(data->b));
		size = data->b->size;
		if (pos <= (size / 2))
			while (pos-- > 0)
				rb(data, 1);
		else
			while (pos++ < size)
				rrb(data, 1);
		pa(data, 1);
	}
}

void	sort_medium(t_data *data)
{
	if (stack_is_sorted(data->a))
		return ;
	if (data->a->size <= 5)
	{
		sort_simple(data);
		return ;
	}
	push_to_b(data);
	push_back_to_a(data);
}
