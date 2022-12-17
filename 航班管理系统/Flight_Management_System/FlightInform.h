/*
������Ϣ�Լ�����ͷ�ļ�
*/
#ifndef _FLIGHTINFORM_H
#define _FLIGHTINFORM_H


//����ṹ����Ϣ
typedef struct flight_inform
{
	char flight_number[20];		//�����
	char departure[20];			//������
	char destination[20];		//Ŀ�ĵ�
	char departure_time[20];	//���ʱ��
	char landing_time[20];		//���ʱ��
	char aircraft_models[20];	//�ɻ�����
	int seats_number;			//��λ��
	int price;					//�۸�

}flight_inform;

//����ṹ��ָ��
typedef struct Link
{
	flight_inform data;
	struct Link *next;

}Link, *LinkList;

void init_flight_inform();
void show_flight_information();
void add_flight_information();
void delete_flight_information();
void PriceSorting();


#endif