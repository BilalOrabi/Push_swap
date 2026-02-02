/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borabi <bilal.orabi@learner.42.tech>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 20:35:21 by borabi            #+#    #+#             */
/*   Updated: 2026/01/15 12:46:02 by borabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *stack)
{
	t_node	*i;
	t_node	*j;
	int		mistake;
	int		total_pairs;

	if (!stack || stack->size < 2)
		return (0.0);
	mistake = 0;
	total_pairs = 0;
	i = stack->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->index > j->index)
				mistake++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistake / (double)total_pairs);
}
