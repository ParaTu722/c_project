/*
������Ϣ�Լ������ļ�
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"FlightInform.h"
#include"PassengerInform.h"

//�����ڴ�ռ��ʼ��
void init_flight_inform(LinkList *L)
{
	*L = (LinkList)malloc(sizeof (Link));
	(*L)->next = NULL;
	if(NULL == L)
	{
		printf("error\n");
	}
}


//��ʾ������Ϣ
void show_flight_information(LinkList L)
{
	int a;
	int i=0;	//��ʾ������
	system("color 72");
	if(NULL == L)
	{
		printf("!!!������ϢΪ��\n");
	}
	else
	{
		LinkList q = L->next;
		while(q)
		{
			printf("\n\t��%d�ܺ������Ϣ����:\n",i+1);
			printf("\t\t����ţ�%s\n",q->data.flight_number);
			printf("\t\t�����أ�%s\n",q->data.departure);
			printf("\t\tĿ�ĵأ�%s\n",q->data.destination);
			printf("\t\t���ʱ�䣺%s\n",q->data.departure_time);
			printf("\t\t����ʱ�䣺%s\n",q->data.landing_time);
			printf("\t\t�ɻ����ͣ�%s\n",q->data.aircraft_models);
			printf("\t\t��λ����%d\n",q->data.seats_number);
			printf("\t\t��Ʊ�۸�%d\n",q->data.price);
			q = q->next;
			i++;
		}
		printf("\n\n");
		printf("\t\t*************************************\n");
		printf("\t\t*          !!!��������Ļ!!!         *\n");
		printf("\t\t*            !!!     !!!            *\n");
		printf("\t\t*          �����ܺ�����:%d           *\n",i);
		printf("\t\t*************************************\n");
	}
	printf("\n!!!������ʾ���,����'0'�󷵻����˵�!!!\n");
	while(1)
	{
		scanf("%d",&a);
		if(a==0)
		{
			break;
		}
		else
		{
			printf("!!!�������������!!!\n");
			continue;
		}
	}
	system("cls");
}



//���Ӻ���
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

	printf("!!!�����뺽��ţ�");
	scanf("%s",&temp.flight_number);
	printf("!!!����������أ�");
	scanf("%s",&temp.departure);
	printf("!!!������Ŀ�ĵأ�");
	scanf("%s",&temp.destination);
	printf("!!!���������ʱ�䣺");
	scanf("%s",&temp.departure_time);
	printf("!!!�����뵽��ʱ�䣺");
	scanf("%s",&temp.landing_time);
	printf("!!!������ɻ����ͣ�");
	scanf("%s",&temp.aircraft_models);
	printf("!!!����������λ����");
	scanf("%d",&temp.seats_number);
	printf("!!!�������Ʊ�۸�");
	scanf("%d",&temp.price);

	p->data = temp;

	q->next = p;
	q = p;
	q->next = NULL;

	printf("\n!!!����������,����'0'�󷵻����˵�!!!\n");
	while(1)
	{
		scanf("%d",&a);
		if(a==0)
		{
			break;
		}
		else
		{
			printf("!!!�������������!!!\n");
			continue;
		}
	}
	system("cls");
}



//ɾ������
void delete_flight_information(LinkList L)
{
	char ft_num[20];
	int a;
	LinkList p = L->next;
	LinkList q = L;
	system("color 74");
	printf("\t��ѡ����Ҫɾ���ĺ���(��ʶ�𺽰��):\n");
	scanf("%s",&ft_num);

	while((NULL != p) && (strcmp(p->data.flight_number,ft_num) != 0))
	{
		p = p->next;
		q = q->next;
	}
	q->next = p->next;
	free(p);
	p = NULL;

	printf("\n!!!��ѡ����������,����'0'�󷵻����˵�!!!\n");
	while(1)
	{
		scanf("%d",&a);
		if(a==0)
		{
			break;
		}
		else
		{
			printf("!!!�������������!!!\n");
			continue;
		}
	}
	system("cls");
}


//�ؼۺ��ࣨ���۸����򣬴Ӵ�С��
//�����һ�����μӣ�����
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
		printf("!!!������ϢΪ��\n");
	}
	else
	{
		q = L->next;
		printf("\n\t�ؼۺ������Ϣ����(���۸���):\n\n");
		while(q)
		{
			printf("\t\t�����:%s\t��λ��:%d\n",q->data.flight_number,q->data.seats_number);
			printf("\t\t������:%s\tĿ�ĵ�:%s\n",q->data.departure,q->data.destination);
			printf("\t\t���ʱ��:%s\t����ʱ��:%s\n",q->data.departure_time,q->data.landing_time);
			printf("\t\t�����Ʊ�۸�:%d\n",q->data.price);
			printf("\n\t-----------------------------------------------\n");
			q = q->next;
			i++;

		}
		printf("\t\t*          �����ܺ�����:%d           *\n",i);
	}
	printf("\n!!!���л�Ʊ���ɰ���ʵ����ʾ���,����'0'�󷵻����˵�!!!\n");
	while(1)
	{
		scanf("%d",&a);
		if(a==0)
		{
			break;
		}
		else
		{
			printf("!!!�������������!!!\n");
			continue;
		}
	}
	system("cls");
}