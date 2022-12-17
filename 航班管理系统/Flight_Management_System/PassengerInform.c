/*
乘客信息以及函数文件
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"FlightInform.h"
#include"PassengerInform.h"


//乘客内存空间初始化
void init_passenger(LinkList_passenger *L)
{
	*L = NULL;
	*L = (LinkList_passenger)malloc(sizeof (Link_passenger));
	(*L)->next = NULL;
}


//航班订票
void flight_bookings(LinkList_passenger LP, LinkList L)
{
	LinkList_passenger p,q;
	LinkList m = L->next;

	int a;
	int nums;	//记录座位数
	char fl_num;
	system("color F1");

	q = LP;

	while(NULL != q->next)
	{
		q = q->next;
	}
	p = (LinkList_passenger)malloc(sizeof(Link_passenger));

	printf("!!!请输入航班号：");
	scanf("%s",&fl_num);
	while((NULL != m) && (strcmp(m->data.flight_number,&fl_num) != 0))	//遍历链表航班号，直至所求航班存在
	{
		m = m->next;
	}
	if(NULL == m)
	{
		printf("航班不存在\n");
	}
	else	//航班存在，记录数据
	{
		printf("航班存在\n");
		strcpy(p->data.name , &fl_num);
		nums = m->data.seats_number;

		printf("!!!请输入日期：");
		scanf("%s",&(p->data.date));
		printf("!!!请输入姓名：");
		scanf("%s",&(p->data.name));
		printf("!!!请输入身份证号：");
		scanf("%s",&(p->data.identification_num));
		printf("!!!请输入选择的座位号：");
		scanf("%s",&(p->data.seats_num));
		printf("\n\t\t航班座位已选，剩余座位数为:%d\n",nums-1);
		q->next = p;
		q = p;
		q->next = NULL;
	}

	printf("\n!!!购票完成,输入'0'后返回主菜单!!!\n");
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


//航班退票
void delete_flight_bookings(LinkList_passenger LP)
{
	int a;
	char name[20];

	LinkList_passenger p =LP->next;
	LinkList_passenger q = LP;

	system("color F2");
	printf("请选择退票人:\n");
	scanf("%s",&name);

	while((NULL != p) && (strcmp(p->data.name,name) != 0))	//与链表中的数据进行比对
	{
		p = p->next;
		q = q->next;
	}
	q->next = p->next;
	free(p); 
	p=NULL;

	printf("\n!!!退票完毕,输入'0'后返回主菜单!!!\n");
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



//航班乘客显示
void show_flight_bookings(LinkList_passenger LP)
{
	int a;
	system("color F3");
	if(NULL == LP)
	{
		printf("!!!已购机票信息为空\n");
	}
	else
	{
		LinkList_passenger p = LP->next;
		while(p)
		{
			printf("************!!!%s先生/女士,您将在%s点到达目的地\n",p->data.name,p->data.date);
			p = p->next;
		}
	}

	printf("\n!!!已购机票显示完毕,输入'0'后返回主菜单!!!\n");
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