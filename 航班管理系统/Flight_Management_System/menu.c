/*
菜单界面文件
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include"menu.h"


//程序预启动界面
void PowerOn_Animation()
{
	int i,j,k;
	int line = 6;
	for(k=0;k<3;k++)
	{
		system("color 5F");
		Sleep(500);
		printf("\t(￣▽￣)");
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
				printf("⊙");
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
				printf("⊙");
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
	printf("\n\t\t系统初始化中");
	for(k=0;k<5;k++)
	{
		Sleep(300);
		printf(".");
	}
	printf("\n");
	printf("\n\t初始化成功，即将进入航班管理系统!!!");
	Sleep(200);
	system("cls");
}


//菜单界面
int sys_memu()
{
	int a;
	system("color 71");

	printf("\t★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
	printf("\t★           ☆☆☆1.显示航班信息                       ★\n");
	printf("\t★           ☆☆☆2.增加航班                           ★\n");
	printf("\t★           ☆☆☆3.删除航班                           ★\n");
	printf("\t★           ☆☆☆4.航班订票                           ★\n");
	printf("\t★           ☆☆☆5.航班退票                           ★\n");
	printf("\t★           ☆☆☆6.航班乘客显示                       ★\n");
	printf("\t★           ☆☆☆7.航班存盘:航班信息存入文件          ★\n");
	printf("\t★           ☆☆☆8.从文件调入:重新生成航班信息        ★\n");
	printf("\t★           ☆☆☆9.特价航班                           ★\n");
	printf("\t★           ☆☆☆0.退出航班管理系统                   ★\n");
	printf("\t★★★★★★★★★★★★★★★★★★★★★★★★★★★★★\n");
	printf("\t\t\t请做出你的选择:");
	scanf("%d",&a);
	printf("\n");
	return a;
}
