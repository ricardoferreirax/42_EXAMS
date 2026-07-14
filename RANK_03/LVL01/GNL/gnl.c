/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmedeiro <rmedeiro@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:38:37 by rmedeiro          #+#    #+#             */
/*   Updated: 2026/01/06 16:39:01 by rmedeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int     get_size(char *line)
{
    int i;

    i = 0;
    if (!line)
        return (0);
    while (line[i])
    {
        if (line[i++] == '\n')
            break ;
    }
    return (i);
}

int     has_new_line(char *line)
{
    int i;

    i = 0;
    if (!line)
        return (0);
    while (line[i])
    {
        if (line[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

void    move_buffer(char *buffer)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n')
        i++;
    while (buffer[i])
        buffer[j++] = buffer[i++];
    buffer[j] = '\0';
}

char *copy_to_line(char *line, char *buffer)
{
    char    *new_line;
    char    *temp_new;
    char    *temp_old;

    new_line = malloc(get_size(buffer) + get_size(line) + 1);
    if (!new_line)
        return (free(line), NULL);
    temp_new = new_line;
    temp_old = line;
    while (line && *line)
        *temp_new++ = *line++;
    while(*buffer)
    {
        *temp_new++ = *buffer;
        if (*buffer++ == '\n')
            break ;
    }
    free(temp_old);
    *temp_new = '\0';
    return (new_line);
}

char    *get_next_line(int fd)
{
    static char    buffer[BUFFER_SIZE + 1];
    ssize_t        readbytes;
    char           *line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = NULL;
    readbytes = 1;
    while (!has_new_line(line))
    {
        if (buffer[0] == '\0')
        {
            readbytes = read(fd, buffer, BUFFER_SIZE);
            if (readbytes == -1)
                return (free(line), NULL);
            if (readbytes == 0)
                return (line);
            if (readbytes >= 0)
                buffer[readbytes] = '\0';
        }
        line = copy_to_line(line, buffer);
        move_buffer(buffer);
    }
    return (line);
}