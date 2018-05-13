/*********************************************************************************
 *      Copyright:  (C) 2018 wangtao
 *                  All rights reserved.
 *
 *       Filename:  fork1.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(05/11/2018)
 *         Author:  WangTao <TAlicer@163.com>
 *      ChangeLog:  1, Release initial version on "05/11/2018 06:09:56 PM"
 *                 
 ********************************************************************************/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define IPC_FILE ".ipc.log"
/********************************************************************************
 *  Description:
 *   Input Args:
 *  Output Args:
 * Return Value:
 ********************************************************************************/
int main (int argc, char **argv)
{
 
    pid_t  pid;
    int    fd = -1;
    char   buf[512];
    FILE   *fp = NULL;

    fd = open(IPC_FILE, O_RDWR|O_CREAT|O_TRUNC,0644);    //打开.ipc.log并获取文件描述符fd
    if( fd < 0)
    {
        printf("open file '%s' failure: %s\n",IPC_FILE,strerror(errno));
        return 0;
    }

    pid=fork();                           //调用fork函数创建子进程
    if(pid <0)
    {
       printf("fork() error: %s\n",strerror(errno));
       return 0;
    }

    else if(pid == 0)    //###"子进程"###
    {
       dup2(fd,1);       //在子进程中，将标准输出重定向到.ipc.log文件中（将标准输出（1）关掉，再将.ipc.log的文件描述符改为1）
     //  sleep(2);
       execl("/sbin/ifconfig","ifconfig","eth0",NULL);  //调用execl执行新的程序（命令）
       printf("####haha\n");     //该句不会打印
    }

    else if(pid > 0)    //###"父进程"###
    {
       int     status;
       wait(&status);       //等待子进程退出后，再继续向下执行

       printf("Parent running: child pid[%ld],parent pid[%ld],grandparent pid[%ld]\n",pid,getpid(),getppid());
       
       lseek(fd,0,SEEK_SET);   //将文件偏移量设置为0，不然读到为空
       fp = fdopen(fd,"r");                   //将文件描述符转换为文件流
      // while( read(fd,buf,sizeof(buf))>0 )
       while( fgets(buf,sizeof(buf),fp)>0 )   //将.ipc.log里的内容一行一行的读到buf里
       {
         if( strstr(buf,"inet addr:"))        //如果读到的某一行buf含有关键词"inet addr:"，则打印该次buf里的内容
         {
           printf("buf:%s\n",buf);
         }
       }
    }

    close(fd);
    unlink(IPC_FILE);    //删除文件.ipc.log

    return 0;
} /* ----- End of main() ----- */

