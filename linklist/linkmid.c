/********************************************************************************* 
 *      Copyright:  (C) 2018 wangtao
 *                  All rights reserved.
 *
 *       Filename:  file.c 
 *    Description:  This file 
 *
 *        Version:  1.0.1(08/23/2018)
 *         Author:  WangTao <TAlicer@163.com>
 *      ChangeLog:  1, Release initial version on "08/23/2018 15:23:43"
 *
 ********************************************************************************/
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define OK        1
#define ERROR     0
#define OVERFLOW -2

typedef int ElemType;

typedef struct Node_s
{
    ElemType data;
    struct Node_s *next;

}Node,*LinkList;        //Node相当于struct Node_s    Linklist相当于struct Node_s *


//函数原型说明
int InitList(LinkList *head);
void CreateListTail(LinkList *head,int n);
int GetElem(LinkList *head,int i,ElemType e);
int Output_L(LinkList *head);
int GetMidNode(LinkList *head,ElemType *e);
int ListLength(LinkList *head);




int InitList(LinkList *head)  //创造一个空的单链表(带头节点的)

{
    *head=(LinkList)malloc(sizeof(Node));
    if(!(*head)) 
    exit(OVERFLOW);
	
    (*head)->next=NULL;
    (*head) = malloc(sizeof(Node));
    (*head)->data = 0x00;
    (*head)->next = NULL;
    return OK;

}//InitList


void CreateListTail(LinkList *head, int n) //按照尾插法随机插入n个元素(带头节点的)
{
    LinkList new_Node = NULL;
	LinkList tail = NULL;
	
    int i;
    srand(time(0));
    for(i=1;i<=n;i++)
    {
       new_Node=(LinkList)malloc(sizeof(Node));
       new_Node->data=rand()%100+1;
       new_Node->next = NULL;
	   
	   if((*head)->next == NULL)
	   {
		   (*head)->next = new_Node;
		   tail = new_Node;
	   }
	   else
	   {
		   tail->next = new_Node;           //这两句不能反
		   tail = new_Node;
	   }
    }
    
    printf("创建链表成功!\n"); 

}


int ListLength(LinkList *head)  //单链表的长度（带头节点的）
{
    int i=0;
    LinkList p=(*head)->next;
	
    while(p)
    {
		p=p->next;
        i++;
    }
    return i;
}

#if 0
int GetElem(LinkList *head, int i, ElemType e) //返回第i个元素
{
    if(!(*head))
    return ERROR;

    LinkList p;
    int j;
    p=(*head)->next;
        
    while(p&&j<i)
    {
       p=p->next;
       j++;
    }
	
    if(!p||j>i)
    return ERROR;
    e=p->data;
	
    return OK;

}//GetElem
#endif


int Link_reverse(LinkList *head) //单链表反转（带头节点的）
{
    if(*head == NULL)
    return  -1;
    //0、记录前一个节点与当前节点
    LinkList prevNode = (*head)->next;
    LinkList node = prevNode->next;
    //只要当前节点存在
    while(node != NULL)
    {
        //1、先记录当前节点的后一个节点
        LinkList nextNode = node->next;
        //2、让当前节点(node)的下一个节点(node->next)指向(=)前一个节点(prev)
        node->next = prevNode;
        //3、让前一个节点指向当前节点、当前节点指向原先记录的下一个节点
        prevNode = node;
        node = nextNode;
    }
    //4、让原来的第一个元素变为尾元素，尾元素的下一个置NULL
    (*head)->next->next = NULL;
    //5、让链表的头节点指向原来的尾元素
    (*head)->next = prevNode;

    return  0;
}


int Output_L(LinkList *head)  //输出单链表的元素(带头节点的)
{
    if(!(*head))
    return ERROR;

    LinkList p;
    p=(*head)->next;
	
    while(p!=NULL)
    {
      printf("%d ",p->data);
      p=p->next;
    }
	
    return OK;
}//output


int GetMidNode(LinkList *head, ElemType *e)//查找单链表中间元素(带头节点的)
{
    if(!(*head))
    return ERROR;

    LinkList mid,search;                //mid:慢指针，search:快指针
    mid=search=(*head)->next;
    
	while(search->next != NULL)
    {
      if (search->next->next != NULL)
      {
        search = search->next->next;
        mid = mid->next;
      }
      
      else
      {
        search = search->next;
      }      
    }
	
    *e=mid->data;
    return OK;
}

int ListInsert(LinkList *head, int i, ElemType new_data) //在i处插入一个为data的元素并输出
{
	if(!(*head))
    return ERROR;
	int      j=1;
	LinkList p1;
    p1 = (*head)->next;
	LinkList new_Node = NULL;
    new_Node=(LinkList)malloc(sizeof(Node));
	new_Node->data = new_data;
	
    while(p1 && (j<i-1))
	{
		p1=p1->next;
		j++;
	}
	new_Node->next = p1->next;
	p1->next = new_Node;
	
	Output_L(head);
    printf("\n");
    return 0;
}


int ListDelete(LinkList *head, int i) //删除在i处的元素并输出
{
	if(!(*head))
    return ERROR;

	int      j=1;
	LinkList p1,p2;
    p1 = (*head);
    while(j<i)
    {
        p1=p1->next;
        j++;
    }

    p2 = p1->next->next;
    free(p1->next);
    p1->next = p2;
    Output_L(head);
    printf("\n");

    return 0;
}


int main()
{
    LinkList head ;
    int      i,s,n=7;
    ElemType e,new_data;
    InitList(&head);
    
    printf("\n********************\n*带头节点的单链表   *\n********************\n");
    printf("请输入您选择的项目：\n 1.创建链表 2.查看链表\n 3.链表长度\
 4.链表反转\n 5.中间元素 6.插入元素\n 7.删除元素 0.退出\n");
	
    while(s!='0')
    {     
        scanf("%d",&s);
		
        switch(s)
        {
        case 1:
		        CreateListTail(&head,n); 
		        break;
        case 2:
		        Output_L(&head);
		        break;
        case 3:
		        printf("链表长度为：%d\n",ListLength(&head)); 
		        break;
        case 4: 
 		        Link_reverse(&head);
                printf("反转后的链表为：\n");
                Output_L(&head);
		        break;
        case 5: 
		        GetMidNode(&head,&e);
		        printf("中间元素为：%d\n",e);
				break;
        case 6:
		        printf("输入要插入的节点和数据\n");
				scanf("%d",&i);
				scanf("%d",&new_data);
				ListInsert(&head, i, new_data);
                break;
        case 7:
                printf("输入要删除的节点\n");
                scanf("%d",&i);
                ListDelete(&head, i);
                break;
        case 0: 
		        exit(0);
		        break;
        }
    }
        
}
