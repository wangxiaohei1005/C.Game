#include "Contact.h"
#include <stdio.h>
#include <string.h>
enum OPTION
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MOD,
	SHOW,
	SORT,
	SAVE,
	LOAD,
};

void menu()
{
	printf("***************************************************************\n");
	printf("********************  0.exit     1.add     ********************\n");
	printf("********************  2.del      3.search  ********************\n");
	printf("********************  4.modify   5.show    ********************\n");
	printf("********************  6.sort     7.load    ********************\n");
	printf("********************  8.save               ********************\n");
	printf("***************************************************************\n");
}
 
void testContact()
{
	int option;
	Contact ct;
	InitContact(&ct);
	do
	{
		menu();
		scanf("%d", &option);
		switch (option)
		{
		case EXIT:
			printf("您好，系统退出成功！！！\n");
			break;
		case ADD:
			AddContact(&ct);
			break;
		case DEL:
			DelContact(&ct);
			break;
		case SEARCH:
			SearchContact(&ct);
			break;
		case MOD:
			ModifyContact(&ct);
			break;
		case SHOW:
			ShowContact(&ct);
			break;
		case SORT:
			SortContact(&ct);
			break;
		case LOAD:
			LoadContact(&ct);
			break;
		case SAVE:
			SaveContact(&ct);
			break;
		default:
			printf("请注意，输入的选项有误！！！请重新输入！！！\n");
		}
	} while (option);
	
}

int main()
{
	testContact();
	return 0;
}