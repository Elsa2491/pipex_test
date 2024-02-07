#include <unistd.h>
#include <stdio.h>
#include <sys/errno.h>

int	main(void)
{
//	char *arr[] = {"/sbin/ping", "google.com", NULL};		// a la maison
	char *arr[] = {"/usr/bin/ping", "google.com", NULL};		// a 42
	execv(arr[0], arr);
	int	err = errno;
	printf("Ping finished executing\nerror status: %d\n", err);
	return (0);
}
