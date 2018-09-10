/********************************************************************************* 
 *      Copyright:  (C) 2018 wangtao
 *                  All rights reserved.
 *
 *       Filename:  iot_mqtt.h
 *    Description:  This file 
 *
 *        Version:  1.0.1(05/20/2018)
 *         Author:  WangTao <TAlicer@163.com>
 *      ChangeLog:  1, Release initial version on "07/30/2018 03:09:43 AM"
 *
 ********************************************************************************/
 
#ifndef  _IOT_MQTT_H_
#define  _IOT_MQTT_H_

//#include "usart.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>  

#define PACK_MIN_SIZE          13      //最小数据包长度
#define TEM                    0x01    //温度传感器
#define HUM                    0x02    //温湿度传感器
#define DOOR                   0x03    //门开关


#define HOST                                     "192.168.0.5"
#define PORT       1883
#define KEEPLIVE   60
#define QOS        0
#define RETAIN     0



#define    debug_printf(...)   printf( __VA_ARGS__ )

typedef unsigned char      u8 ;
typedef unsigned short     u16;
typedef unsigned int       u32;  

typedef struct __st_data
{  
	 u8             message_Type   ;       //设备类型	 
	 u8             netaddr;               //网络号
	 u8             devaddr;               //设备号
	 double         battery_voltage;       //电池电压
	 u8             signal_strength;       //信号强度
	 u8             datapack      [4]  ;   //数据 
	 u8             message_time  [64];    //数据产生时间
     u8             serial_number [64];    //产品序列号 
	 u8             device_address[512];   //产品位置地址 
}_st_data; 

typedef struct __st_flag
{    
     u8             sta_port        ;       //0:串口未连接， 1：串口已连接
	 u8             sta_mqtt        ;       //0:mqtt未连接， 1：mqtt已连接
//	 u8             data_base       ;       //1:未将数据写到数据库，0：将数据写到数据库
	 int            port_fd         ;       //串口的fd   
	 int            thead_mqtt_exit ;       //0:mqtt 线程退出    1:保持连接  
	 
	 struct         mosquitto  *	mosq;
}_st_flag;


//返回值：     0 表示成功     >0 连接掉线，请复位st_flag->mqtt  <0 其他失败 
extern int mqtt_send_data(unsigned char *buff,struct  mosquitto  * mosq,const unsigned char *type);
void *     mqtt_worker(void  *	arg);

#endif

