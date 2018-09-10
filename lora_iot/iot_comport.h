#ifndef  _IOT_UART_H_
#define  _IOT_UART_H_



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>

//#include "iot_comport.h"
#include "usart.h"
#include "iot_mqtt.h"
#include "sqlite3.h"

#define   LORA_PACK_TAG         0xFE

void *comport_worker(void *arg);
char *  get_time(void);
int query_loradb_id(unsigned char *serial_number,unsigned char *device_address, u8 netaddr, u8 devaddr);
int write_loradb_data(unsigned char *buff,unsigned char *type);
int send_loradb_data(struct  mosquitto  * mosq);


#endif

