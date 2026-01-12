/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilty.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borabi <bilal.orabi@learner.42.tech>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 18:13:37 by borabi            #+#    #+#             */
/*   Updated: 2026/01/04 18:13:37 by borabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *new_stack(void)
{
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

t_node *new_node(int value)
{
	t_node *node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void stack_push(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;

	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
		node->next = NULL;
		node->prev = NULL;
	}
	else
	{
		node->next = stack->top;
		node->prev = NULL;
		stack->top->prev = node;
		stack->top = node;
	}
	stack->size++;
}

t_node *stack_pop(t_stack *stack)
{
	t_node *node;
	if (!stack || stack->size == 0)
		return (NULL);
	
	node = stack->top;
	if (stack->size == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->top = node->next;
		stack->top->prev = NULL;
	}

	node->next = NULL;
	node->prev = NULL;
	stack->size--;

	return (node);
}

void stack_free(t_stack *stack)
{
	t_node *current;
	t_node *next;

	if(!stack)
		return ;

	current = stack->top;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}

	free(stack);
}
