/*
�˵������ļ�
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include"menu.h"


//����Ԥ��������
void PowerOn_Animation()
{
	int i,j,k;
	int line = 6;
	for(k=0;k<3;k++)
	{
		system("color 5F");
		Sleep(500);
		printf("\t(������)");
	}
	printf("\n");
	for(i=0;i<line;i++)	
	{
		printf("\t\t");
		system("color 56");
		for(j=0;j<line-i-1;j++)
		{
			printf(" ");
			system("color 57");
			Sleep(20);
		}
		for(j=0;j<2*i+1;j++)
		{
			if(j==0 || j==2*i)
			{
				printf("��");
				Sleep(20);
				system("color 59");
			}
			else
			{
				printf(" ");
				Sleep(10);
				system("color 5F");
			}	
		}
		printf("\n");
	}
	
	for(i=1;i<line;i++)	
	{
		printf("\t\t");
		system("color 56");
		for(j=0;j<i;j++)
		{
			system("color 57");
			printf(" ");
			Sleep(10);
		}
		for(j=0;j<2*(line-i)-1;j++)
		{
			if(j==0 || j==2*(line-i)-2)
			{
				system("color 59");
				printf("��");
				Sleep(10);
			}
			else
			{
				system("color 5F");
				printf(" ");
				Sleep(10);
			}
		}
		printf("\n");
	}
	system("color 5F");
	printf("\n\t\tϵͳ��ʼ����");
	for(k=0;k<5;k++)
	{
		Sleep(300);
		printf(".");
	}
	printf("\n");
	printf("\n\t��ʼ���ɹ����������뺽�����ϵͳ!!!");
	Sleep(200);
	system("cls");
}


//�˵�����
int sys_memu()
{
	int a;
	system("color 71");

	printf("\t������������������������������\n");
	printf("\t��           ����1.��ʾ������Ϣ                       ��\n");
	printf("\t��           ����2.���Ӻ���                           ��\n");
	printf("\t��           ����3.ɾ������                           ��\n");
	printf("\t��           ����4.���ඩƱ                           ��\n");
	printf("\t��           ����5.������Ʊ                           ��\n");
	printf("\t��           ����6.����˿���ʾ                       ��\n");
	printf("\t��           ����7.�������:������Ϣ�����ļ�          ��\n");
	printf("\t��           ����8.���ļ�����:�������ɺ�����Ϣ        ��\n");
	printf("\t��           ����9.�ؼۺ���                           ��\n");
	printf("\t��           ����0.�˳��������ϵͳ                   ��\n");
	printf("\t������������������������������\n");
	printf("\t\t\t���������ѡ��:");
	scanf("%d",&a);
	printf("\n");
	return a;
}
