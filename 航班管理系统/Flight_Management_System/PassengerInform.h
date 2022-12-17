/*
乘客信息以及函数头文件
*/
#ifndef _PASSENGERINFORM_H
#define _PASSENGERINFORM_H


//乘客订票结构体信息
typedef struct passenger_inform
{
	char p_flight_num[20];			//航班号
	char date[20];					//日期
	char name[20];					//乘客姓名
	char identification_num[20];	//身份证号
	char seats_num[10];				//座位号

}passenger_inform;

//乘客订票结构体指针
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

