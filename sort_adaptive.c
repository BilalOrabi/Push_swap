/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borabi <bilal.orabi@learner.42.tech>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:35:57 by borabi            #+#    #+#             */
/*   Updated: 2026/01/15 13:05:03 by borabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	select_strategy(t_data *data, double disorder)
{
	if (disorder < 0.2)
	{
		data->strategy = SIMPLE;
		sort_simple(data);
	}
	else if (disorder < 0.5)
	{
		data->strategy = MEDIUM;
		sort_medium(data);
	}
	else
	{
		data->strategy = COMPLEX;
		sort_complex(data);
	}
}

void	sort_adaptive(t_data *data)
{
	double	disorder;

	if (stack_is_sorted(data->a))
		return ;
	if (data->a->size <= 5)
	{
		if (data->a->size == 2)
			sort_two(data);
		else if (data->a->size == 3)
			sort_three(data);
		else if (data->a->size == 4)
			sort_four(data);
		else if (data->a->size == 5)
			sort_five(data);
		return ;
	}
	disorder = compute_disorder(data->a);
	data->disorder = disorder;
	select_strategy(data, disorder);
}
