/*********************************************************************************
 *      Copyright:  (C) 2018 Wang Tao
 *                  All rights reserved.
 *
 *       Filename:  pipe.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2018年05月12日)
 *         Author:  wang tao <TAlicer@163.com>
 *      ChangeLog:  1, Release initial version on "2018年05月12日 20时25分30秒"
 *                 
 ********************************************************************************/
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<stdio.h>

/********************************************************************************
 *  Description:
 *   Input Args:
 *  Output Args:
 * Return Value:
 ********************************************************************************/
int main (int argc, char **argv)
{
   int    pipefd[2];
   char   buf[64];

   if(pipe(pipefd) < 0)
    {
       printf("pipe failure: %s\n",strerror(errno));
       return 0;
    }
   
   write(pipefd[1],"Hello Word!\n",13);
   
   read(pipefd[0],buf,sizeof(buf));
   printf("buf: %s\n",buf);
    
    return 0;
} /* ----- End of main() ----- */

