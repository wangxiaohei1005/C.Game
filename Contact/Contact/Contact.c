#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include "Contact.h"
#include <malloc.h>
void InitContact(pContact pc)//初始化
{
	pc->size = 0;
	pc->data = (info*)malloc(sizeof(info)* DEFAULT);
	pc->capacity = DEFAULT;
}
int CheckCapacity(pContact pc)
{
	if (pc->size == pc->capacity)
	{
		//pc->data = (info*)realloc(pc->data, sizeof(info) * (pc->capacity + 10));
		info* tmp = (info*)malloc(sizeof(info)* (pc->capacity + 10));
		memcpy(tmp, pc->data, sizeof(info)* pc->size);
		free(pc-> data);
		pc->data = tmp;
		pc->capacity += 10;
	}
	return 1;
}
void AddContact(pContact pc)//添加信息
{
	info curInfo;
	if (CheckCapacity(pc) == 0)
	{
		printf("通讯录内存不足，无法添加！！！\n");
		return;
	}
	printf("请输入姓名：\n");
	scanf("%s", curInfo.name);
	printf("请输入性别：\n");
	scanf("%s", curInfo.gender);
	printf("请输入电话：\n");
	scanf("%s", curInfo.tele);
	printf("请输入年龄：\n");
	scanf("%d", &curInfo.age);
	printf("请输入身高：\n");
	scanf("%d", &curInfo.tall);
	printf("请输入地址：\n");
	scanf("%s", curInfo.addr);
	pc->data[pc->size] = curInfo;
	pc->size++;
}
void DelContact(pContact pc)//删除
{
	char name[NAME];
	printf("请输入你要删除的信息的姓名：\n");
	scanf("%s", name);
	int pos = FindContact(pc, name);
	if (pos == -1)
	{
		printf("此信息不存在，删除失败！！！\n");
		return;
	}
	for (int i = pos; i < pc->size; ++i)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->size--;
	printf("信息删除成功！！！\n");
}
void SearchContact(pContact pc)//查找
{
	char name[NAME];
	printf("请输入要查找的信息的姓名：\n");
	scanf("%s", name);
	int pos = FindContact(pc, name);
	if (pos == -1)
	{
		printf("查找失败，无此人！！！\n");
		return;
	}
	printf("************************************\n");
	printf("姓名：%s\n", pc->data[pos].name);
	printf("姓别：%s\n", pc->data[pos].gender);
	printf("电话：%s\n", pc->data[pos].tele);
	printf("年龄：%d\n", &pc->data[pos].age);
	printf("身高：%d\n", &pc->data[pos].tall);
	printf("地址：%s\n", pc->data[pos].addr);
	printf("************************************\n");
}
int FindContact(pContact pc, char* name)
{
	for (int i = 0; i < pc->size; ++i)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void ModifyContact(pContact pc)//更改
{
	char name[NAME];
	printf("请输入需要更改信息的姓名：\n");
	scanf("%s", name);
	int pos = FindContact(pc, name);
	if (pos == -1)
	{
		printf("此人信息不存在，更改失败！！！\n");
		return;
	}
	printf("请输入姓名：\n");
	scanf("%s", pc->data[pos].name);
	printf("请输入性别：\n");
	scanf("%s", pc->data[pos].gender);
	printf("请输入电话：\n");
	scanf("%s", pc->data[pos].tele);
	printf("请输入年龄：\n");
	scanf("%d", &pc->data[pos].age);
	printf("请输入身高：\n");
	scanf("%d", &pc->data[pos].tall);
	printf("请输入地址：\n");
	scanf("%s", pc->data[pos].addr);
	printf("更改完成！！！\n");
}
void SortContact(pContact pc)//排序(按照年龄)
{
	for (int sz = pc->size; sz > 0; --sz)//需排序的元素个数 
	{
		for (int i = 1; i < sz; ++i)
		{
 			if (strcmp(pc->data[i - 1].name, pc->data[i].name))
			{
				info tmp = pc->data[i - 1];
				pc->data[i - 1] = pc->data[i];
				pc->data[i] = tmp;
			}
		}
	}
}
void ShowContact(pContact pc)//打印
{
	for (int i = 0; i < pc->size; ++i)
	{
		printf("**************第%d个人**************\n", i);
		printf("************************************\n");
		printf("姓名：%s\n", pc->data[i].name);
		printf("姓别：%s\n", pc->data[i].gender);
		printf("电话：%s\n", pc->data[i].tele);
		printf("年龄：%d\n", pc->data[i].age);
		printf("身高：%d\n", pc->data[i].tall);
		printf("地址：%s\n", pc->data[i].addr);
		printf("************************************\n");
	}
}
void LoadContact(pContact pc)
{
	FILE* pF = fopen("contact.dat", "rb");
	if (pF == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	info curInfo;
	while (fread(&curInfo, sizeof(info), 1, pF))
	{
		if (CheckCapacity(pc))
		{
			pc->data[pc->size] = curInfo;
			pc->size++;
		}
	}
	fclose(pF);
}
void SaveContact(pContact pc)
{
	FILE* pF = fopen("contact.dat", "wb");
	if (pF == NULL)
	{
		printf("打开文件失败！！！\n");
		return;
	}
	for (int i = 0; i < pc->size; ++i)
	{
		fwrite(pc->data + i, sizeof(info), 1, pF);
	}
	fclose(pF);
}