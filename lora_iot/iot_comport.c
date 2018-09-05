#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>

#include "iot_comport.h"
#include "usart.h"
#include "iot_mqtt.h"


/********************************************************************  
* 名称：            UART0_Time  
* 功能：            获取系统时间  
* 入口参数：        st_data      数据包结构体      
*                     
*                     
* 出口参数：        无  
*******************************************************************/  
char *  get_time(void)              //获取系统时间
{    
    time_t       now_time     = {0};	
	struct tm   *st_now_time = NULL;
    static       u8  pack[32] = {0};
	
	time(&now_time);
	st_now_time = localtime(&now_time);
	
	if(NULL == st_now_time)
	{
		return NULL;
	}
	
    snprintf(pack,sizeof(pack),"%04d\\%02d\\%02d %02d:%02d:%02d",st_now_time->tm_year+1900,\
	st_now_time->tm_mon+1,  st_now_time->tm_mday,  st_now_time->tm_hour ,\
	st_now_time->tm_min,st_now_time->tm_sec);
	
	return   pack;
}  


void *comport_worker(void *arg)
{
	_st_flag               *st_flag = (_st_flag *)arg; 
    _st_data               st_data   = {0};

	
    int                    i;    
	int                    rv = 0;
	int                    type;
	int                    len = 0;
    int                    ofset = 0; 
	char                   buf[1024];                                             //用于串口接收
    unsigned char          pack[1024]  = {0};                                     //将解析好的数据打包
	int                    data_length = 0;
	
	if( arg != st_flag ) 
    {
        printf("Invalid arguments\n");
        return NULL;
    }
	
  
    while(1)
    {
        
        rv = UART0_Recv(st_flag->port_fd, &buf[len], sizeof(buf)-len);                 //rv为read函数的返回值 
        if(rv > 0)
           len+=rv;		

PARSER:                                                                              //开始解析数据
		if( len < PACK_MIN_SIZE )
			continue;
	
		for(i=0; i<len; i++)
        {

        	if( (LORA_PACK_TAG==buf[i]) && (len-i)>11 && DOOR==buf[i+6] )             //对门开关量的解析
			{
				data_length=buf[i+1];                                //数据长度

				st_data.message_Type=buf[i+6];                       //传感器类型
				st_data.devaddr=buf[i+4];                            //设备号
				st_data.netaddr=(buf[i+2]<<7)|(buf[i+3]);            //网络号
				st_data.battery_voltage=buf[i+5];                    //电池电压
				st_data.signal_strength=buf[i+10];                   //信号强度
				st_data.datapack[0]=buf[i+7];                        //门开关数据
				
				strncpy(st_data.message_time,get_time(),sizeof(st_data.message_time));  //获取系统时间
				
				/*从数据库中获取产品序列号和设备物理地址*/
				if( query_loradb_id(st_data.serial_number, st_data.device_address, st_data.netaddr, st_data.devaddr) < 0) 
				{
                  printf("Throw data from unknow LoRa[%d:%d]\n", st_data.netaddr, st_data.devaddr);
				}
				
				/*将数据打包到pack中*/
				snprintf(pack,sizeof(pack),"%s,%4.2f,%d,%s,%s,%d", st_data.serial_number,(st_data.battery_voltage)/51, \
				st_data.signal_strength,st_data.device_address,st_data.message_time,st_data.datapack[0]);
				
				type = 2;

                if((mqtt_send_data(pack, st_flag->mosq,type)))        //通过mqtt发送
				{
			
					write_loradb_data(pack);                          //如果mqtt连接中断，将数据写到数据库中
					
				}	
			
//				while(st_flag->sta_mqtt   ==  FALSE)
//				{
//				 if(st_flag->sta_mqtt   ==  TRUE)                      //如果mqtt连接成功
//				 {
//			
//                  if(!(send_loradb_data(st_flag->mosq,type)))         //将数据库中的数据发送出去
//
//                 break;		
//				 }
//				}

                memset(&st_data,0,sizeof(_st_data));
				memmove(buf, &buf[i+data_length], (len-(i+data_length)));				
				len -= (i+data_length);

				goto  PARSER;
			}
			
			else if( (LORA_PACK_TAG==buf[i]) && (len-i)>12 && TEM==buf[i+6] )         //对温度数据的解析
			{
				data_length=buf[i+1];                                //数据长度

				st_data.message_Type=buf[i+6];                       //传感器类型
				st_data.devaddr=buf[i+4];                            //设备号
				st_data.netaddr=(buf[i+2]<<7)|(buf[i+3]);            //网络号
				st_data.battery_voltage=buf[i+5];                    //电池电压
				st_data.signal_strength=buf[i+11];                   //信号强度
				st_data.datapack[0]=buf[i+7];                        //温度整数部分
				st_data.datapack[1]=buf[i+8];                        //温度小数部分
				
				strncpy(st_data.message_time,get_time(),sizeof(st_data.message_time));   //获取系统时间
				
				/*从数据库中获取产品序列号和设备物理地址*/
				if( query_loradb_id(st_data.serial_number, st_data.device_address, st_data.netaddr, st_data.devaddr) < 0) 
				{
                  printf("Throw data from unknow LoRa[%d:%d]\n", st_data.netaddr, st_data.devaddr);
				}
				/*将数据打包到pack中*/
				snprintf(pack,sizeof(pack),"%s,%4.2f,%d,%s,%s,%d.%d", st_data.serial_number,(st_data.battery_voltage)/51, \
				st_data.signal_strength,st_data.device_address,st_data.message_time,st_data.datapack[0],st_data.datapack[1]);
				
				type = 0;
				if((mqtt_send_data(pack, st_flag->mosq,type)))        //通过mqtt发送
				{
					write_loradb_data(pack);                          //如果mqtt连接中断，将数据写到数据库中
					
				}	
				
				
//				while(st_flag->sta_mqtt   ==  FALSE)
//				{
//				 if(st_flag->sta_mqtt   ==  TRUE)                      //如果mqtt连接成功
//				 {
//
//                  if(!(send_loradb_data(st_flag->mosq,type)))         //将数据库中的数据发送出去
//			      break;		
//				 }
//				}

                memset(&st_data,0,sizeof(_st_data));
				memmove(buf, &buf[i+data_length], (len-(i+data_length)));				
				len -= (i+data_length);

				goto  PARSER;
			}
			
			else if( (LORA_PACK_TAG==buf[i]) && (len-i)>15 && HUM==buf[i+6] )         //对温湿度数据的解析
			{
				data_length=buf[i+1];                                 //数据长度

				st_data.message_Type=buf[i+6];                        //传感器类型
				st_data.devaddr=buf[i+4];                             //设备号
				st_data.netaddr=(buf[i+2]<<7)|(buf[i+3]);             //网络号
				st_data.battery_voltage=buf[i+5];                     //电池电压
				st_data.signal_strength=buf[i+13];                    //信号强度
				st_data.datapack[0]=buf[i+7];                         //温度整数部分
				st_data.datapack[1]=buf[i+8];                         //温度小数部分
				st_data.datapack[2]=buf[i+9];                         //湿度整数部分
				st_data.datapack[3]=buf[i+10];                        //湿度小数部分

				strncpy(st_data.message_time,get_time(),sizeof(st_data.message_time));   //获取系统时间
				
				/*从数据库中获取产品序列号和设备物理地址*/
				if( query_loradb_id(st_data.serial_number, st_data.device_address, st_data.netaddr, st_data.devaddr) < 0) 
				{
                  printf("Throw data from unknow LoRa[%d:%d]\n", st_data.netaddr, st_data.devaddr);
				}
				/*将数据打包到pack中*/
				snprintf(pack,sizeof(pack),"%s,%4.2f,%d,%s,%s,%d.%d,%d.%d", st_data.serial_number,(st_data.battery_voltage)/51,st_data.signal_strength, \
				st_data.device_address,st_data.message_time,st_data.datapack[0],st_data.datapack[1],st_data.datapack[2],st_data.datapack[3]);
				
				type = 1;
				if((mqtt_send_data(pack, st_flag->mosq,type)))        //通过mqtt发送
				{
					write_loradb_data(pack);                          //如果mqtt连接中断，将数据写到数据库中
					
				}	
				
//				while(st_flag->sta_mqtt   ==  FALSE)
//				{
//				 if(st_flag->sta_mqtt   ==  TRUE)                      //如果mqtt连接成功
//				 {
//
//                 if(!(send_loradb_data(st_flag->mosq,type)))         //将数据库中的数据发送出去
//			      break;		
//				 }
//				}	

                memset(&st_data,0,sizeof(_st_data));
				memmove(buf, &buf[i+data_length], (len-(i+data_length)));				
				len -= (i+data_length);

				goto  PARSER;
			}	
			
		}	
    }
    return NULL;
}




