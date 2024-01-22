#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

int	tab_size(int *tab, int n)
{
	int	i;
	
	i = 0;
	while (i < n)
		i += 1;
	return (i);
}

int	tab_reverse(int *tab, int n)
{
	int	size;

	size = tab_size(tab, n);
	while (n > size / 2)
		n -= 1;
	return (n);
}

int	main(void)
{
	int	arr[] = {1, 24, 91, 4, 1, 999};
	int	fd[2];
	int	id;
	int	start;
	int	end;
	int	size;
	int	result;
	int	i;

	size = tab_size(arr, 6);
	if (pipe(fd) == -1)
	{
		printf("An error occured from the pipe\n");
		return (-1);
	}
	id = fork();
	if (id == -1)
	{
		printf("An error occured with fork\n");
		return (-1);
	}
	if (id == 0)
	{
		start = 0;
		end = tab_reverse(arr, 6);
	}
	else
	{
		start = size / 2;
		end = size;
	}
	result = 0;
	i = start;
	while (i < end)
	{
		result += arr[i];
		i += 1;
	}
	printf("sum %d\n", result);
	wait(NULL);
	if (id == 0)
	{
		close(fd[0]);
		write(fd[1], &result, sizeof(int));
		close(fd[1]);
	}
	else
	{
		int	child_result;
		close(fd[1]);
		read(fd[0], &child_result, sizeof(int));
		close(fd[0]);
		int	total;
		total = result + child_result;
		printf("total : %d\n", total);
	}
	return (0);
}
