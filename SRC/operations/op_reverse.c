/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borabi <bilal.orabi@learner.42.tech>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 19:32:32 by borabi            #+#    #+#             */
/*   Updated: 2026/01/04 19:32:32 by borabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse_rotate_stack(t_stack *stack)
{
	t_node *last;
	
	if(!stack || stack->size < 2)
		return ;
	last = stack->bottom;
	stack->bottom = last->prev;
	stack->bottom->next = NULL;
	last->prev = NULL;
	last->next = stack->top;
	stack->top->prev = last;
	stack->top = last;
}

void rra(t_data *data, int does_print)
{
	reverse_rotate_stack(data->a);
	if (does_print)
		write(1,"rra\n", 4);
	data->bench.rra++;
	data->bench.total++;
}

void rrb(t_data *data, int does_print)
{
	reverse_rotate_stack(data->b);
	if (does_print)
		write(1,"rrb\n", 4);
	data->bench.rrb;
	data->bench.total++;
}

void rrr(t_data *data, int does_print)
{
	reverse_rotate_stack(data->a);
	reverse_rotate_stack(data->b);
	if (does_print)
		write(1,"rrr\n", 4);
	data->bench.rrr++;
	data->bench.total++;
}

