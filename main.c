/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borabi <bilal.orabi@learner.42.tech>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 04:00:35 by borabi            #+#    #+#             */
/*   Updated: 2026/01/12 04:00:35 by borabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_data(t_data *data)
{
	data->a = new_stack();
	data->b = new_stack();
	data->strategy = ADAPTIVE;
	data->disorder = 0.0;
	data->bench_mode = 0;
	ft_bzero(&data->bench, sizeof(t_bench));
}

static int	parse_flags(int argc, char **argv, t_data *data)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--simple", 9) == 0)
			data->strategy = SIMPLE;
		else if (ft_strncmp(argv[i], "--medium", 9) == 0)
			data->strategy = MEDIUM;
		else if (ft_strncmp(argv[i], "--complex", 9) == 0)
			data->strategy = COMPLEX;
		else if (ft_strncmp(argv[i], "--adaptive", 9) == 0)
			data->strategy = ADAPTIVE;
		else if (ft_strncmp(argv[i], "--bench", 9) == 0)
			data->bench_mode = 1;
		i++;
	}
	return (1);
}

static void	run_sort(t_data *data)
{
	if (data->strategy == SIMPLE)
		sort_simple(data);
	else if (data->strategy == MEDIUM)
		sort_medium(data);
	else if (data->strategy == COMPLEX)
		sort_complex(data);
	else if (data->strategy == ADAPTIVE)
		sort_adaptive(data);
}

static int	has_numbers(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-' || ft_isdigit(argv[i][1])
		|| (argv[i][1] == '-' && ft_isdigit(argv[i][2])))
			return (1);
		if (argv[i][0] == '-' && argv[i][1] != '-')
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	if (!has_numbers(argc, argv))
		return (0);
	init_data(&data);
	if (!data.a || !data.b)
		error_exit(&data);
	parse_flags(argc, argv, &data);
	if (!parse_args(argc, argv, &data))
		error_exit(&data);
	if (data.a->size == 0)
	{
		free_all(&data);
		return (0);
	}
	index_stack(data.a);
	data.disorder = compute_disorder(data.a);
	if (!stack_is_sorted(data.a))
		run_sort(&data);
	print_benchmark(&data);
	free_all(&data);
	return (0);
}
