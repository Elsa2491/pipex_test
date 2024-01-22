#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>

int	main(void)
{
	int	id;

	id = fork();
	if (id == -1)
		return (-1);

	if (id == 0)
	{
		int	filde;
		int	error;
		char *arr[] = {"/sbin/ping", "-c", "3", "google.com", NULL};

		file = open("redirection_test.txt", O_WRONLY | OCREAT, 0777);
		if (file == -1)
			return (-1);
		error = execv(arr[0], arr);
		if (error == -1)
		{
			printf("Error in child process\n");
			return (-1);
		}
	}
	else
	{
		int	wait_status;

		wait(&wait_status);
		if (WIFEXITED(wait_status))
		{
			int	code_status;

			code_status = WEXITSTATUS(wait_status);
			if (code_status == 0)
				printf("\nSuccess\n");
			else
				printf("\nFailure with status code: %d\n", code_status);
		}
	}
	return (0);
}
