/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eltouma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 15:16:09 by eltouma           #+#    #+#             */
/*   Updated: 2024/02/07 17:07:40 by eltouma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		int		file;
		int		file2;
		int		error;
//		char	*arr[] = {"sbin/ping", "-c", "3", "google.com", NULL};		// maison
		char	*arr[] = {"/usr/bin/ping", "-c", "3", "google.com", NULL};	// 42
		file = open("redirection_test.txt", O_RDONLY | O_WRONLY | O_CREAT, 0777);
		if (file == -1)
			return (-1);
		file2 = dup2(file, 1);
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
				printf("Success\n");
			else
				printf("Failure with status code: %d\n", code_status);
		}
	}
	return (0);
}
