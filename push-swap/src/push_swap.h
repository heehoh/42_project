/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:59:06 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/18 14:44:06 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				num;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef struct s_pivot
{
	int	first;
	int	second;
	int	third;
}	t_pivot;

typedef struct s_count
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_count;

int		*get_nums(char *argv[], int *count);
void	set_stack(t_stack *a, t_stack *b, int nums[], int count);
void	get_pivot(int *nums, int count, t_pivot *pivot);
void	sort_stack(t_stack *a, t_stack *b, t_pivot *pivot);
int		is_sorted(t_stack *stack);
void	push(t_stack *stack, t_node *new);
t_node	*pop(t_stack *stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	greedy(t_stack *a, t_stack *b, int pivot);
void	init_count(t_count *count, int rb, int rrb);
void	count_op(t_stack *a, t_node *node, t_count *count, t_count *least);
void	free_stack(t_stack *stack);
void	print_malloc_error(void);
void	print_error(void);

#endif