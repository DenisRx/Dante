/*
** EPITECH PROJECT, 2021
** reader
** File description:
** reader
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

char *read_file(char const *filepath, char *buff)
{
    int fd = open(filepath, O_RDONLY);
    struct stat * file;
    ssize_t size;

    if ((file = malloc(sizeof(struct stat))) == NULL)
        return (NULL);
    if (fd == -1)
        return (NULL);
    if (stat(filepath, file) == -1)
        return (NULL);
    if ((buff = malloc(sizeof(char) * (file->st_size + 1))) == NULL)
        return (NULL);
    if ((size = read(fd, buff, file->st_size)) == -1)
        return (NULL);
    buff[size] = '\0';
    if (close(fd) == -1)
        return (NULL);
    free(file);
    if (buff[0] == 0)
        return NULL;
    return (buff);
}