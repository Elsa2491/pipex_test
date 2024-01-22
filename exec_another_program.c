#include <unistd.h>
#include <stdio.h>
#include <sys/errno.h>

int	main(void)
{
	char *arr[] = {"/sbin/ping", "google.com", NULL};
	execv(arr[0], arr);
	int	err = errno;
	printf("Ping finished executing\n");
	return (0);
}
