/*********************************************************************************
 *      Copyright:  (C) 2018 Wang Tao
 *                  All rights reserved.
 *
 *       Filename:  daemon.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2018年05月13日)
 *         Author:  wang tao <TAlicer@163.com>
 *      ChangeLog:  1, Release initial version on "2018年05月13日 19时38分32秒"
 *                 
 ********************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/klog.h>
#include <syslog.h>
#include <stdarg.h>
#include <signal.h>
#include <string.h>
/********************************************************************************
 *  Description:
 *   Input Args:
 *  Output Args:
 * Return Value:
 ********************************************************************************/
void sig_proc(int signum)
{
    printf("receive signal [%d]\n",signum);
    if(signum == SIGALRM)
    {
       printf("alarm timeout,need weak up now\n");
    }
    return;
}

int main (int argc, char **argv)
{
    char *ptr=NULL;

    printf("Program %s start running\n",argv[0]);
    signal(SIGALRM,sig_proc);
    signal(SIGINT,sig_proc);
    signal(SIGSEGV,sig_proc);
    signal(SIGTERM,sig_proc);  //捕捉SIGTERM信号，如果程序收到SIGTERM信号，就调用sig_proc函数，并将信号的序号【SIGTERM是15】作为参数传给sig_proc函数

    
    strcpy(ptr,"hello");      //会导致栈（段）出错(指针出错),当一个进程执行了一个无效的内存引用，或发生段错误时系统会发送给它SIGSEGV信号
   
    alarm(10);  //10秒后，系统向本进程发一个SIGALRM信号，该信号默认动作是程序退出
    while(1)
    {
    
    }

    closelog();
    return 0;
} /* ----- End of main() ----- */
//killall -9 a.out命令是强制杀死该程序
