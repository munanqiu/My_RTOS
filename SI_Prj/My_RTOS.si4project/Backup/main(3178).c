//struct node
//{
//    struct node *next;
//	char data1;
//	unsigned char array[];
//	unsigned long *prt;
//	struct userstruct data2;
//	/*......*/
//}

struct node
{
	  struct node  *next;
}

struct userstruct
{
	  struct node *next;
	  char data1[100];
		int data2;
}

int main(void)
{
		int a = 1;
		int i = 0;
		while(1)
		{
				for(i=1;i<10;i++)
				{
						a++;
				}
		}
}