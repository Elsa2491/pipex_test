#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(void)
{
	int	p1[2];	// C => P	read
	int	p2[2];	// P => C	write
	int	id;

	if (pipe(p1) == -1) 
		return (-1);
	if (pipe(p2) == -1)
		return (-1);
	id = fork();
	if (id == -1)
		return (-1);
	if (id == 0)
	{
		close(p1[0]);
		close(p2[1]);
		int	x;
		if (read(p2[0], &x, sizeof(x)) == -1)
			return (-1);
		x *= 3;
		if (write(p1[1], &x, sizeof(x)) == -1)
			return (-1);
		close(p1[1]);
		close(p2[0]);
	}
	else
	{
		close(p1[1]);
		close(p2[0]);
		int	y;
		y = 4;
		if (write(p2[1], &y, sizeof(y)) == -1)
			return (-1);
		if (read(p1[0], &y, sizeof(y)) == -1)
			return (-1);
		printf("result is %d\n", y);
		close(p1[0]);
		close(p2[1]);
		wait(NULL);
	}
}
