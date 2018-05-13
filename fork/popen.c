/*********************************************************************************
 *      Copyright:  (C) 2018 Wang Tao
 *                  All rights reserved.
 *
 *       Filename:  popen.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2018年05月12日)
 *         Author:  wang tao <TAlicer@163.com>
 *      ChangeLog:  1, Release initial version on "2018年05月12日 21时14分17秒"
 *                 
 ********************************************************************************/
#include <stdio.h>
#include <string.h>
#include <errno.h>
/********************************************************************************
 *  Description:
 *   Input Args:
 *  Output Args:
 * Return Value:
 ********************************************************************************/
int main (int argc, char **argv)
{
    FILE   *fp;
    char   buf[512];
    char   *p1,*p2,*p3;
    char   ipaddr[16];
    char   netmask[16];

    fp = popen("ifconfig eth0","r");
    if( fp == NULL)
    {
      printf("popen failure: %s\n",strerror(errno));
      return 0;
    }

    while( fgets(buf,sizeof(buf),fp)>0)
    {
      if( (p1=strstr(buf,"inet addr:")) !=NULL)  //p1指向含有"inet addr:"关键词这一行的首地址
      {

          //printf("%s",buf);

          p2=strchr(p1,':');   //p2指向p1行第一个冒号处
          p3=strchr(p2,' ');   //p2指向p2以后第一个空格处
          memset(ipaddr,0,sizeof(ipaddr));
          strncpy(ipaddr,p2+1,p3-p2);      //截取IP地址到ipaddr数组中
          printf("IP address: %s\n",ipaddr);
         
          p2=strrchr(p1, ':');   //p2指向p1行最后一个冒号处
          p3=strrchr(p2, '\n');  //p3指向p2以后最后一个换行符处（在p1行中）
          memset(netmask, 0, sizeof(netmask));
          strncpy(netmask, p2+1, p3-p2);    //截取Mask地址到netmask数组中
          printf("Netmask address: %s\n", netmask);
      }
    }
    pclose(fp);

    return 0;
} /* ----- End of main() ----- */

