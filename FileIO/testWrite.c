#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
#if 1
    /* 打开文件 */
    int fd = open("./hello.txt", O_RDWR | O_CREAT, 666);
    if (fd == -1)
    {
        perror("open error\n");
    }

    /* 向文件中写数据 */
    char *ptr = "hello world\n";
    int bytes = write(fd, ptr, strlen(ptr));
    if (bytes < 0)
    {
        perror("write error\n");
    }
    else
    {
        printf("bytes:%d\n", bytes);
    }

    close(fd);
#endif

#if 0
    /* 打开文件 */
    int fd = open("./hello.txt", O_RDWR | O_TRUNC);     //O_TRUNC是清空文件
    if (fd == -1)
    {
        perror("open error\n");
    }

    close(fd);
#endif

#if 0
    int fd = open("./hello.txt", O_RDWR | O_APPEND, 777);     //O_APPEND是追加文件
    if (fd == -1)
    {
        perror("open error\n");
    }

    char ptr[]= "123\n";
    write(fd, ptr, sizeof(ptr) - 1);

    close(fd);
#endif

    return 0;
}
