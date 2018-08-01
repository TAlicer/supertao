/********************************************************************************* 
 *      Copyright:  (C) 2018 wangtao
 *                  All rights reserved.
 *
 *       Filename:  port_mqtt.h
 *    Description:  This file 
 *
 *        Version:  1.0.1(05/20/2018)
 *         Author:  WangTao <TAlicer@163.com>
 *      ChangeLog:  1, Release initial version on "07/30/2018 03:09:43 AM"
 *
 ********************************************************************************/
 
#ifndef  _PORT_MQTT_H_
#define  _PORT_MQTT_H_
 
#include "usart.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>  
 
typedef unsigned int       u32;   // uint32_t 
typedef unsigned short     u16;
typedef unsigned char *    u8 ;
typedef struct  __st_device
{
    u32            ID;                 //设备号
    u32            Address;            //网络号
    int            Battery;            //电池电压
    int            SignalIntensity;    //信号强度

}_st_device;

typedef struct __st_data
{   
    u16            data_length;       
    u8             MessageType;        //传感器类型
    _st_device     st_device;
    int            databuff[4];
}_st_data; 

#define PACK_MIN_SIZE          13      //最小数据包长度
#define TEM                    0x01    //温度传感器
#define HUM                    0x02    //温湿度传感器
#define DOOR                   0x03    //门开关
 
#endif   /* ----- #ifndef _PORT_MQTT_H_  ----- */
