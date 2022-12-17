/*
航班信息以及函数文件
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"FlightInform.h"
#include"PassengerInform.h"

//航班内存空间初始化
void init_flight_inform(LinkList *L)
{
	*L = (LinkList)malloc(sizeof (Link));
	(*L)->next = NULL;
	if(NULL == L)
	{
		printf("error\n");
	}
}


//显示航班信息
void show_flight_information(LinkList L)
{
	int a;
	int i=0;	//显示航班数
	system("color 72");
	if(NULL == L)
	{
		printf("!!!航班信息为空\n");
	}
	else
	{
		LinkList q = L->next;
		while(q)
		{
			printf("\n\t第%d架航班的信息如下:\n",i+1);
			printf("\t\t航班号：%s\n",q->data.flight_number);
			printf("\t\t出发地：%s\n",q->data.departure);
			printf("\t\t目的地：%s\n",q->data.destination);
			printf("\t\t起飞时间：%s\n",q->data.departure_time);
			printf("\t\t到达时间：%s\n",q->data.landing_time);
			printf("\t\t飞机机型：%s\n",q->data.aircraft_models);
			printf("\t\t座位数：%d\n",q->data.seats_number);
			printf("\t\t机票价格：%d\n",q->data.price);
			q = q->next;
			i++;
		}
		printf("\n\n");
		printf("\t\t*************************************\n");
		printf("\t\t*          !!!机场大屏幕!!!         *\n");
		printf("\t\t*            !!!     !!!            *\n");
		printf("\t\t*          今日总航班数:%d           *\n",i);
		printf("\t\t*************************************\n");
	}
	printf("\n!!!航班显示完毕,输入'0'后返回主菜单!!!\n");
	while(1)
	{
		scanf("%d",&a);
		if(a==0)
		{
			break;
		}
		else
		{
			printf("!!!输入错误，请重试!!!\n");
			continue;
		}
	}
	system("cls");
}



//增加航班
void add_flight_information(LinkList L)
{
	
	LinkList p,q;
	int a;

	flight_inform temp;

	q = L;
	while(NULL != q->next)
	{
		q = q->next;
	}
	p = (LinkList)malloc(sizeof(Link));
	system("color 73");

	printf("!!!请输入航班号：");
	scanf("%s",&temp.flight_number);
	printf("!!!请输入出发地：");
	scanf("%s",&temp.departure);
	printf("!!!请输入目的地：");
	scanf("%s",&temp.destination);
	printf("!!!请输入起飞时间：");
	scanf("%s",&temp.departure_time);
	printf("!!!请输入到达时间：");
	scanf("%s",&temp.landing_time);
	printf("!!!请输入飞机机型：");
	scanf("%s",&temp.aircraft_models);
	printf("!!!请输入总座位数：");
	scanf("%d",&temp.seats_number);
	printf("!!!请输入机票价格：");
	scanf("%d",&temp.price);

	p->data = temp;

	q->next = p;
	q = p;
	q->next = NULL;

	printf("\n!!!航班添加完毕,输入'0'后返回主菜单!!!\n");
	while(1)
	{
		scanf("%d",&a);
		if(a==0)
		{
			break;
		}
		else
		{
			printf("!!!输入错误，请重试!!!\n");
			continue;
		}
	}
	system("cls");
}



//删除航班
void delete_flight_information(LinkList L)
{
	char ft_num[20];
	int a;
	LinkList p = L->next;
	LinkList q = L;
	system("color 74");
	printf("\t请选择你要删除的航班(仅识别航班号):\n");
	scanf("%s",&ft_num);

	while((NULL != p) && (strcmp(p->data.flight_number,ft_num) != 0))
	{
		p = p->next;
		q = q->next;
	}
	q->next = p->next;
	free(p);
	p = NULL;

	printf("\n!!!所选航班输出完毕,输入'0'后返回主菜单!!!\n");
	while(1)
	{
		scanf("%d",&a);
		if(a==0)
		{
			break;
		}
		else
		{
			printf("!!!输入错误，请重试!!!\n");
			continue;
		}
	}
	system("cls");
}


//特价航班（按价格排序，从大到小）
//排序第一个不参加？？？
void PriceSorting(LinkList L)
{
	int a;
	int i=0;
	flight_inform temp;

	LinkList p=L->next;
	LinkList q=L;
	system("color 2F");
	while(p != NULL)
	{
		while(p->next != NULL)
		{
			if(p->data.price < p->next->data.price)
			{
				temp = p->data;
				p->data = p->next->data;
				p->next->data = temp;
			}
			p = p->next;
		}
		p =q->next;
		q = p;
	}
	if(NULL == L)
	{
		printf("!!!航班信息为空\n");
	}
	else
	{
		q = L->next;
		printf("\n\t特价航班的信息如下(按价格降序):\n\n");
		while(q)
		{
			printf("\t\t航班号:%s\t座位数:%d\n",q->data.flight_number,q->data.seats_number);
			printf("\t\t出发地:%s\t目的地:%s\n",q->data.departure,q->data.destination);
			printf("\t\t起飞时间:%s\t到达时间:%s\n",q->data.departure_time,q->data.landing_time);
			printf("\t\t★★★机票价格:%d\n",q->data.price);
			printf("\n\t-----------------------------------------------\n");
			q = q->next;
			i++;

		}
		printf("\t\t*          今日总航班数:%d           *\n",i);
	}
	printf("\n!!!所有机票已由昂贵到实惠显示完毕,输入'0'后返回主菜单!!!\n");
	while(1)
	{
		scanf("%d",&a);
		if(a==0)
		{
			break;
		}
		else
		{
			printf("!!!输入错误，请重试!!!\n");
			continue;
		}
	}
	system("cls");
}