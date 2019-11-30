#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#define NAME 20
#define GENDER 20
#define TELE 12
#define ADDR 200
#define MAX 200//总存储量
#define DEFAULT 1
typedef struct info
{
	char name[NAME];
	char gender[GENDER];
	char tele[TELE];
	int age;
	int tall;
	char addr[ADDR];

}info;

//typedef struct Contact
//{
//	info data[MAX];
//	int size;
//}Contact, *pContact;

typedef struct Contact//内存动态存储
{
	info* data;
	int size;
	int capacity;
}Contact,*pContact;

void InitContact(pContact pc);//初始化
void AddContact(pContact pc);//添加信息
void DelContact(pContact pc);//删除
void SearchContact(pContact pc);//查找
int FindContact(pContact ,char* name);//寻找
void ModifyContact(pContact pc);//更改
void SortContact(pContact pc);//排序
void ShowContact(pContact pc);//打印
int CheckCapacity(pContact pc);
void LoadContact(pContact pc);
void SaveContact(pContact pc);