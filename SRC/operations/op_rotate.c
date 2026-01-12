/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borabi <bilal.orabi@learner.42.tech>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:18:48 by borabi            #+#    #+#             */
/*   Updated: 2026/01/04 20:18:48 by borabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate_stack(t_stack *stack)
{
	t_node *first;
	
	if(!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	stack->top->prev = NULL;
	first->next = NULL;
	first->prev = stack->bottom;
	stack->bottom->next = first;
	stack->bottom = first;
}

void ra(t_data *data, int does_print)
{
	rotate_stack(data->a);
	if (does_print)
		write(1,"ra\n", 3);
	data->bench.ra++;
	data->bench.total++;
}

void rb(t_data *data, int does_print)
{
	rotate_stack(data->b);
	if (does_print)
		write(1,"rb\n", 3);
	data->bench.rb++;
	data->bench.total++;
}

void rr(t_data *data, int does_print)
{
	rotate_stack(data->a);
	rotate_stack(data->b);
	if (does_print)
		write(1,"rr\n", 3);
	data->bench.rr++;
	data->bench.total++;
}