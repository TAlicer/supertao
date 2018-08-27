#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>

#include "mosquitto.h"
#include "iot_mqtt.h"
#include "iot_comport.h"
#include "usart.h"

/******************************************************************************** 
 *  Description:
 *  Input Args:
 *  Output Args:
 *  Return Value:
 *******************************************************************************/
int main(int argc, char **argv)    
{   
        
    int                    err;                    
    pthread_t              tid1;
    pthread_t              tid2;
	
    _st_flag               st_flag  = 
	{
	   .sta_port        =   FALSE,         //0:串口未连接， 1：串口已连接
 	   .sta_mqtt        =   FALSE,         //0:mqtt未连接， 1：mqtt已连接

       .port_fd         =   -1,            //串口的fd  
       .thead_mqtt_exit =   TRUE ,         //0:mqtt 线程退出    1:保持连接  
 
       .mosq            =   NULL,
	};  //声明一个传感器数据结构体

    mosquitto_lib_init();

	st_flag.mosq = mosquitto_new(NULL,true,NULL);

	if(NULL == st_flag.mosq )
	{
		printf("create mosq failure :\n");
		return -1;
	}

	
 	if(argc != 3)    
    {    
        printf("Usage: %s /dev/ttySn 0(send data)/1 (receive data) \n",argv[0]);
        printf("open failure : %s\n", strerror(errno));
    
        return -1;    
    } 
	
 	if((argc != 3)||(0!= strcmp(argv[2],"RZ"))) 
    { 
        printf("Usage: %s /dev/ttySn SZ(send data)/RZ (receive data) \n",argv[0]);
        printf("open failure : %s\n", strerror(errno));
    
        return -1; 
    }	 

   do  
    {   
        st_flag.port_fd = UART0_Open(argv[1]); //打开串口，返回文件描述符	
        err = UART0_Init(st_flag.port_fd,115200,0,8,1,'N');    
        printf("Set Port Exactly!\n");    
    }
	while(FALSE == err || FALSE == st_flag.port_fd);    


	
  
    /* start serial port thread */
    err = pthread_create(&tid1,NULL, comport_worker,&st_flag);  //创建一个线程执行函数comport_worker
	debug_printf("pthread_create comport_worker:%s\n",strerror(err));
	if(0 != err)
	{
		return 0;
	}



	
	err = pthread_create(&tid2,NULL, mqtt_worker,    &st_flag);     //创建一个线程执行函数mqtt_worker
	debug_printf("pthread_create mqtt_worker:%s\n",strerror(err));
    if(0 != err)
	{
		return 0;
	}

     
    while(1)  
    {			
        sleep(1);
    }
 
    return 0; 

}	
