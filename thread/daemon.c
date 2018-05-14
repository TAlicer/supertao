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
/********************************************************************************
 *  Description:
 *   Input Args:
 *  Output Args:
 * Return Value:
 ********************************************************************************/
int main (int argc, char **argv)
{
   
    daemon(0,0);  //将本进程设置为一个守护进程（自动后台运行）,第一个参数为0时,即可将工作目录修改为根目录，第二个参数为0时,输入,输出以及错误输出重定向到/dev/null 。

    openlog("testlog",LOG_CONS|LOG_PID,0); //syslog将本程序的日志信息记录到/var/log/messages中，"testlog"为该日志信息的标识，第三个参数“0”是什么？CONS是什么？

    syslog(LOG_EMERG,"Program %s start running\n",argv[0]);

    while(1)
    {
        ;
    }

    closelog();
    return 0;
} /* ----- End of main() ----- */
//日志记录到文件 /var/log/messages
