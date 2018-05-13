/*********************************************************************************
 *      Copyright:  (C) 2018 Wang Tao
 *                  All rights reserved.
 *
 *       Filename:  main.c
 *    Description:  This file 
 *                 
 *        Version:  1.0.0(2018年05月12日)
 *         Author:  wang tao <TAlicer@163.com>
 *      ChangeLog:  1, Release initial version on "2018年05月12日 22时47分48秒"
 *                 
 ********************************************************************************/
#include <stdio.h>
#include "getnic.h"

/********************************************************************************
 *  Description:
 *   Input Args:
 *  Output Args:
 * Return Value:
 ********************************************************************************/
int main (int argc, char **argv)
{
    char         ipaddr[IPADDR_LEN];    
    char         netmask[IPADDR_LEN];

    if( getnic_addr("eth0", ipaddr, netmask)<0 )    
    { 
        return -1;   
    }

    printf("eth0 ipaddr: %s  netmask: %s\n", ipaddr, netmask);

    
    
    if( getnic_addr("virbr0", ipaddr, netmask)<0 )
    {
        return -1;
    }

    printf("virbr0 ipaddr: %s  netmask: %s\n", ipaddr, netmask);
    return 0;
} /* ----- End of main() ----- */

