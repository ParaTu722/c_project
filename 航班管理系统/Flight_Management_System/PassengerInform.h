/*
�˿���Ϣ�Լ�����ͷ�ļ�
*/
#ifndef _PASSENGERINFORM_H
#define _PASSENGERINFORM_H


//�˿Ͷ�Ʊ�ṹ����Ϣ
typedef struct passenger_inform
{
	char p_flight_num[20];			//�����
	char date[20];					//����
	char name[20];					//�˿�����
	char identification_num[20];	//���֤��
	char seats_num[10];				//��λ��

}passenger_inform;

//�˿Ͷ�Ʊ�ṹ��ָ��
typedef struct Link_passenger
{
	passenger_inform data;
	struct Link_passenger *next;

}Link_passenger, *LinkList_passenger;



void init_passenger();
void flight_bookings();
void delete_flight_bookings();
void show_flight_bookings();

#endif

