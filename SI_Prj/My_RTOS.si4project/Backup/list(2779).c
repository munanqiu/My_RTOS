#include "list.h"

/*链表节点初始化*/
void vListInitialiseItem(ListItem_t * const pxItem)
{
    /*初始化该节点所在的链表为空，表示节点还没有插入任何链表*/
    pxItem->pvContainer=NULL;
}

/*链表根节点初始化*/
void vListInitialise(List_t * const pxList)
{
	/*将链表索引指针指向最后一个节点*/
	pxList->pxIndex = (ListItem_t *)&(pxList->xListEnd);
	/*将链表最后一个节点的辅助排序的值设置为最大，确保该节点就是链表的最后节点*/
	pxList->xListEnd.xItemValue = portMAX_DELAY;
	/*将最后一个节点的pxNext和pxPrevious指针均指向节点自身，表示链表为空*/
	pxList->xListEnd.pxNext = (ListItem_t *) &(pxList->xListEnd);
	pxList->xListEnd.pxPrevious = (ListItem_t *)&(pxList->xListEnd);
	/*初始化链表节点计数器的值为0，表示链表为空*/
	pxList->uxNumberOfItems = (UBaseType_t) 0U;
}

/*将节点插入链表的尾部*/
void vListInsertEnd(List_t * const pxList, ListItem_t * const pxNewListItem)
{
	ListItem_t * const pxIndex = pxList->pxIndex;

	pxNewListItem->pxNext = pxIndex;
	pxNewListItem->pxPrevious = pxIndex->pxPrevious;
	pxIndex->pxPrevious->pxNext = pxNewListItem;
	pxIndex->pxPrevious = pxNewListItem;

	/*记住根节点所在的链表*/
	pxNewListItem->pvContainer = (void *)pxList;

	/*链表节点计数器++*/
	(pxList->uxNumberOfItems)++;
}

/*将节点按照升序排列插入链表*/
void vListInsert(List_t * const pxList, ListItem_t * const pxNewListItem)
{
	ListItem_t *pxIterator;

	/*获取节点的排序辅助值*/
	const TickType_t xValueOfInsertion = pxNewListItem->xItemValue;

	/*寻找节点要插入的位置*/
	if(xValueOfInsertion == portMAX_DELAY)
	{
			pxIterator = pxList->xListEnd.pxPrevious;
	}
	else
	{
		for(pxIterator = (ListItem_t *)&(pxList->xListEnd);
				pxIterator->pxNext->xItemValue <= xValueOfInsertion;
				pxIterator = pxIterator->pxNext)
		{
			/*不作任何事情，不断迭代只是为了找到节点要插入的位置*/
		}
	}

	/*根据升序排列，将节点插入*/
	pxNewListItem->pxNext = pxIterator->pxNext;
	pxNewListItem->pxNext->pxPrevious = pxNewListItem;
	pxNewListItem->pxPrevious = pxIterator;
	pxIterator->pxNext = pxNewListItem;

	/*链表节点计数器++*/
	(pxList->uxNumberOfItems)++;
		
}

/*将节点从链表中删除*/
UBaseType_t uxListRemove(ListItem_t * const pxItemToRemove)
{
	/*获取节点所在的链表*/
	List_t * const pxList = (List_t *)pxItemToRemove->pvContainer;
	/*将指定的节点从链表删除*/
	pxItemToRemove->pxNext->pxPrevious = pxItemToRemove->pxPrevious;
	pxItemToRemove->pxPrevious->pxNext = pxItemToRemove->pxNext;

	/*调整链表的节点索引指针*/
	if(pxList->pxIndex == pxItemToRemove)
	{
		pxList->pxIndex = pxItemToRemove->pxPrevious;
	}

	/*初始化该节点所在的链表为空，表示节点还没有插入任何链表*/
	pxItemToRemove->pvContainer = NULL;

	/*链表计数器--*/
	(pxList->uxNumberOfItems)--;

	/*返回链表中剩余节点的个数*/
	return pxList->uxNumberOfItems;
}

/*节点带参宏函数*/
/*初始化节点的拥有者*/
#define listSET_LIST_ITEM_OWNER( pxListItem, pxOwner )\
	((pxListItem)->pvOwner = (void * )(pxOwner))

/*获取节点拥有者*/
#define listGET_LIST_ITEM_OWNER( pxListItem)\
	(( pxListItem )->pvOwner)

/*初始化节点排序辅助值*/
#define listSET_LIST_ITEM_VALUE( pxListItem)\
	((pxListItem)->xItemValue = (xValue))

/*获取节点排序辅助值*/
#define listGet_LIST_ITEM_VALUE(pxListItme)\
	((pxListItem)->xItemValue)

/*获取链表根节点的节点计数器的值*/
#define listGET_ITEM_VALUE_OF_HEAD_ENTRY( pxList )\
	((( pxList )->xListEnd ).pxNext->xItemValue )

/*获取链表的入口节点*/
#define listGet_HEAD_ENTRY( pxList )\
	((( pxList )->xListEnd ).pxNext )

/*获取节点的下一个节点*/
#define listGET_NEXT( pxListItem )\
	(( pxListItme )-> pxNext)

/*获取链表的最后一个节点*/
#define listGET_END_MARKER( pxList )\
	((ListItem_t const * ) (&(( pxList )->xListEnd)))

/*判断链表是否为空*/
#define listLIST_IS_EMPTY( pxList )\
	(( BaseType_t )(( pxList )->uxNumberOfItems == (UBaseType_t) 0 ))

/*获取链表的节点数*/
#define listCURRENT_LIST_LENGTH( pxList )\
	((pxList )->uxNumberOfItems )

/*获取链表第一个节点的OWNER，即TCB*/
//#define listGET_OWNER_OF_NEXT_ENTRY( pxTCB, pxList )
//{
//	List_t const pxConstList = ( pxList );
//	/*节点索引指向链表的第一个节点*/  \
//	( pxConstList )->pxIndex = ( pxConstList)->pxIndex->pxNext;
//	/*这个操作有什么用*/ \
//	if(( void* )( pxConstList )->pxIndex == ( void* ) &((pxConstList)->xListEnd ))\
//	{
//		( pxConstList )->pxIndex = ( pxConstList )->pxIndex->pxNEXT;
//	}
//	/*获取节点的OWNER， 即TCB*/\
//	( pxTCB ) = ( pxConstList )->pxIndex->pvOwner;
//}

