/********************************************************************************
 *      Copyright:  (C) 2018 Wang Tao
 *                  All rights reserved.
 *
 *       Filename:  getnic.h
 *    Description:  This head file 
 *
 *        Version:  1.0.0(2018年05月12日)
 *         Author:  wang tao <TAlicer@163.com>
 *      ChangeLog:  1, Release initial version on "2018年05月12日 22时46分13秒"
 *                 
 ********************************************************************************/

#ifndef __GETNIC_H_
#define __GETNIC_H_

#define IPADDR_LEN         16

extern int getnic_addr (char *nic, char *ipaddr, char *netmask);

#endif
