/*
�˿���Ϣ�Լ������ļ�
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"FlightInform.h"
#include"PassengerInform.h"


//�˿��ڴ�ռ��ʼ��
void init_passenger(LinkList_passenger *L)
{
	*L = NULL;
	*L = (LinkList_passenger)malloc(sizeof (Link_passenger));
	(*L)->next = NULL;
}


//���ඩƱ
void flight_bookings(LinkList_passenger LP, LinkList L)
{
	LinkList_passenger p,q;
	LinkList m = L->next;

	int a;
	int nums;	//��¼��λ��
	char fl_num;
	system("color F1");

	q = LP;

	while(NULL != q->next)
	{
		q = q->next;
	}
	p = (LinkList_passenger)malloc(sizeof(Link_passenger));

	printf("!!!�����뺽��ţ�");
	scanf("%s",&fl_num);
	while((NULL != m) && (strcmp(m->data.flight_number,&fl_num) != 0))	//����������ţ�ֱ�����󺽰����
	{
		m = m->next;
	}
	if(NULL == m)
	{
		printf("���಻����\n");
	}
	else	//������ڣ���¼����
	{
		printf("�������\n");
		strcpy(p->data.name , &fl_num);
		nums = m->data.seats_number;

		printf("!!!���������ڣ�");
		scanf("%s",&(p->data.date));
		printf("!!!������������");
		scanf("%s",&(p->data.name));
		printf("!!!���������֤�ţ�");
		scanf("%s",&(p->data.identification_num));
		printf("!!!������ѡ�����λ�ţ�");
		scanf("%s",&(p->data.seats_num));
		printf("\n\t\t������λ��ѡ��ʣ����λ��Ϊ:%d\n",nums-1);
		q->next = p;
		q = p;
		q->next = NULL;
	}

	printf("\n!!!��Ʊ���,����'0'�󷵻����˵�!!!\n");
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


//������Ʊ
void delete_flight_bookings(LinkList_passenger LP)
{
	int a;
	char name[20];

	LinkList_passenger p =LP->next;
	LinkList_passenger q = LP;

	system("color F2");
	printf("��ѡ����Ʊ��:\n");
	scanf("%s",&name);

	while((NULL != p) && (strcmp(p->data.name,name) != 0))	//�������е����ݽ��бȶ�
	{
		p = p->next;
		q = q->next;
	}
	q->next = p->next;
	free(p); 
	p=NULL;

	printf("\n!!!��Ʊ���,����'0'�󷵻����˵�!!!\n");
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



//����˿���ʾ
void show_flight_bookings(LinkList_passenger LP)
{
	int a;
	system("color F3");
	if(NULL == LP)
	{
		printf("!!!�ѹ���Ʊ��ϢΪ��\n");
	}
	else
	{
		LinkList_passenger p = LP->next;
		while(p)
		{
			printf("************!!!%s����/Ůʿ,������%s�㵽��Ŀ�ĵ�\n",p->data.name,p->data.date);
			p = p->next;
		}
	}

	printf("\n!!!�ѹ���Ʊ��ʾ���,����'0'�󷵻����˵�!!!\n");
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