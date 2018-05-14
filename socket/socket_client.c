/*********************************************************************************
 *      Copyright:  WangTao
 *               
 *
 *       Filename:  socket_client.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(4/29/2018)
 *         Author:  wang Tao <TAlicer@163.com>
 *      ChangeLog:  1, Release initial version on "4/29/2018 01:38:08 PM"
 *                 
 ********************************************************************************/
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int                     conn_fd = -1;
    struct sockaddr_in      serv_addr;
    char                    buf[1024]; 
    char                    r_buf[1024];
    conn_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(conn_fd < 0)
    {
        printf("create socket failure: %s\n", strerror(errno));
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8889);
    inet_aton( "192.168.152.20", &serv_addr.sin_addr );
     // inet_aton( "127.0.0.1", &serv_addr.sin_addr );

    if( connect(conn_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))  < 0)
    {
        printf("connect to server failure: %s\n", strerror(errno));
        return 0;
    }
    freopen("/wt.txt","r",stdin);
    fgets(r_buf,40,stdin);
    //freopen("/home/wt/supertao/socket/wt.txt","r",stdin);
    write(conn_fd, r_buf, strlen(r_buf)); 
    
    memset(buf, 0, sizeof(buf));
    read(conn_fd, buf, sizeof(buf));    
    printf("read '%s' from client\n", buf); 
    
    sleep(1);   
    close(conn_fd);
}

