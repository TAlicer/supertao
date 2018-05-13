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

/********************************************************************************
 *  Description:
 *   Input Args:
 *  Output Args:
 * Return Value:
 ********************************************************************************/
int main (int argc, char **argv)
{
 
    pid_t  pid;

    pid=fork();
    if(pid <0)
    {
       printf("fork() error: %s\n",strerror(errno));
       return 0;
    }
    else if(pid == 0)
    {
       printf("starrt excute ifconfig eth0 command:\n");
       execl("/sbin/ifconfig","ifconfig","eth0",NULL);
       printf("####haha\n");
    }
    else if(pid > 0)
    {
       printf("Parent running: child pid[%ld],parent pid[%ld],grandparent pid[%ld]\n",pid,getpid(),getppid());
    }
    return 0;
} /* ----- End of main() ----- */

