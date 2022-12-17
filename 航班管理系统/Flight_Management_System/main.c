/*
主函数文件：实现对各个功能函数的调用
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
	
	//链表初始化
	init_flight_inform(&L);
	init_passenger(&LP);

	//开机画面
	PowerOn_Animation();
	//功能选择
	while(1)
	{
		switch(sys_memu())
		{
			case 1:
				//显示航班信息
				show_flight_information(L);
				break;

			case 2:
				//增加航班
				add_flight_information(L);
				break;

			case 3:
				//删除航班
				delete_flight_information(L);
				break;

			case 4:
				//航班订票
				flight_bookings(LP,L);
				break;

			case 5:
				//航班退票
				delete_flight_bookings(LP);
				break;

			case 6:
				//购票显示
				show_flight_bookings(LP);
				break;

			case 7:
				//航班存盘
				record_in_file(L);
				break;

			case 8:
				//从文件增加航班
				add_finform_in_file(L);
				break;

			case 9:
				//特价航班（按价格降序）
				PriceSorting(L);
				break;

			case 0:
				printf("!!!已退航班管理系统!!!\n");
				exit(0);

			default:
				printf("!!!输入错误，请重新选择!!!\n");
				system("cls");
				break;
		}
	}
}
