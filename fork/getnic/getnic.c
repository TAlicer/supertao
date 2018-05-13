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
#include "getnic.h"
/********************************************************************************
 *  Description:
 *   Input Args:
 *  Output Args:
 * Return Value:
 ********************************************************************************/
int getnic_addr (char *nic, char *ipaddr,char *netmask)
{
    FILE   *fp;
    char   buf[512];
    char   *p1,*p2,*p3;
    int    rv = -2;

    memset(buf,0,sizeof(buf));
    snprintf(buf,sizeof(buf),"ifconfig %s",nic);

    fp = popen(buf,"r");
    if( fp == NULL)
    {
      printf("popen failure: %s\n",strerror(errno));
      return -1;
    }

    while( fgets(buf,sizeof(buf),fp)>0)
    {
      if( (p1=strstr(buf,"inet addr:")) !=NULL)
      {

          //printf("%s",buf);

          p2=strchr(p1,':');
          p3=strchr(p2,' ');
          memset(ipaddr,0,sizeof(ipaddr));
          strncpy(ipaddr,p2+1,p3-p2);
         
          p2=strrchr(p1, ':');
          p3=strrchr(p2, '\n');
          memset(netmask, 0, sizeof(netmask));
          strncpy(netmask, p2+1, p3-p2);

          rv = 0;
      }
    }
    pclose(fp);

    return rv;
}

