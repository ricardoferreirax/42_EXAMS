/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picoshell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 16:45:02 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/01/13 05:47:44 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
Assignment name:	picoshell
Expected files:		picoshell.c
Allowed functions:	close, fork, wait, exit, execvp, dup2, pipe
___________________________________________________________________

Write the following function:

int    picoshell(char **cmds[]);

The goal of this function is to execute a pipeline. It must execute each
commands of cmds and connect the output of one to the input of the
next command (just like a shell).
e
Cmds contains a null-terminated list of valid commands. Each rows
of cmds are an argv array directly usable for a call to execvp. The first
arguments of each command is the command name or path and can be passed
directly as the first argument of execvp.

If any error occur, The function must return 1 (you must of course
close all the open fds before). otherwise the function must wait all child
processes and return 0. You will find in this directory a file main.c which
contain something to help you test your function.


Examples: 
./picoshell /bin/ls "|" /usr/bin/grep picoshell
picoshell
./picoshell echo 'squalala' "|" cat "|" sed 's/a/b/g'
squblblb

___________________________________________________________________

Old summary by a student:
You are given a main function. It converts received arguments into cmds array
of strings. When there is a pipe the commands after the pipe are in the next
array of strings. You have to create a pipeline using the cmds you receive from
the main, and execute them. If there is any error the function should return 1.
Close all FFS before returning. If the cmds executed successfully wait all
child processes and return 0.
*/

#

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int picoshell(char **cmds[])
{
	int prevfd = -1;
	int pipefd[2];
	int status;
	int ret = 0;
	int i = 0;

	if (!cmds || !cmds[0])
		return (0);
	while (cmds[i])
	{
		if (cmds[i + 1])
		{
			if (pipe(pipefd) == -1)
			{
				ret = 1;
				break ;
			}
		}
		else
		{
			pipefd[0] = -1;
			pipefd[1] = -1;
		}
		pid_t pid = fork();
		if (pid < 0)
		{
			if (pipefd[0] != -1)
				close(pipefd[0]);
			if (pipefd[1] != -1)
				close(pipefd[1]);
			ret = 1;
			break ;
		}
		if (pid == 0)
		{
			if (prevfd != -1)
			{
				if (dup2(prevfd, STDIN_FILENO) == -1)
					exit(1);
			}
			if (cmds[i + 1])
			{
				if (dup2(pipefd[1], STDOUT_FILENO) == -1)
					exit(1);
			}
			if (prevfd != -1)
				close(prevfd);
			if (cmds[i + 1])
			{
				close(pipefd[0]);
				close(pipefd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (prevfd != -1)
			close(prevfd);
		if (cmds[i + 1])
		{
			close(pipefd[1]);
			prevfd = pipefd[0];
		}
		else
			prevfd = -1;
		i++;
	}
	if (prevfd != -1)
		close(prevfd);
	while (wait(&status) > 0)
	{
		if (WIFEXITED(status) == 0 || WEXITSTATUS(status) != 0)
			ret = 1;
	}
	return (ret);
}

#include <stdio.h>
int main(void)
{
    char *cmd1[] = {"/bin/ls", "level-1", NULL};
    // char *cmd1[] = {"/bin/ls", NULL};
    char *cmd2[] = {"/usr/bin/grep", "picoshell", NULL};
    char **cmds[] = {cmd1, cmd2, NULL};

    int result = picoshell(cmds);
    printf("picoshell returned %d\n", result);

    return 0;
}
