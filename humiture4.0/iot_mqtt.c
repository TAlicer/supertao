#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>


#include "usart.h"
#include "mosquitto.h"
#include "iot_mqtt.h"



//返回值：     0 表示成功     >0  连接掉线，请复位st_flag->mqtt  <0 其他失败 
int mqtt_send_data(unsigned char *buff,struct  mosquitto  * mosq,int type)
{
	int            rt   = 0;  
	const unsigned char  *Str_Type[3] = {"temperature","sensirion","doorswitch"};
	
	rt = mosquitto_publish(mosq, NULL, Str_Type[type], 64, buff, QOS, RETAIN);

    switch(rt)
	{
		case MOSQ_ERR_SUCCESS:
			return 0;
		break;
		
		case MOSQ_ERR_NO_CONN :

		default:
		    debug_printf("Mosquitto Publish Failed:%s\n",mosquitto_strerror(rt));
		    return 1;
		break;
	}
	
	return -1;
}


void * mqtt_worker(void  *	arg)
{

	_st_flag  * st_flag       =  (_st_flag  *)arg;
	int     rt                = 0;
	struct  mosquitto *mosq   = st_flag->mosq;
	char    buff [128]        = {0};

	//建立连接
	rt = mosquitto_connect(mosq,HOST,PORT,KEEPLIVE);

	
	if(MOSQ_ERR_SUCCESS == rt)
	{
		st_flag->sta_mqtt   =   TRUE;
		debug_printf("Mosquitto Connect Succeed :%s\n",mosquitto_strerror(rt));
	}
	else
	{
		st_flag->sta_mqtt   =   FALSE;
		debug_printf("Mosquitto Connect Failed:%s\n",mosquitto_strerror(rt));
	}	

	while(st_flag->thead_mqtt_exit)
	{
		while(FALSE == st_flag->sta_mqtt)
		{
			//重新连接
			rt = mosquitto_connect(mosq,HOST,PORT,KEEPLIVE);
			//rt = mosquitto_reconnect(mosq);
			
			if(MOSQ_ERR_SUCCESS == rt)
			{
				st_flag->sta_mqtt   =   TRUE;
				debug_printf("Mosquitto Connect Succeed :%s\n",mosquitto_strerror(rt));
				
				if(0==(send_loradb_data(st_flag->mosq,type)))         //将数据库中的数据发送出去
				break;
			}
			else
			{
				st_flag->sta_mqtt   =   FALSE;
				
				debug_printf("Mosquitto Connect Failed:%s\n",mosquitto_strerror(rt));
			}	
			
			sleep(1);
		}
		
		while(TRUE == st_flag->sta_mqtt)
		{
			//保持连接
			rt = mosquitto_loop(mosq,-1,1);
			switch(rt)
			{
				case MOSQ_ERR_SUCCESS:
				break;
				
				case MOSQ_ERR_NO_CONN :
			
				default:
					st_flag->sta_mqtt   =   FALSE;
					debug_printf("Mosquitto loop Failed:%s\n",mosquitto_strerror(rt));
				break;
			}

			sleep(1);
		}
	}
	
	rt = mosquitto_disconnect(mosq);
    debug_printf("Mosquitto DisConnect:%s\n",mosquitto_strerror(rt));
	
	mosquitto_destroy(mosq);
	mosquitto_lib_cleanup();
	
	debug_printf("thead_mqtt_connect exited!\n");
	
	return NULL;
}




