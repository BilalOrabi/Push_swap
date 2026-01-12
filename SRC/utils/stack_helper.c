/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borabi <bilal.orabi@learner.42.tech>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:40:46 by borabi            #+#    #+#             */
/*   Updated: 2026/01/05 22:40:46 by borabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_position(t_stack *stack, int index)
{
	t_node *current;
	int position;

	if(!stack || !stack->top)
		return (-1);
	current = stack->top;
	position = 0;
	while (current)
	{
		if (current->index == index)
			return position;
		position++;
		current = current->next;
	}
	return (-1);
}

void rotate_to_top(t_data *data, t_stack *stack, int position, char name)
{
	int size;
	
	size = stack->size;
	if(position <= size / 2)
	{
		while (position-- > 0)
		{
			if (name = 'a')
				ra(data, 1);
			else
				rb(data, 1);
		}
	}
	else
	{
		position = size - position;
		while (position-- > 0)
		{
			if (name = 'a')
				rra(data, 1);
			else
				rrb(data, 1);
		}
	}
}

int ft_sqrt(int n)
{
	int i;
	if (n <= 0)
		return (0);
	i = 1;
	while (i * i <= n)
	{
		i++;
	}
	return (i - 1);
}

int    get_max_bits(t_stack *stack)
{
    int	max_idx;
    int	bits;

    max_idx = stack_max_index(stack);
    bits = 0;
    while ((max_idx >> bits) != 0)
        bits++;
    return (bits);
}