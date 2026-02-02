/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borabi <bilal.orabi@learner.42.tech>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 18:59:19 by borabi            #+#    #+#             */
/*   Updated: 2026/01/15 14:39:27 by borabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(t_stack *stack)
{
	t_node	*i;
	t_node	*j;

	if (!stack || stack->size < 2)
		return (0);
	i = stack->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

static void	add_to_bottom(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (stack->size == 0)
	{
		stack->top = node;
		stack->bottom = node;
	}
	else
	{
		node->prev = stack->bottom;
		stack->bottom->next = node;
		stack->bottom = node;
	}
	stack->size++;
}

int	parse_args(int argc, char **argv, t_data *data)
{
	int		i;
	long	number;
	t_node	*node;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-' && ft_isalpha(argv[i][2]))
			continue ;
		if (!is_valid_number(argv[i]))
			return (0);
		number = ft_atol(argv[i]);
		if (number > INT_MAX || number < INT_MIN)
			return (0);
		node = new_node((int)number);
		if (!node)
			return (0);
		add_to_bottom(data->a, node);
	}
	if (has_duplicate(data->a))
		return (0);
	return (1);
}
