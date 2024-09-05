#include <stdio.h>
#include <unistd.h>
#include "Server.h"


int main(int argc, char* argv[])
{
    //argc是命令行传入参数个数
    // argv[0]是可执行程序名字，【1】是命令行传入的第一个参数 ...
    
    if (argc < 3)
    {
        printf("./a.out port path\n");
        return -1;
    }
    unsigned short port = atoi(argv[1]);
    // 切换服务器的工作路径
    chdir(argv[2]);

    // 初始化用于监听的套接字 
    int lfd = initListenFd(10000);
    // 启动服务器程序
    epollRun(lfd);


    return 0;
}