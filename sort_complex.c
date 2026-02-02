/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borabi <bilal.orabi@learner.42.tech>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:35:54 by borabi            #+#    #+#             */
/*   Updated: 2026/01/15 13:05:55 by borabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits_needed(t_stack *stack)
{
	int	max_index;
	int	bits;

	max_index = stack->size - 1;
	bits = 0;
	while (max_index > 0)
	{
		max_index >>= 1;
		bits++;
	}
	return (bits);
}

static int	has_bit_set(int index, int bit_position)
{
	return ((index >> bit_position) & 1);
}

static void	sort_by_bit(t_data *data, int bit_position)
{
	int	size;
	int	i;

	size = data->a->size;
	i = 0;
	while (i < size)
	{
		if (has_bit_set(data->a->top->index, bit_position))
			ra(data, 1);
		else
			pb(data, 1);
		i++;
	}
	while (data->b->size > 0)
		pa(data, 1);
}

void	sort_complex(t_data *data)
{
	int	max_bits;
	int	bit;

	if (stack_is_sorted(data->a))
		return ;
	if (data->a->size <= 5)
		return (sort_simple(data));
	max_bits = get_max_bits_needed(data->a);
	bit = 0;
	while (bit < max_bits)
	{
		sort_by_bit(data, bit);
		bit++;
	}
}
