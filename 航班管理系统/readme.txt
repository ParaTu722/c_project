������Ŀ���ƣ��������ϵͳ

��������������
1. main.c:�������ļ������������ļ�����
	

2. menu.c ; menu.h:������ʾ���˵���ʾ�ĺ�������ͷ�ļ�
	������
		PowerOn_Animation();//��������
		sys_memu();//�˵�����

3. FlightInform.c ; FlightInform.h:������Ϣ�����������ļ�
	������
		show_flight_information();//��ʾ������Ϣ
		add_flight_information();//���Ӻ���
		delete_flight_information(L);//ɾ������
		PriceSorting(L);//�ؼۺ��ࣨ���۸���


4. PassengerInform.c ; PassengerInform.h:�˿���Ϣ�����������ļ�
	������
		flight_bookings(LP,L);//���ඩƱ
		delete_flight_bookings(LP);//������Ʊ
		show_flight_bookings(LP);//��Ʊ��ʾ


5. FileOperation.c ; FileOperation.h:�ļ�������������ͷ�ļ�
	������
		record_in_file(L);//�ļ�����
		add_finform_in_file(L);//���ļ����Ӻ���


����bug������������������������	�ޱ���