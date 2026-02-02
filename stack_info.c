/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borabi <bilal.orabi@learner.42.tech>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:24:09 by borabi            #+#    #+#             */
/*   Updated: 2026/01/15 13:16:15 by borabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || stack->size < 2)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

int	stack_min(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	stack_max(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	stack_min_index(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	min = current->index;
	while (current)
	{
		if (current->index < min)
			min = current->index;
		current = current->next;
	}
	return (min);
}

int	stack_max_index(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	max = current->index;
	while (current)
	{
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	return (max);
}
