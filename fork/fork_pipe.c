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
#include<unistd.h>

/********************************************************************************
 *  Description:
 *   Input Args:
 *  Output Args:
 * Return Value:
 ********************************************************************************/
int main (int argc, char **argv)
{
 
    pid_t  pid;
    int    fd[2];
    char   buf[512];
    FILE   *fp = NULL;

    if( pipe(fd)<0 )
    {
       printf("pipe failure: %s\n",strerror(errno));
       return -1;
    }

//    fd = open(IPC_FILE, O_RDWR|O_CREAT|O_TRUNC,0644);
//    if( fd < 0)
//    {
//        printf("open file '%s' failure: %s\n",IPC_FILE,strerror(errno));
//        return 0;
//    }

    pid=fork();
    if(pid <0)
    {
       printf("fork() error: %s\n",strerror(errno));
       return 0;
    }

    else if(pid == 0)     //###"子进程"###
    {  
       close(fd[0]);      //关闭管道读端
       dup2(fd[1],1);     //在子进程中，将标准输出重定向到管道写端中（将标准输出（1）关掉，再将管道写端的文件描述符改为1）
     //  sleep(2);
       execl("/sbin/ifconfig","ifconfig","eth0",NULL);
       printf("####haha\n");  //该句不会打印
    }

    else if(pid > 0)     //###"父进程"###
    {  
       close(fd[1]);     //关闭管道写端
       int     status;
       wait(&status);

       printf("Parent running: child pid[%ld],parent pid[%ld],grandparent pid[%ld]\n",pid,getpid(),getppid());
       
      // lseek(fd,0,SEEK_SET);
       
       fp = fdopen(fd[0],"r");                   //将文件描述符转换为文件流
      // while( read(fd,buf,sizeof(buf))>0 )
       while( fgets(buf,sizeof(buf),fp)>0 )     // 将父进程管道读端里的内容一行一行的读到buf里
       {
         if( strstr(buf,"inet addr:"))
         {
           printf("buf:%s\n",buf);
         }
       }
       fclose(fp);

    }


    return 0;
} /* ----- End of main() ----- */

