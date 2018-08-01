/********************************************************************************* 
 *      Copyright:  (C) 2018 wangtao
 *                  All rights reserved.
 *
 *       Filename:  port_mqtt.c 
 *    Description:  This file 
 *
 *        Version:  1.0.1(05/20/2018)
 *         Author:  WangTao <TAlicer@163.com>
 *      ChangeLog:  1, Release initial version on "07/30/2018 03:09:43 AM"
 *
 ********************************************************************************/
#include "port_mqtt.h"
#include "usart.h"

void *comport_worker(int fd); 
/******************************************************************************** 
 *  Description:
 *  Input Args:
 *  Output Args:
 *  Return Value:
 *******************************************************************************/
int main(int argc, char **argv)    
{   
    int fd = -1;                 //串口文件描述符    
    int err;                     //返回调用函数的状态    
  
 if((argc != 3) || (0 != strcmp(argv[2],"RZ" ) ))    
    {    
        printf("Usage: %s /dev/ttySn SZ(send data)/RZ (receive data) \n",argv[0]);
        printf("open failure : %s\n", strerror(errno));
        return FALSE; 
    }    
     fd = UART0_Open(fd,argv[1]); //打开串口，返回文件描述符   
     do  
    {    
        err = UART0_Init(fd,115200,0,8,1,'N');    
        printf("Set Port Exactly!\n");    
    }
	while(FALSE == err || FALSE == fd);    
   
   
    {
        pthread_t              tid1;
//		pthread_t              tid2;
 
        /* start serial port thread */
        pthread_create(&tid1,NULL, comport_worker, fd);  //创建一个线程执行函数comport_worker
    }
    
	while(1)
    {
    sleep(1);
    }
    
}	
   
void *comport_worker(int fd)
{
     
    char                   buf[1024];
    int                    rv = 0;
    int                    ofset = 0; 
    int                    i;

    char                   *A="temperature";
    char                   *B="humiture";
    char                   *C="door";
    _st_data               st_data;                                         //声明一个传感器数据结构体

    memset(&st_data, 0, sizeof(st_data));
    st_data.MessageType = (char *)malloc(14);
  
  while(1)
    {
      
        rv = UART0_Recv(fd,&buf[ofset], sizeof(buf)-ofset);                 //rv为read函数的返回值 
          

		
PARSER:                                                                     //开始解析数据
		if( rv < PACK_MIN_SIZE )
			continue;
		for(i=0; i<rv; i++)
        {
			if( (0xFE==buf[i]) && (rv-i)>11 && DOOR==buf[i+6] )             //对门开关量的解析
			{
				st_data.data_length=buf[i+1];                          //数据长度
				memcpy(st_data.MessageType, C, 13);
				st_data.st_device.ID=buf[i+4];                         //设备号
				st_data.st_device.Address=(buf[i+2]<<8)|(buf[i+3]);    //网络号
				st_data.st_device.Battery=buf[i+5];                    //电池电压
				st_data.st_device.SignalIntensity=buf[i+10];           //信号强度
				st_data.databuff[0]=buf[i+7];                          //门开关数据
				
				
				memmove(buf, &buf[i+st_data.data_length], (rv-(i+st_data.data_length)));
				
				rv=rv-st_data.data_length;
				 printf("Sensor type is [%s]\n",st_data.MessageType);
                 printf("Device_Address is [%d]\n",st_data.st_device.Address);
                 printf("Device_ID is [%d]\n",st_data.st_device.ID);
                 printf("Battery is [%d]\n",st_data.st_device.Battery);
                 printf("Data is [%d]\n\n",st_data.databuff[0]);
				goto  PARSER;
			}
			
			else if( (0xFE==buf[i]) && (rv-i)>12 && TEM==buf[i+6] )         //对温度数据的解析
			{
				st_data.data_length=buf[i+1];
				memcpy(st_data.MessageType, A, 13);
				st_data.st_device.ID=buf[i+4];
				st_data.st_device.Address=(buf[i+2]<<8)|(buf[i+3]);
				st_data.st_device.Battery=buf[i+5];
				st_data.st_device.SignalIntensity=buf[i+11];
				st_data.databuff[0]=buf[i+7];                          //温度整数部分
				st_data.databuff[1]=buf[i+8];                          //温度小数部分
				
				
				memmove(buf, &buf[i+st_data.data_length], (rv-(i+st_data.data_length)));
				
				rv=rv-st_data.data_length;
			    printf("Sensor type is [%s]\n",st_data.MessageType);
                printf("Device_Address is [%d]\n",st_data.st_device.Address);
                printf("Device_ID is [%d]\n",st_data.st_device.ID);
                printf("Battery is [%d]\n",st_data.st_device.Battery);
                printf("Data is [%d.%d℃]\n\n",st_data.databuff[0],st_data.databuff[1]);
				goto  PARSER;
			}
			
			else if( (0xFE==buf[i]) && (rv-i)>14 && HUM==buf[i+6] )         //对温湿度数据的解析
			{
				st_data.data_length=buf[i+1];
                memcpy(st_data.MessageType, B, 13);
				st_data.st_device.ID=buf[i+4];
				st_data.st_device.Address=(buf[i+2]<<8)|(buf[i+3]);
				st_data.st_device.Battery=buf[i+5];
				st_data.st_device.SignalIntensity=buf[i+11];
				st_data.databuff[0]=buf[i+7];                          //温度整数部分
				st_data.databuff[1]=buf[i+8];                          //温度小数部分
				st_data.databuff[2]=buf[i+9];                          //湿度整数部分
				st_data.databuff[3]=buf[i+10];                         //湿度小数部分
				
				
				memmove(buf, &buf[i+st_data.data_length], (rv-(i+st_data.data_length)));
				
				rv=rv-st_data.data_length;
				printf("Sensor type is [%s]\n",st_data.MessageType);
                printf("Device_Address is [%d]\n",st_data.st_device.Address);
                printf("Device_ID is [%d]\n",st_data.st_device.ID);
                printf("Battery is [%d]\n",st_data.st_device.Battery);
                printf("Data is [%d.%d℃,%d.%d%%]\n",st_data.databuff[0],st_data.databuff[1],st_data.databuff[2],st_data.databuff[3]);
				goto  PARSER;
			}	
			
		}
		ofset=rv;	
    }
    return NULL;
}
