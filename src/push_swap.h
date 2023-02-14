/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:59:06 by hujeong           #+#    #+#             */
/*   Updated: 2023/02/14 17:41:44 by hujeong          ###   ########.fr       */
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

typedef struct s_option
{
	int		least_count;
	t_node	node;
}	t_option;

int		*get_nums(int argc, char *argv[], int *count);
void	set_stack(t_stack *a, t_stack *b, int nums[], int count);
void	sort_nums(int *nums, int count);
void	push(t_stack *stack, t_node *new);
t_node	*pop(t_stack *stack);
t_node	*new_node(int num);
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
void	greedy(t_stack *a, t_stack *b, t_pivot *pivot);

#endif