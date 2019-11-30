#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include "Contact.h"
#include <malloc.h>
void InitContact(pContact pc)//��ʼ��
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
void AddContact(pContact pc)//�����Ϣ
{
	info curInfo;
	if (CheckCapacity(pc) == 0)
	{
		printf("ͨѶ¼�ڴ治�㣬�޷���ӣ�����\n");
		return;
	}
	printf("������������\n");
	scanf("%s", curInfo.name);
	printf("�������Ա�\n");
	scanf("%s", curInfo.gender);
	printf("������绰��\n");
	scanf("%s", curInfo.tele);
	printf("���������䣺\n");
	scanf("%d", &curInfo.age);
	printf("��������ߣ�\n");
	scanf("%d", &curInfo.tall);
	printf("�������ַ��\n");
	scanf("%s", curInfo.addr);
	pc->data[pc->size] = curInfo;
	pc->size++;
}
void DelContact(pContact pc)//ɾ��
{
	char name[NAME];
	printf("��������Ҫɾ������Ϣ��������\n");
	scanf("%s", name);
	int pos = FindContact(pc, name);
	if (pos == -1)
	{
		printf("����Ϣ�����ڣ�ɾ��ʧ�ܣ�����\n");
		return;
	}
	for (int i = pos; i < pc->size; ++i)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->size--;
	printf("��Ϣɾ���ɹ�������\n");
}
void SearchContact(pContact pc)//����
{
	char name[NAME];
	printf("������Ҫ���ҵ���Ϣ��������\n");
	scanf("%s", name);
	int pos = FindContact(pc, name);
	if (pos == -1)
	{
		printf("����ʧ�ܣ��޴��ˣ�����\n");
		return;
	}
	printf("************************************\n");
	printf("������%s\n", pc->data[pos].name);
	printf("�ձ�%s\n", pc->data[pos].gender);
	printf("�绰��%s\n", pc->data[pos].tele);
	printf("���䣺%d\n", &pc->data[pos].age);
	printf("��ߣ�%d\n", &pc->data[pos].tall);
	printf("��ַ��%s\n", pc->data[pos].addr);
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

void ModifyContact(pContact pc)//����
{
	char name[NAME];
	printf("��������Ҫ������Ϣ��������\n");
	scanf("%s", name);
	int pos = FindContact(pc, name);
	if (pos == -1)
	{
		printf("������Ϣ�����ڣ�����ʧ�ܣ�����\n");
		return;
	}
	printf("������������\n");
	scanf("%s", pc->data[pos].name);
	printf("�������Ա�\n");
	scanf("%s", pc->data[pos].gender);
	printf("������绰��\n");
	scanf("%s", pc->data[pos].tele);
	printf("���������䣺\n");
	scanf("%d", &pc->data[pos].age);
	printf("��������ߣ�\n");
	scanf("%d", &pc->data[pos].tall);
	printf("�������ַ��\n");
	scanf("%s", pc->data[pos].addr);
	printf("������ɣ�����\n");
}
void SortContact(pContact pc)//����(��������)
{
	for (int sz = pc->size; sz > 0; --sz)//�������Ԫ�ظ��� 
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
void ShowContact(pContact pc)//��ӡ
{
	for (int i = 0; i < pc->size; ++i)
	{
		printf("**************��%d����**************\n", i);
		printf("************************************\n");
		printf("������%s\n", pc->data[i].name);
		printf("�ձ�%s\n", pc->data[i].gender);
		printf("�绰��%s\n", pc->data[i].tele);
		printf("���䣺%d\n", pc->data[i].age);
		printf("��ߣ�%d\n", pc->data[i].tall);
		printf("��ַ��%s\n", pc->data[i].addr);
		printf("************************************\n");
	}
}
void LoadContact(pContact pc)
{
	FILE* pF = fopen("contact.dat", "rb");
	if (pF == NULL)
	{
		printf("�ļ���ʧ��\n");
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
		printf("���ļ�ʧ�ܣ�����\n");
		return;
	}
	for (int i = 0; i < pc->size; ++i)
	{
		fwrite(pc->data + i, sizeof(info), 1, pF);
	}
	fclose(pF);
}