/*********************************************************************************
 *      Copyright:  (C) 2018 Wang Tao
 *                  All rights reserved.
 *
 *       Filename:  thread.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2018年05月15日)
 *         Author:  wang tao <TAlicer@163.com>
 *      ChangeLog:  1, Release initial version on "2018年05月15日 00时34分04秒"
 *                 
 ********************************************************************************/
#include <pthread.h>
#include <stdio.h>

int  g_var = 10;

/*线程一*/
void *thread_worker1(void *args)  //参数为void *类型的函数可以接受任意一种类型的指针
{
    int   times = 0;


    while(1)
    {
       printf("thread1: g_var++=%d\n",g_var++);
        sleep(1);
    }
    
    printf("thread1 start exit now\n");
    return NULL;
}

/* 线程二*/
void *thread_worker2(void *args)  //参数为void *类型的函数可以接受任意一种类型的指针
 {
     int   times = 0;
 
 
     while(1)
     { 
        printf("thread2: g_var++=%d\n",g_var++);
         sleep(1);
     }  
          
     printf("thread2 start exit now\n");
     return NULL;
        
 }
 /********************************************************************************
 *  Description:
 *   Input Args:
 *  Output Args:
 * Return Value:
 ********************************************************************************/
int main (int argc, char **argv)   //写多线程的程序，编译时一定要链接线程的动态库(gcc thread.c -lpthread )
{
    pthread_t   tid1;
    pthread_t   tid2;
    pthread_t   tid3;
    int         times = 0;
    
    pthread_create(&tid1,NULL,thread_worker1,"cat");
    printf("start thread_worker1 [%lu]\n",tid1);

    pthread_create(&tid2,NULL,thread_worker2,"dog");
    printf("start thread_worker2 [%lu]\n",tid2);
    
    while(1)
    {
        printf("g_var=%d\n",g_var++);
        sleep(1);
    }

    printf("master/control thread start exit now\n");  //主线程退出会导致整个进程退出
    return 0;
} /* ----- End of main() ----- */

