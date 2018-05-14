/*********************************************************************************
 *      Copyright:  Wang Tao
 *                 
 *
 *       Filename:  socket_server.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(4/29/2018)
 *         Author:  Wang Tao <TAlicer@163.com>
 *      ChangeLog:  1, Release initial version on "4/29/2018 01:41:05 PM"
 *                 
 ********************************************************************************/


#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main(int argc, char **argv)
{
    int                     listen_fd,  new_fd = -1;   //为什么不设置listen_fd = -1
    struct sockaddr_in      serv_addr;             
    char                    buf[1024]; 
    
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_fd < 0 )
    {
        printf("create socket failure: %s\n", strerror(errno));
        return -1;
    }
    printf("socket create fd[%d]\n", listen_fd);

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;        
    serv_addr.sin_port = htons(8889);
   // inet_aton( "192.168.152.20", &serv_addr.sin_addr );
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);   //INADDR_ANY为0
    //uint32_t htonl(ADDR);

    if( bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0 )  //服务端套接字绑定自己的IP地址与端口号
    {
        printf("create socket failure: %s\n", strerror(errno));
        return -2;               //为什么返回为-2而不是-1
    }
    printf("socket bind ok\n", listen_fd);

    listen(listen_fd, 13);     //最大监听客户端数为13个？
    printf("listen fd ok\n", listen_fd);
    
    while(1)   
    {
        printf("start accept...\n", listen_fd);
        new_fd = accept(listen_fd, NULL, NULL);
        if(new_fd < 0)
        {
            printf("accept new socket failure: %s\n", strerror(errno));
            return -2;
        }
        printf("accept ok, return new fd: [%d]\n", new_fd);

        memset(buf, 0, sizeof(buf));        

        read(new_fd, buf, sizeof(buf));     
        printf("read '%s' from client\n", buf);

        write(new_fd, "goodbye", strlen("goodbye"));
        sleep(1);
        close(new_fd); 
    } 
    close(listen_fd);
}


