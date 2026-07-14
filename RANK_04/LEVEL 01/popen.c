/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:43:10 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/01/11 20:14:52 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Assignment name  : ft_popen
Expected files   : ft_popen.c
Allowed functions: pipe, fork, dup2, execvp, close, exit
--------------------------------------------------------------------------------------

Write the following function:

int ft_popen(const char *file, char *const argv[], char type);

The function must launch the executable file with the arguments argv (using execvp).
If type is 'r' the function must return a file descriptor connected to the output of the command.
If type is 'w' the function must return a file descriptor connected to the input of the command.
In case of error or invalid parameter the function must return -1.

For example, the function could be used like that:

int main()
{
    int  fd;
    char *line;

    fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
    while ((line = get_next_line(fd)))
        ft_putstr(line);
    return (0);
}


int	main() {
	int	fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
	dup2(fd, 0);
	fd = ft_popen("grep", (char *const []){"grep", "c", NULL}, 'r');
	char	*line;
	while ((line = get_next_line(fd)))
		printf("%s", line);
}

Hints:
Do not leak file descriptors!
This exercise is inspired by the libc's popen().
*/

#include <unistd.h>     // pipe, fork, dup2, execvp, close
#include <stdlib.h>     // exit
#include <sys/types.h>  // pid_t

int ft_popen(const char *file, char *const argv[], char type)
{
    int     fd[2];
    pid_t   pid;

    if (!file || !argv || !argv[0] || (type != 'r' && type != 'w'))
        return (-1);
    if (pipe(fd) == -1)
        return (-1);

    pid = fork();
    if (pid < 0)
    {
        close(fd[0]);
        close(fd[1]);
        return (-1);
    }
    if (pid == 0)
    {
        if (type == 'r')
        {
            if (dup2(fd[1], STDOUT_FILENO) == -1)
            {
                close(fd[0]);
                close(fd[1]);
                exit(1);
            }
        }
        else
        {
            if (dup2(fd[0], STDIN_FILENO) == -1)
            {
                close(fd[0]);
                close(fd[1]);
                exit(1);
            }
        }
        close(fd[0]);
        close(fd[1]);
        execvp(file, argv);
        exit(1);
    }
    if (type == 'r')
    {
        close(fd[1]);
        return (fd[0]);
    }
    else
    {
        close(fd[0]);
        return (fd[1]);
    }
}

/*#include <stdio.h>
#include <string.h>
int main()
{
	//int fd = open("texte", O_RDONLY);
	int fd = ft_popen("lss", (char *const[]){"ls", NULL}, 'r');

	char buf[1];
	while(read(fd, buf, 1))
		write(1, buf, 1);

	close(fd);
	return (0);
}*/ 
