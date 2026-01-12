/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borabi <bilal.orabi@learner.42.tech>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:22:47 by borabi            #+#    #+#             */
/*   Updated: 2026/01/04 20:22:47 by borabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap_stack(t_stack *stack)
{
	int temp_value;
	int temp_index;
	if(!stack || stack->size < 2)
		return ;
	temp_value = stack->top->value;
	temp_index = stack->top->index;
	stack->top->value = stack->top->next->value;
	stack->top->index = stack->top->next->index;
	stack->top->next->value = temp_value;
	stack->top->next->index = temp_index;
}

void sa(t_data *data, int does_print)
{
	swap_stack(data->a);
	if(does_print)
		write(1, "sa\n", 3);
	data->bench.sa++;
	data->bench.total++;
}

void sb(t_data *data, int does_print)
{
	swap_stack(data->b);
	if(does_print)
		write(1, "sb\n", 3);
	data->bench.sb++;
	data->bench.total++;
}

void ss(t_data *data, int does_print)
{
	swap_stack(data->a);
	swap_stack(data->b);
	if(does_print)
		write(1, "ss\n", 3);
	data->bench.ss++;
	data->bench.total++;
}