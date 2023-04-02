/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hujeong <hujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:06:06 by hujeong           #+#    #+#             */
/*   Updated: 2023/04/02 15:04:01 by hujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void	*test1(void	*data)
{
	int	i;
	int	a;

	a = *((int *)data);
	i = 0;
	while (++i < 10)
	{
		printf("%d\n", -i * a);
	}
	return (data);
}

void	*test(void	*data)
{
	int	i;
	int	*a;

	a = ((int *)data);
	i = 0;
	while (++i < 10)
	{
		*a = *a * i;
		printf("%d\n", *a);
		usleep(2);
	}
	return (data);
}

int	main(void)
{
	int			a;
	pthread_t	pthread;
	pthread_t	pthread1;
	int			status;
	int			status1;

	a = 100;
	if (pthread_create(&pthread, NULL, test, (void *)&a) < 0)
	{
		write(2, "error\n", 6);
		return (1);
	}
	pthread_create(&pthread1, NULL, test, (void *)&a);
	pthread_join(pthread, (void **)&status);
	pthread_join(pthread1, (void **)&status1);
	printf("Thread end: %d  '%d'\n", status, status1);
	return (0);
}
