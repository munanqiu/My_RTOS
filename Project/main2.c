/*链表节点插入实验*/

/*******************************************************
包含的头文件
********************************************************/

#include "list.h"
#include "stdint.h"
#include "stddef.h"

/*******************************************************
定义任务栈
*******************************************************/

#define TASK1_STACK_SIZE 128
StackType_t Task1Stack[TASK1_STACK_SIZE];

#define TASK2_STACK_SIZE 128
StackType_t Task2Stack[TASK2_STACK_SIZE];

/*定义任务控制块*/
TCB_t Task1TCB;
TCB_t Task2TCB;


uint32_t flag1;
uint32_t flag2;

void delay( count)
{
	for(; count!=0; count--);
}

void Task1_Entry( void *p_arg )
{
	for(;;)
	{
		flag1 = 1;
		dealy(100);
		flag1 = 0;
		delay(100);
	}
}

void Task2_Entry(void *p_arg)
{
	for(;;)
	{
		flag2 = 1;
		delay(100);
		flag2 = 0;
		delay(100);
	}
}


/********************************************************
main函数
********************************************************/

int main(void)
{

	for( ; ; )
	{
		flag1 = 1;
		delay(100);
		flag1 = 0;
		delay(100);

		flag2 = 1;
		delay(100);
		flag2 = 0;
		delay(100);
	}

}
