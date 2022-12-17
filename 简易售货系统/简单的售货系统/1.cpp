/*

�ͻ�����½���޸����룬��ֵ���ֻ��󶨣��˳�

����Ա����½ ����ӻ�Ա ���鿴��� ���˳�

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//�ṹ�幹���ͻ���Ϣ
typedef struct tagUser{        //�ͻ��Ѵ��˺ţ�1  ���룺123
    char Accnum[20];
    char pwd[20];
    struct tagUser* next;
}User;

//�ṹ�幹��������Ϣ
typedef struct tagBoss{     ///�����Ѵ��˺ţ�722  ���룺722   
    char bossAccnum[20];
    char bosspwd[20];
    struct tagBoss* next;
}Boss;

//������
Boss *gBossHead = NULL;
void link_boss_push(Boss* a)
{
    Boss* b = new Boss;
    *b = *a;
    b->next = gBossHead;
    gBossHead = b;
}
void link_boss_clear()
{
    while (gBossHead != NULL){
        Boss* n = gBossHead->next;
        delete gBossHead; gBossHead = n;
    }
}
Boss* link_boss_find(void* data, bool(*cmp)(void*, void*))
{
    for (Boss* n = gBossHead; n != NULL; n = n->next){
        if (cmp(data, n)) return n;
    }
    return NULL;
}

//�ͻ���
User *gUserHead = NULL;
void link_user_push(User* a)
{
    User* b = new User;
    *b = *a;
    b->next = gUserHead;
    gUserHead = b;
}
void link_user_clear()
{
    while (gUserHead != NULL){
        User* n = gUserHead->next;
        delete gUserHead; gUserHead = n;
    }
}
User* link_user_scaner(void* data, bool(*cmp)(void*, void*))
{
    for (User* n = gUserHead; n != NULL; n = n->next){
        if (cmp(data, n)) return n;
    }
    return NULL;
}


void welcome();
void loadDate();//���ݼ���
void saveDate();//���ݱ���


//���庯����
void CustomerLogin();
void Customermenu(char Accnum[]);
void changepwd(char Accnum[]);
void Recharge();
void addphone();
void BossLogin();
void Bossmenu(char bossAccnum[]);
void addvip();
void Stock();
void addgl();


//���ݼ���
void loadDate(){
    FILE *f = fopen("information.dat", "r");
    if (f == NULL){
        printf("�ļ�������\n");

        User userTbl[100] = 
        {
            { "1", "123" },
            { "2", "123" },
            { "3", "123" }
        };
        link_user_push(userTbl + 0);
        link_user_push(userTbl + 1);
        link_user_push(userTbl + 2);
    }
    else{
        User user;
        int size = sizeof(User) - sizeof(void*);

        fseek(f, 0, SEEK_END);//�ļ�ĩβ
        long lenght = ftell(f);
        fseek(f, 0, 0);//ָ���0
        int count = lenght / size;
        while (count-- > 0){
            fread(&user, size, 1, f);
            link_user_push(&user);
        }
        printf("���ݼ��سɹ�\n");
        fclose(f);
    }
}

//���ݱ���
bool user_save_one(void* fp, void* user)
{
    int size = sizeof(User) - sizeof(void*);
    fwrite(user, size, 1, (FILE*)fp);
    return false;
}
void saveDate(){
    FILE *f = fopen("information.dat", "w");
    link_user_scaner(f, user_save_one);
    printf("���ݱ���ɹ�\n");
    fclose(f);
}


//��ӭ����
void welcome(){
    printf("===============��ӭ����SUPER�޵в��ܴ�ѩ�����==================\n");
    printf("===============��ӭ����SUPER�޵в��ܴ�ѩ�����==================\n");
    printf("===============��ӭ����SUPER�޵в��ܴ�ѩ�����==================\n");
    printf("=====================��Ҫ������˵����===========================\n");
    printf("=======================1 ������Ա===============================\n");
    printf("=======================2 �װ��ĵ곤=============================\n");
    printf("=======================3 ��ӹ���=============================\n");
    printf("=======================0 ɽˮ�����=============================\n");
}

//������ط���
bool user_cmp_operator(void* a, void *b)
{
    User* ab = (User*)a;
    User* bb = (User*)b;
    return (strcmp(ab->Accnum, bb->Accnum) == 0) &&
        (strcmp(ab->pwd, bb->pwd) == 0);
}

//�ͻ���ط���
void CustomerLogin(){
    User tmp;
    while (1){
        printf("�������˺�:\n");
        scanf("%s", tmp.Accnum);
        printf("����������:\n");
        scanf("%s", tmp.pwd);

        //�ж����е��˺��Ƿ���������˺���ͬ
        if (link_user_scaner(&tmp, user_cmp_operator)){
            //�ɹ� ����������
            printf("��½�ɹ�\n");
            Customermenu(tmp.Accnum);
        }
        else{//ʧ��
            printf("�˺Ż�������������\n");
            int op;
            printf("�Ƿ����µ�½:(1 ���� 0 �˳� )\n");
            scanf("%d", &op);
            if (op){

            }
            else{
                printf("�ص���ӭ����\n");
                return;
            }
        }
    }
}

//�ͻ�����
void Customermenu(char Accnum[]){
    while (1){
        printf("WELCOME======SVIP\n");
        printf("1.�޸�����\n");
        printf("2.��ֵ\n");
        printf("3.�ֻ���\n");
        printf("4.���µ�½\n");
        int op;
        scanf("%d", &op);
        switch (op){   //switchʵ�ֶ��֧ѡ��ṹ
        case 1:
            //�޸�����
            changepwd(Accnum);
            break;//�˳���ѭ��
        case 2:
            //��ֵ
            Recharge();
            break;
        case 3:
            //�ֻ���
            addphone();
            break;
        case 4:
            //���µ�½
            printf("���µ�½\n");
            return;
        default:
            printf("WARNING==WARNING==WARNING\n        REENTER\n");
            break;
        }
    }
}

//�ͻ��µ��޸�����
void changepwd(char Accnum[])
{
    User tmp;
    char newpwd[20];
    char renewpwd[20];
    strcpy(tmp.Accnum, Accnum);
    while (1){// while��� ����ѭ����������ѭ������
        printf("�����������:\n");
        scanf("%s", tmp.pwd);
        printf("������������:\n");
        scanf("%s", newpwd);
        printf("��ȷ��������:\n");
        scanf("%s", renewpwd);

        int i;
        if (strcmp(newpwd, renewpwd) == 0){  //�����������ȷ�������Ƿ���ͬ
            User* user;
            if (user = link_user_scaner(&tmp, user_cmp_operator), user != NULL){
                strcpy(user->pwd, newpwd);
                printf("�����޸ĳɹ�\n");
                return;
            }
            else{
                printf("ԭʼ�����������=====����������\n");
            }
        }
        else{
            printf("������ȷ�ϴ���=====����������\n");
        }
        printf("�Ƿ����:(���������,0 �˳�)\n");
        int op;
        scanf("%d", &op);
        if (op == 0){
            return;
        }
    }
}

//�ͻ��µĳ�ֵϵͳ
void Recharge(){

    int a;
    printf("��������Ҫ��ֵ�Ľ��: ");
    scanf("%d", &a);
    printf("===========\n");
    printf("�𾴵ĳ�����Ա==��ϲ����ֵ�ɹ�\n");
    printf("�𾴵ĳ�����Ա==�������Ϊ:%d\n", a);
}


//�ͻ����ֻ���
void addphone(){
    char phone[20];
    printf("=====����ǰ�������ֻ���=====\n");
    printf("�����������ֻ���:\n");
    scanf("%s", phone);
    printf("===========\n");
    printf("�𾴵ĳ�����Ա,�����ڿ���ͨ������:%s ���ձ������֪ͨ\n", phone);

}



//������ط���
bool boss_cmp_operator(void* a, void *b)
{
    Boss* ab = (Boss*)a;
    Boss* bb = (Boss*)b;
    return (strcmp(ab->bossAccnum, bb->bossAccnum) == 0) &&
        (strcmp(ab->bosspwd, bb->bosspwd) == 0);
}

void BossLogin(){
    Boss tmp;
    while (1){
        printf("�������˺�:\n");
        scanf("%s", tmp.bossAccnum);
        printf("����������:\n");
        scanf("%s", tmp.bosspwd);

        //�ж����е��˺��Ƿ���������˺���ͬ
        if (link_boss_find(&tmp, boss_cmp_operator)){
            //�ɹ� ����������
            printf("��½�ɹ�\n");
            Bossmenu(tmp.bossAccnum);
        }
        else{//ʧ��
            printf("�˺Ż�������������\n");
            int op;
            printf("�Ƿ����µ�½:(1 ���� 0 �˳� )\n");
            scanf("%d", &op);
            if (op){

            }
            else{
                printf("�ص���ӭ����\n");
                break;
            }
        }
    }
}


//�������
void Bossmenu(char bossAccnum[]){
    while (1){
        printf("WELCOME======BOSS\n");
        printf("1.��ӻ�Ա\n");
        printf("2.�鿴���\n");
        printf("0.���µ�½\n");
        int op;
        scanf("%d", &op);
        switch (op){
        case 1:
            //��ӻ�Ա
            addvip();
            break;
        case 2:
            //�鿴���
            Stock();
            break;
        case 0:
            //���µ�½
            printf("���µ�½\n");
            return;
            break;
        default:
            printf("WARNING==WARNING==WARNING\n        REENTER\n");
            break;
        }
    }
}



//������ӻ�Ա
void addvip(){
    printf("==========��ӻ�Ա\n");
    User s;
    printf("�������»�Ա�˺�:\n");
    scanf("%s", s.Accnum);
    printf("����������:\n");
    scanf("%s", s.pwd);
    link_user_push(&s);

    printf("��ϲ�����뱾���Ա\n");
    saveDate();

}

//����鿴���
void Stock(){
    printf("============��ݺ��ɿ�������:2\n");
    printf("============��ʽ��̢:20\n");
    printf("============����Ҭ�㵰��:6\n");
    printf("============�λ�����:5\n");
    printf("============��ݮǧ��:4\n");
    printf("============�ٷְ�ȫ����˾:16\n");
    printf("============˽�˶������յ���:��ѯ�ʵ��յ�Ա�������\n");
}

//��ӹ���
void addgl(){
    printf("==========��ӹ���\n");
    Boss s;
    printf("����������˺�:\n");
    scanf("%s", s.bossAccnum);
    printf("�������������:\n");
    scanf("%s", s.bosspwd);

    link_boss_push(&s);

    printf("������ӳɹ�\n");
    saveDate();
}



void main()
{
    {
        Boss bossTbl[] = 
        {
            { "722", "722" },
            { "2", "123" }
        };  //�����˺�����
        link_boss_push(bossTbl + 0);
        link_boss_push(bossTbl + 1);
    }

    loadDate();
    while (1){
        welcome();
        int op;
        scanf("%d", &op);
        switch (op)
        {
        default:
            printf("WARNING==WARNING==WARNING\n        REENTER\n");
            continue;
        case 1:
            //�ͻ���½
            CustomerLogin();
            continue;
        case 2:
            //�����½
            BossLogin();
            continue;
        case 3:
            //��ӹ���
            addgl();
            continue;
        case 0://�˳�
            printf("ɽˮ�����\n");
            break;
        }
        break;
    }
    link_boss_clear();
}
