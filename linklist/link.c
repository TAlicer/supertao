/********************************************************************************* 
 *      Copyright:  (C) 2018 wangtao
 *                  All rights reserved.
 *
 *       Filename:  1.c 
 *    Description:  This file 
 *
 *        Version:  1.0.1(08/23/2018)
 *         Author:  WangTao <TAlicer@163.com>
 *      ChangeLog:  1, Release initial version on "08/23/2018 15:23:43"
 *
 ********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node_s
{
    ElemType data;
    struct Node_s *next;

}Node,*LinkList;        //Node相当于struct Node_s    Linklist相当于struct Node_s *

#if 0
/*创建不带头节点的空链表*/
Status InitList(Linklist head)
{
	head = NULL;
}

/*创建带头节点的空链表*/
Status InitList(Linklist head)
{
	head
}
#endif


/*四种方法将数字1~10插入到链表中*/


/*尾插法-----------不带头节点*/
#if 0
int main()
{
   int  i;
   Node *head = NULL;
   Node *tail = NULL;
   Node *new_Node = NULL;

   for(i=0;i<10;i++)
   {
	  new_Node = malloc(sizeof(Node));
	  new_Node->data = i+1;               
	  new_Node->next = NULL;              //将即将要插入的节点打包(数据域放什么，指针域放什么)
	
      if(head == NULL)                    //如果为空链表
      {
	     head = new_Node;                //头指针指向第一个节点
		 tail = new_Node;                //尾指针指向第一个节点
      }
	  else
	  {
		 tail->next = new_Node;          //尾指针指向的节点(上一个节点)的指针域指向新插入的节点
		 tail = new_Node;                //这两句不能反
      }

    }
  
    Output_L(head);
}
#endif



/*尾插法-----------带头节点*/
#if 0
int main()
{
   int  i;
   Node *head = NULL;
   Node *tail = NULL;
   Node *new_Node = NULL;

   head = malloc(sizeof(Node));
   head->data = -1;
   head->next = NULL;

   for(i=0;i<10;i++)
   {
	   new_Node = malloc(sizeof(Node));
	   new_Node->data = i+1;
	   new_Node->next = NULL;
	
	   if(head->next == NULL)
	   {
		   head->next = new_Node;
		   tail = new_Node;
	   }
	   else
	   {
		   tail->next = new_Node;           //这两句不能反
		   tail = new_Node;
	   }
    }
   Output_HL(head);
}
#endif


/*头插法-----------不带头节点*/
#if 1
int main()
{
   int  i;
   Node *head = NULL;
   Node *tail = NULL;
   Node *new_Node = NULL;

   for(i=0;i<10;i++)
   {
	  new_Node = malloc(sizeof(Node));
	  new_Node->data = i+1;               
	  new_Node->next = NULL;              //将即将要插入的节点打包(数据域放什么，指针域放什么)
	  
      new_Node->next = head;
      head = new_Node;

    }
    
    printf("原链表\n");	
    Output_L(head);
	reverse(&head);
	printf("反转后的链表\n");	
	Output_L(head);
}
#endif

/*头插法-----------带头节点*/
#if 0
int main()
{
   int  i;
   Node *head = NULL;
   Node *new_Node = NULL;

   head = malloc(sizeof(Node));
   head->data = -1;
   head->next = NULL;

   for(i=0;i<10;i++)
   {
	   new_Node = malloc(sizeof(Node));
	   new_Node->data = i+1;
	   new_Node->next = NULL;

       new_Node->next = head->next;
       head->next = new_Node;
	
    }
    printf("原链表\n");	
    Output_HL(head);
	reverse_H(&head);
	printf("反转后的链表\n");	
	Output_HL(head);
}
#endif




int Output_L(LinkList head)  //输出不带头节点的单链表的元素
{ 
    if(!head)
    return -1;

    LinkList p;
    p=head;
	
    while(p!=NULL)
    {
      printf("%d ",p->data);
      p=p->next;
    }
	printf("\n");
    return 0;
}




int Output_HL(LinkList head)  //输出带头节点的单链表的元素
{ 
    if(!head)
    return -1;

    LinkList p;
    p=head->next;
	
    while(p!=NULL)
    {
      printf("%d ",p->data);
      p=p->next;
    }
	printf("\n");
    return 0;
}



//链表逆序
int reverse(LinkList *head)
{
 //   LinkList head = *h;
    if(*head == NULL)
    return  -1;
    //0、记录前一个节点与当前节点
    LinkList prevNode = *head;
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
    (*head)->next = NULL;
    //5、让链表的头节点指向原来的尾元素
    *head = prevNode;
    
    return  0;
}


int reverse_H(LinkList *head)
{

    if(*head == NULL)
    return  -1;
    LinkList prevNode = (*head)->next;
    LinkList node = prevNode->next;

    while(node != NULL)
    {
        LinkList nextNode = node->next;
        node->next = prevNode;
        prevNode = node;
        node = nextNode;
    }

    (*head)->next->next = NULL;
    (*head)->next = prevNode;
    
    return  0;
}