/*从数据库中获取产品序列号和设备物理地址,返回值：0 （成功），<0（失败）*/

int query_loradb_id(unsigned char *serial_number,unsigned char *device_address, u8 netaddr, u8 devaddr)
{
   sqlite3 *db;
   char                     sql[128];           //存放sqlite命令
   char                     **result;           //存放查询到的结果
   int                      rownum;             //查询到的总行数
   int                      colnum;             //查询到的总列数
   char                     *errmsg = NULL;     //存放出错原因
   int                      rv = 0;
   int                      rc;	
   rc = sqlite3_open("lora1.db", &db);
   
   if( rc )
   {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return 0;
   }
   else
   {  
      fprintf(stderr, "Opened database1 successfully\n");
   }
   memset(sql, 0, sizeof(sql));
   snprintf(sql, sizeof(sql), "select id from lora where netaddr=%d and devaddr=%d;\
   select address from lora where netaddr=%d and devaddr=%d;",netaddr, devaddr,netaddr, devaddr);
  
   if( SQLITE_OK != sqlite3_get_table(db, sql, &result, &rownum, &colnum, &errmsg) )
   { 
        printf("query lora ID from database failure: %s\n", errmsg);
        sqlite3_free(errmsg);
        rv = -4;
        goto out;
   }
    
   if(  rownum <= 0 )
   {
        printf("can't find lora ID for netaddr<0x%04x> devaddr<0x%04x> in DB\n",netaddr, devaddr);
        rv = -3;
        goto out;
   }
   strncpy(serial_number, result[1], 16);
   strncpy(device_address, result[2], 32);

out:
 
   sqlite3_close(db);
   return rv;
}




