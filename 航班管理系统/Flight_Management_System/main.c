/*
�������ļ���ʵ�ֶԸ������ܺ����ĵ���
*/
#include<stdio.h>
#include<stdlib.h>
#include"menu.h"
#include"FlightInform.h"
#include"PassengerInform.h"
#include"FileOperation.h"


void main()
{
	LinkList L;
	LinkList_passenger LP;
	
	//�����ʼ��
	init_flight_inform(&L);
	init_passenger(&LP);

	//��������
	PowerOn_Animation();
	//����ѡ��
	while(1)
	{
		switch(sys_memu())
		{
			case 1:
				//��ʾ������Ϣ
				show_flight_information(L);
				break;

			case 2:
				//���Ӻ���
				add_flight_information(L);
				break;

			case 3:
				//ɾ������
				delete_flight_information(L);
				break;

			case 4:
				//���ඩƱ
				flight_bookings(LP,L);
				break;

			case 5:
				//������Ʊ
				delete_flight_bookings(LP);
				break;

			case 6:
				//��Ʊ��ʾ
				show_flight_bookings(LP);
				break;

			case 7:
				//�������
				record_in_file(L);
				break;

			case 8:
				//���ļ����Ӻ���
				add_finform_in_file(L);
				break;

			case 9:
				//�ؼۺ��ࣨ���۸���
				PriceSorting(L);
				break;

			case 0:
				printf("!!!���˺������ϵͳ!!!\n");
				exit(0);

			default:
				printf("!!!�������������ѡ��!!!\n");
				system("cls");
				break;
		}
	}
}
