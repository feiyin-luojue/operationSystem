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
    /* 打开两个文件 */
    int fd1 = open("./txt1.txt", O_RDONLY);
    int fd2 = open("./txt2.txt", O_WRONLY);

    /* 判断文件是否成功打开 */
    if(fd1 == -1)
    {
        perror("fd1 oppen error\n");
    }
    if(fd2 == -1)
    {
        perror("fd2 oppen error\n");
    }

    /* 缓冲区*/
    char buf[BUFFER_SIZE];
    memset(buf, 0, sizeof(buf));
    
    /* 开始读写 */
    while (1)
    {   
        int reallen = read(fd1, buf, sizeof(buf) - 1);
        if (reallen == 0)
        {
            break;
        }
        write(fd2, buf, reallen);
        if (reallen < sizeof(buf) - 1)  //如果读完就结束读写
        {
            break;
        }
    }

    close(fd1);
    close(fd2);
    return 0;
}
