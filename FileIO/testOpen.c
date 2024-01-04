#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    /* 打开文件 */
    int fd1 = open("./hello.txt", O_RDWR | O_CREAT, 0644);
    if (fd1 == -1)
    {
        perror("open error\n");
    }
    printf("fd1 = %d\n", fd1);


    int fd2 = open("./hello.txt", O_RDWR | O_CREAT, 0644);
    if (fd2 == -1)
    {
        perror("open error\n");
    }
    printf("fd2 = %d\n", fd2);


    int fd3 = open("./hello.txt", O_RDWR | O_CREAT, 0644);
    if (fd3 == -1)
    {
        perror("open error\n");
    }
    printf("fd3 = %d\n", fd3);


    int fd4 = open("./hello.txt", O_RDWR | O_CREAT, 0644);
    if (fd4 == -1)
    {
        perror("open error\n");
    }
    printf("fd4 = %d\n", fd4);

    

    int fd5 = open("./hello.txt", O_RDWR | O_CREAT, 0644);
    if (fd5 == -1)
    {
        perror("open error\n");
    }
    printf("fd5 = %d\n", fd5);

    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);
    close(fd5);
    return 0;
}
