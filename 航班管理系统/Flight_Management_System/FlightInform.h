/*
航班信息以及函数头文件
*/
#ifndef _FLIGHTINFORM_H
#define _FLIGHTINFORM_H


//航班结构体信息
typedef struct flight_inform
{
	char flight_number[20];		//航班号
	char departure[20];			//出发地
	char destination[20];		//目的地
	char departure_time[20];	//起飞时间
	char landing_time[20];		//落地时间
	char aircraft_models[20];	//飞机机型
	int seats_number;			//座位数
	int price;					//价格

}flight_inform;

//航班结构体指针
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