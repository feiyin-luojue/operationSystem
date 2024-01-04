#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 10

int main(int argc, char const *argv[])
{
#if 1
    /* 打开文件 */
    int fd = open("./hello.txt",  O_RDWR);
    if (fd == -1)
    {
        perror("open error\n");
    }
    
    char buf[BUFFER_SIZE];
    memset(buf, 0, sizeof(buf));

    read(fd, buf, sizeof(buf) - 1); 
    printf("buf:%s\n", buf);

    read(fd, buf, sizeof(buf) - 1); 
    printf("buf:%s\n", buf);

    /* 缓冲区 */
    char array[] = "hello world";
    write(fd, array, sizeof(array) - 1);

    off_t offset = lseek(fd, 0, SEEK_CUR);
    printf("offset:%ld\n", offset);

    close(fd);

#endif
}