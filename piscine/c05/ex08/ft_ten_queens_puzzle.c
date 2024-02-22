/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:27:40 by hujeong           #+#    #+#             */
/*   Updated: 2022/10/15 09:48:28 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_board(char *board, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == board[col])
			return (1);
		i++;
	}
	i = 0;
	while (i < col)
	{
		if (board[i] - board[col] == col - i \
				|| board[col] - board[i] == col - i)
			return (1);
		++i;
	}
	return (0);
}

void	ft_print_board(char *board, int col, int *n)
{
	int	i;

	if (check_board(board, col - 1))
		return ;
	else
	{
		if (col == 10)
		{
			write(1, board, 10);
			write(1, "\n", 1);
			*n += 1;
			return ;
		}
		else
		{
			i = 0;
			while (i < 10)
			{
				board[col] = i + '0';
				ft_print_board(board, col + 1, n);
				++i;
			}
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	char	board[10];
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (i < 10)
		board[i++] = 0;
	i = 0;
	while (i < 10)
	{
		board[0] = i + '0';
		ft_print_board(board, 1, &n);
		i++;
	}
	return (n);
}
