#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 100

int main(int argc, char const *argv[])
{

    /* 打开文件 */
    int fd = open("./hello.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open error\n");
    }

    char buffer[BUFFER_SIZE] = {0};

    int length = read(fd, &buffer, sizeof(buffer) - 1);
    printf("length = %d\n", length);
    printf("buffer:\n%s", buffer);

    close(fd);

}