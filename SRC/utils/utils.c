/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borabi <bilal.orabi@learner.42.tech>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 21:29:15 by borabi            #+#    #+#             */
/*   Updated: 2026/01/05 21:29:15 by borabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_all(t_data *data)
{
	if (data->a)
		stack_free(data->a);
	if (data->b)
		stack_free(data->b);
}

void error_exit(t_data *data)
{
	free_all(data);
	write(2, "Error\n", 6);
	exit(1);
}

static void print_bench_ops(t_data *data)
{
	ft_putstr_fd("[bench] sa: ", 2);
    ft_putnbr_fd(data->bench.sa, 2);
    ft_putstr_fd(" sb: ", 2);
    ft_putnbr_fd(data->bench.sb, 2);
    ft_putstr_fd(" ss: ", 2);
    ft_putnbr_fd(data->bench.ss, 2);
    ft_putstr_fd(" pa: ", 2);
    ft_putnbr_fd(data->bench.pa, 2);
    ft_putstr_fd(" pb: ", 2);
    ft_putnbr_fd(data->bench.pb, 2);
    ft_putstr_fd("\n[bench] ra: ", 2);
    ft_putnbr_fd(data->bench.ra, 2);
    ft_putstr_fd(" rb: ", 2);
    ft_putnbr_fd(data->bench.rb, 2);
    ft_putstr_fd(" rr: ", 2);
    ft_putnbr_fd(data->bench.rr, 2);
    ft_putstr_fd(" rra: ", 2);
    ft_putnbr_fd(data->bench.rra, 2);
    ft_putstr_fd(" rrb: ", 2);
    ft_putnbr_fd(data->bench.rrb, 2);
    ft_putstr_fd(" rrr: ", 2);
    ft_putnbr_fd(data->bench.rrr, 2);
    ft_putstr_fd("\n", 2);
}

static void print_strategy_name(t_data *data)
{
	ft_putstr_fd("[bench] strategy: ", 2);
    if (data->strategy == SIMPLE)
		ft_putstr_fd("Simple / O(n^2)\n", 2);
    else if (data->strategy == MEDIUM)
        ft_putstr_fd("Medium / O(n*sqrt(n))\n", 2);
    else if (data->strategy == COMPLEX)
        ft_putstr_fd("Complex / O(n log n)\n", 2);
    else
    {
        if (data->disorder < 0.2)
            ft_putstr_fd("Adaptive / O(n)\n", 2);
        else if (data->disorder < 0.5)
            ft_putstr_fd("Adaptive / O(n*sqrt(n))\n", 2);
        else
            ft_putstr_fd("Adaptive / O(n log n)\n", 2);
    }
}

void print_benchmark(t_data *data)
{
	int    disorder_int;
    int    disorder_dec;

    if (!data->bench_mode)
        return ;
    disorder_int = (int)(data->disorder * 100);
    disorder_dec = (int)(data->disorder * 10000) % 100;
    ft_putstr_fd("[bench] disorder: ", 2);
    ft_putnbr_fd(disorder_int, 2);
    ft_putstr_fd(".", 2);
    if (disorder_dec < 10)
        ft_putstr_fd("0", 2);
    ft_putnbr_fd(disorder_dec, 2);
    ft_putstr_fd("%\n", 2);
    print_strategy_name(data);
    ft_putstr_fd("[bench] total_ops: ", 2);
    ft_putnbr_fd(data->bench.total, 2);
    ft_putstr_fd("\n", 2);
    print_bench_ops(data);
}

