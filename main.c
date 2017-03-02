#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd;
    int fd2;
    char *line;
    int next_line;
    
    (void)argc;
    fd = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_RDONLY);
    next_line = get_next_line(fd, &line);
    printf("%d.(1.1) - %s\n", next_line, line);
    next_line = get_next_line(fd, &line);
    printf("%d.(1.2) - %s\n", next_line, line);
    next_line = get_next_line(fd2, &line);
    printf("%d.(2.1) - %s\n", next_line, line);
    next_line = get_next_line(fd, &line);
    printf("%d.(1.3) - %s\n", next_line, line);
    next_line = get_next_line(fd, &line);
    printf("%d.(1.4) - %s\n", next_line, line);
    next_line = get_next_line(fd2, &line);
    printf("%d.(2.2) - %s\n", next_line, line);
    next_line = get_next_line(fd2, &line);
    printf("%d.(2.3) - %s\n", next_line, line);
    next_line = get_next_line(fd, &line);
    printf("%d.(1.5) - %s\n", next_line, line);
    next_line = get_next_line(fd2, &line);
    printf("%d.(2.4) - %s\n", next_line, line);
    next_line = get_next_line(fd2, &line);
    printf("%d.(2.5) - %s\n", next_line, line);
    return (0);
}
