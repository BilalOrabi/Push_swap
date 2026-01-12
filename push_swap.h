/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: borabi <bilal.orabi@learner.42.tech>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 17:51:05 by borabi            #+#    #+#             */
/*   Updated: 2026/01/04 17:51:05 by borabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//####################################
//##############{Lib}##############
//####################################
#include <limits.h>
#include "libft/libft.h"

//####################################
//##############{structs}##############
//####################################

typedef struct s_node
{
	int value;
	int index;
	t_node *next;
	t_node *prev;
} t_node ;

typedef struct s_stack
{
	int size;
	t_node *top;
	t_node *bottom;
} t_stack ;

typedef struct s_bench
{
	int sa;
	int sb;
	int ss;

	int pa;
	int pb;

	int ra;
	int rb;
	int rr;

	int rra;
	int rrb;
	int rrr;

	int total;
} t_bench ;

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
} t_strategy ;

typedef struct s_data
{
	t_bench bench;
	t_stack *a;
	t_stack *b;
	t_strategy strategy;
	double disorder;
	int bench_mode;
} t_data ;

//####################################
//##############{Utilty}##############
//####################################

void stack_free(t_stack *stack);
t_node *stack_pop(t_stack *stack);
void stack_push(t_stack *stack, t_node *node);
t_node *new_node(int value);
t_stack *new_stack(void);
double compute_disorder(t_stack *stack);
void index_stack(t_stack *stack);
int stack_is_sorted(t_stack *stack);
int stack_min(t_stack *stack);
int stack_max(t_stack *stack);
int stack_min_index(t_stack *stack);
int stack_max_index(t_stack *stack);
long	ft_atoi_v2(char *str);
int is_valid_number(char *str);
int has_duplicate(t_stack *stack);
int	parse_args(int argc, char **argv, t_data *data);

//####################################
//##############{helper}##############
//####################################

int	get_position(t_stack *stack, int index);
void	rotate_to_top(t_data *data, t_stack *stack, int position, char name);
int	ft_sqrt(int n);
int	get_max_bits(t_stack *stack);

//#####################################
//##############{op_push}##############
//#####################################
void pb(t_data *data, int does_print);
void pa(t_data *data, int does_print);

//#####################################
//#########{op_reverse_rotate}#########
//#####################################
void rrr(t_data data, int does_print);
void rrb(t_data data, int does_print);
void rra(t_data data, int does_print);

//#####################################
//#########{op_rotate}#################
//#####################################
void rr(t_data data, int does_print);
void rb(t_data data, int does_print);
void ra(t_data data, int does_print);

//#####################################
//#########{op_swap}###################
//#####################################
void	sa(t_data *data, int does_print);
void	sb(t_data *data, int does_print);
void	ss(t_data *data, int does_print);

//####################################
//##############{sort_small}##########
//####################################
void	sort_two(t_data *data);
void	sort_three(t_data *data);
void	sort_four(t_data *data);
void	sort_five(t_data *data);

//####################################
//##############{sort_simple}#########
//####################################
void	sort_simple(t_data *data);

//####################################
//############{sort_medium}###########
//####################################
void	sort_medium(t_data *data);

//####################################
//############{sort_complex}##########
//####################################

//####################################
//############{sort_adaptive}#########
//####################################
#endif
