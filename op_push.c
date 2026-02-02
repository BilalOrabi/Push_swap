/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borabi <bilal.orabi@learner.42.tech>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:02:28 by borabi            #+#    #+#             */
/*   Updated: 2026/01/15 12:51:43 by borabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to(t_stack *src, t_stack *dst)
{
	t_node	*node;

	if (!src || src->size == 0)
		return ;
	node = stack_pop(src);
	stack_push(dst, node);
}

void	pa(t_data *data, int does_print)
{
	push_to(data->b, data->a);
	if (does_print)
		write(1, "pa\n", 3);
	data->bench.pa++;
	data->bench.total++;
}

void	pb(t_data *data, int does_print)
{
	push_to(data->a, data->b);
	if (does_print)
		write(1, "pb\n", 3);
	data->bench.pb++;
	data->bench.total++;
}
