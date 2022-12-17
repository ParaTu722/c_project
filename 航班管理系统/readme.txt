★★★项目名称：航班管理系统

二、功能描述：
1. main.c:主函数文件，运行所有文件函数
	

2. menu.c ; menu.h:开机显示，菜单显示的函数及其头文件
	包含：
		PowerOn_Animation();//开机画面
		sys_memu();//菜单界面

3. FlightInform.c ; FlightInform.h:航班信息及函数及其文件
	包含：
		show_flight_information();//显示航班信息
		add_flight_information();//增加航班
		delete_flight_information(L);//删除航班
		PriceSorting(L);//特价航班（按价格降序）


4. PassengerInform.c ; PassengerInform.h:乘客信息及函数及其文件
	包含：
		flight_bookings(LP,L);//航班订票
		delete_flight_bookings(LP);//航班退票
		show_flight_bookings(LP);//购票显示


5. FileOperation.c ; FileOperation.h:文件操作函数及其头文件
	包含：
		record_in_file(L);//文件存盘
		add_finform_in_file(L);//从文件增加航班


三、bug描述：各个功能运行正常，	无报错