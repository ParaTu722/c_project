/*
文件操作函数文件
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"FlightInform.h"
#include"PassengerInform.h"
#include"FileOperation.h"



//航班存盘:航班信息存入文件
void record_in_file(LinkList L)
{
	FILE *fp = NULL;
	int a;
	system("color 04");
	fp = fopen("flight_inform.txt","a");
	if(NULL == fp)
	{
		printf("!!!ERROR!!!\n");
	}
	if(NULL == L)
	{
		printf("航班信息为空\n");
	}
	else
	{
		LinkList q = L->next;
		while(q)
		{
			fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\n", 
				q->data.flight_number,q->data.departure,q->data.destination,
				q->data.departure_time,q->data.landing_time,q->data.aircraft_models,
				q->data.seats_number,q->data.price);

			q = q->next;
		}
	}
	printf("\n!!!航班信息已存入文件flight_inform.txt中,输入'0'后返回主菜单!!!\n");
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
	fclose(fp);
	system("cls");
}


//从文件调入:重新生成航班信息
void add_finform_in_file(LinkList L)
{
	FILE *fp = NULL;
	LinkList p,q=L;
	int a;
	system("color 04");

	fp = fopen("flight_inform.txt","rt+");
	if(NULL == fp)
	{
		printf("!!!ERROR!!!\n");
	}
	while(NULL != q->next)
	{
		q = q->next;
	}
	
	while( !feof(fp) )
	{
		p = (LinkList)malloc(sizeof(Link));
		fscanf(fp, "%s\t%s\t%s\t%s\t%s\t%s\t%d\t%d\n" ,
			&p->data.flight_number,&p->data.departure,&p->data.destination,
			&p->data.departure_time,&p->data.landing_time,&p->data.aircraft_models,
			&p->data.seats_number,&p->data.price);

		q->next = p;
		q = p;
		q->next = NULL;
	}
	printf("\n!!!航班信息已重新生成,输入'0'后返回主菜单!!!\n");
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
	fclose(fp);
	system("cls");
	
}
