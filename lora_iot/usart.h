/********************************************************************************* 
 *      Copyright:  (C) 2018 wangtao
 *                  All rights reserved.
 *
 *       Filename:  usart.h
 *    Description:  This file 
 *
 *        Version:  1.0.1(05/20/2018)
 *         Author:  WangTao <TAlicer@163.com>
 *      ChangeLog:  1, Release initial version on "07/30/2018 03:09:43 AM"
 *
 ********************************************************************************/
#ifndef  _USART_H_
#define  _USART_H_

//串口相关的头文件    
#include<stdio.h>      /*标准输入输出定义*/    
#include<stdlib.h>     /*标准函数库定义*/    
#include<unistd.h>     /*Unix 标准函数定义*/    
#include<sys/types.h>     
#include<sys/stat.h>       
#include<fcntl.h>      /*文件控制定义*/    
#include<termios.h>    /*PPSIX 终端控制定义*/    
#include<errno.h>      /*错误号定义*/    
#include<string.h>    
 
#include "iot_mqtt.h"

//宏定义    
#define FALSE  0    
#define TRUE   1

extern int UART0_Open(char * port);
extern void UART0_Close(int fd) ; 

extern int UART0_Set(int fd,int speed,int flow_ctrl,int databits,int stopbits,int parity);
extern int UART0_Init(int fd, int speed,int flow_ctrl,int databits,int stopbits,int parity) ;
extern int UART0_Recv(int fd, char *rcv_buf,int data_len);
extern int UART0_Send(int fd, char *send_buf,int data_len);



#endif
