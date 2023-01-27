#include "pipex.h"

int	main(void)
{
	int	fd[2];
	pid_t	pid[2];
	char	buff[10];
	int		status;

	pipe(fd);
	pid[0] = fork();
	if (pid[0] == 0)
	{
		pid[1] = fork();
		if (pid[1] == 0)
		{
			char *buff;
			dup2(fd[1], 1);
			close(fd[1]);
			close(fd[0]);
			close(0);
			int fd3 = open("hi.c", O_RDONLY);
			buff = get_next_line(fd3);
			write(1, buff, ft_strlen(buff));
			while (1)
				write(1, "\n", 1);
			return (0);
		}
		char *argv[3] = {"head", "-n1" , NULL};
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		sleep(10);
		if (execve("/usr/bin/head", argv, NULL) < 0)
			perror("error");
	}
	waitpid(pid[0], NULL, 0);
	return (0);
}