/*将未发送的数据写到数据库中,返回值：0 （成功），1（失败）*/

int write_loradb_data(unsigned char *pack)
{
   sqlite3 *db;
   char                     sql[128];
   int                      rv = 0;
   char                     *zErrMsg = 0;
   int                      rc;  
   rc = sqlite3_open("lora1.db", &db);                                              //打开数据库
 //printf("unsend data is %s\n",pack); 
   if( rc )
   {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return 0;
   }
   else
   {  
      fprintf(stderr, "Opened database2 successfully\n");
   }
   memset(sql, 0, sizeof(sql));
   snprintf(sql, sizeof(sql), "INSERT INTO MESSAGE VALUES (NULL, '%s', 1);",pack);  //输入执行的命令
   
    rc = sqlite3_exec(db, sql, NULL, NULL, &zErrMsg);                               //执行命令
   if( rc != SQLITE_OK )                                                            //<sqlite3.h>中SQLITE_OK = 0；
   {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
	  rv = -1;
   }
   else
   {
      fprintf(stdout, "Operation done successfully\n");
	  rv = 0;
   }
   
   sqlite3_close(db);
   return rv;
}


/*将数据库中未发送的数据发出去, 返回值：0 （成功），非0（失败）*/

int send_loradb_data(struct  mosquitto  * mosq,int type)
{
   sqlite3                  *db;
   char                     *zErrMsg = 0;                    //zErrMsg将被返回用来获取程序生成的任何错误。
   char                     sql_1[128];
   char                     sql_2[128];
   unsigned char            pack[128];
   char                     **result;
   int                      rownum;      //查询到的总行数
   int                      colnum;      //查询到的总列数
   char                     *errmsg = NULL;
   int                      rv=0;
   int                      rc;
   int                      i;
   rc = sqlite3_open("lora1.db", &db);

   if( rc )
   {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return 0;
   }
   else
   {  
      fprintf(stderr, "Opened database3 successfully\n");
   }

    memset(sql_1, 0, sizeof(sql_1));
    memset(sql_2, 0, sizeof(sql_2));
	memset(pack, 0, sizeof(pack));
    snprintf(sql_1, sizeof(sql_1), "select data from message where flag=1;");
    
    if( SQLITE_OK == sqlite3_get_table(db, sql_1, &result, &rownum, &colnum, &errmsg) )
    { 
      for(i=1;i<=rownum;i++)
      {
		strncpy(pack, result[i], 128); 
        rv=mqtt_send_data(pack, mosq,type);
        snprintf(sql_2, sizeof(sql_2), "delete from message where id=%d;",i);
        sqlite3_exec(db, sql_2, NULL, NULL, &zErrMsg);
         
      }
    
    }	
printf("rv=%d\n",rv);	
    sqlite3_close(db);
	return rv;
}


