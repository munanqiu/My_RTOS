/*链表节点插入实验*/

/*******************************************************
包含的头文件
********************************************************/

#include "list.h"

/*******************************************************
全局变量
*******************************************************/

/*定义链表根节点*/
struct xLIST List_test;

/*定义节点*/
struct xLIST_ITEM List_Item1;
struct xLIST_ITEM List_Item2;
struct xLIST_ITEM List_Item3;


/********************************************************
main函数
********************************************************/

int main(void)
{
	/*链表根节点初始化*/
	vListInitialise( &List_test );

	/*三个节点初始化*/
	vListInitialiseItem( &List_Item1);
	List_Item1.xItemValue = 1;

	vListInitialiseItem( &List_Item2);
	List_Item2.xItemValue = 2;

	vListInitialiseItem( &List_Item3);
	List_Item3.xItemValue = 3;


	/*将节点插入链表，按照升序排列*/
	vListInsert( &List_test, &List_Item1 );
	vListInsert(& List_test, & List_Item2);
	vListInsert( &List_test, &List_Item3);


	for( ; ; )
	{
		/*什么也不做*/
	}

}
