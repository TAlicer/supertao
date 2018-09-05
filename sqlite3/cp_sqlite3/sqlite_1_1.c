

//连接到一个现有的数据库。如果数据库不存在，那么它就会被创建，最后将返回一个数据库对象。

#include <stdio.h>
#include <sqlite3.h>
#include <string.h>

int main(int argc, char* argv[])
{
   sqlite3 *db;
   char *zErrMsg = 0;                    //zErrMsg将被返回用来获取程序生成的任何错误。
   int rc;
   char                     sql[128];
   char                     sql1[128];
   char                     **result;
   unsigned char            lora[128];
   int                      rownum;
   int                      colnum;
   char                     *errmsg = NULL;
   int                      rv = 0;
   int                      i;
   rc = sqlite3_open("lora1.db", &db);

   if( rc )
   {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return 0;
   }
   else
   {  
      fprintf(stderr, "Opened database successfully\n");
   }

    memset(sql, 0, sizeof(sql));
    memset(sql, 0, sizeof(sql1));
    memset(lora, 0, sizeof(lora));
    snprintf(sql, sizeof(sql), "select data from message where flag=1;");
    
    if( SQLITE_OK == sqlite3_get_table(db, sql, &result, &rownum, &colnum, &errmsg) )
    { 
      for(i=1;i<=rownum;i++)
     {
        strncpy(lora, result[i], 64);
        printf("result : %s\n",lora);
        snprintf(sql1, sizeof(sql), "delete from message where id=%d;",i);
        sqlite3_exec(db, sql1, NULL, NULL, &zErrMsg);
         
      }
    
    }

//    strncpy(lora_id, result[1], 64);            //将查询到的结果放到入口参数lora_id中
//    strncpy(salary, result[2], 64);
//    printf("result1 : %s\n",result[1]);
//    printf("result2 : %s\n",salary);
//    printf("行 : %d\n",rownum);
//    printf("列 : %d\n",colnum);

   sqlite3_close(db);
}
