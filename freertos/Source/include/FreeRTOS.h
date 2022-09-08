#ifndef FREERTOS_H
#define FREERTOS_H

typedef struct tskTaskControlBlock
{
	volatile StackType_t *pxTopOfStack;/*栈顶*/
	ListItem_t xStateListItem;/*任务节点*/
	StackType_t *pxStack; /*任务栈起始地址*/

	char pcTaskName[ConfigMAX_TASK_NAME_LEN];
}tskTCB;

typedef tskTCB TCB_t;

#endif/*FREERTOS_CONFIG_H*/
