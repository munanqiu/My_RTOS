
#ifndef LIST_H
#define LIST_H

#include "portmacro.h"

struct xLIST_ITEM
{
    TickType_t xItemValue; //辅助值，用于帮助节点进行顺序排列
    struct xLIST_ITEM *pxNext;//指向链表下一个节点
    struct xLIST_ITEM *pxPrevious;//指向链表上一个节点
    void *pvOwner;//指向拥有该节点的内核对象，通常是TCB *
    void *pvContainer;//指向该节点所在的链表
};

typedef struct xLIST_ITEM ListItem_t; //节点数据类型重定义

struct xMINI_LIST_ITEM
{
    TickType_t xItemValue;/*辅助值，用于帮助节点进行升序排列*/
	struct xLIST_ITEM *pxNEXT;/*指向链表下一个节点*/
	struct xLIST_ITEM *pxPrevious;/*指向链表上一个节点*/
};
typedef struct xMINI_LIST_ITEM MiniListItem_t;

struct xLIST
{
    UBaseType_t uxNumberOfItems;//链表节点计数器
    ListItem_t * pxIndex;/*链表节点索引指针*/
    MiniListItem_t xListEnd;/*链表最后一个节点*/
};
typedef struct xLIST List_t;

#endif

