/*

客户：登陆，修改密码，充值，手机绑定，退出

管理员：登陆 ，添加会员 ，查看库存 ，退出

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//结构体构建客户信息
typedef struct tagUser{        //客户已存账号：1  密码：123
    char Accnum[20];
    char pwd[20];
    struct tagUser* next;
}User;

//结构体构建管理信息
typedef struct tagBoss{     ///管理已存账号：722  密码：722   
    char bossAccnum[20];
    char bosspwd[20];
    struct tagBoss* next;
}Boss;

//管理链
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

//客户链
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
void loadDate();//数据加载
void saveDate();//数据保存


//定义函数名
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


//数据加载
void loadDate(){
    FILE *f = fopen("information.dat", "r");
    if (f == NULL){
        printf("文件不存在\n");

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

        fseek(f, 0, SEEK_END);//文件末尾
        long lenght = ftell(f);
        fseek(f, 0, 0);//指针回0
        int count = lenght / size;
        while (count-- > 0){
            fread(&user, size, 1, f);
            link_user_push(&user);
        }
        printf("数据加载成功\n");
        fclose(f);
    }
}

//数据保存
bool user_save_one(void* fp, void* user)
{
    int size = sizeof(User) - sizeof(void*);
    fwrite(user, size, 1, (FILE*)fp);
    return false;
}
void saveDate(){
    FILE *f = fopen("information.dat", "w");
    link_user_scaner(f, user_save_one);
    printf("数据保存成功\n");
    fclose(f);
}


//欢迎界面
void welcome(){
    printf("===============欢迎光临SUPER无敌菠萝吹雪蛋糕店==================\n");
    printf("===============欢迎光临SUPER无敌菠萝吹雪蛋糕店==================\n");
    printf("===============欢迎光临SUPER无敌菠萝吹雪蛋糕店==================\n");
    printf("=====================重要的事情说三遍===========================\n");
    printf("=======================1 超级会员===============================\n");
    printf("=======================2 亲爱的店长=============================\n");
    printf("=======================3 添加管理=============================\n");
    printf("=======================0 山水有相逢=============================\n");
}

//管理相关方法
bool user_cmp_operator(void* a, void *b)
{
    User* ab = (User*)a;
    User* bb = (User*)b;
    return (strcmp(ab->Accnum, bb->Accnum) == 0) &&
        (strcmp(ab->pwd, bb->pwd) == 0);
}

//客户相关方法
void CustomerLogin(){
    User tmp;
    while (1){
        printf("请输入账号:\n");
        scanf("%s", tmp.Accnum);
        printf("请输入密码:\n");
        scanf("%s", tmp.pwd);

        //判断链中的账号是否与输入的账号相同
        if (link_user_scaner(&tmp, user_cmp_operator)){
            //成功 进入管理界面
            printf("登陆成功\n");
            Customermenu(tmp.Accnum);
        }
        else{//失败
            printf("账号或密码输入有误\n");
            int op;
            printf("是否重新登陆:(1 继续 0 退出 )\n");
            scanf("%d", &op);
            if (op){

            }
            else{
                printf("回到欢迎界面\n");
                return;
            }
        }
    }
}

//客户界面
void Customermenu(char Accnum[]){
    while (1){
        printf("WELCOME======SVIP\n");
        printf("1.修改密码\n");
        printf("2.充值\n");
        printf("3.手机绑定\n");
        printf("4.重新登陆\n");
        int op;
        scanf("%d", &op);
        switch (op){   //switch实现多分支选择结构
        case 1:
            //修改密码
            changepwd(Accnum);
            break;//退出本循环
        case 2:
            //充值
            Recharge();
            break;
        case 3:
            //手机绑定
            addphone();
            break;
        case 4:
            //重新登陆
            printf("重新登陆\n");
            return;
        default:
            printf("WARNING==WARNING==WARNING\n        REENTER\n");
            break;
        }
    }
}

//客户下的修改密码
void changepwd(char Accnum[])
{
    User tmp;
    char newpwd[20];
    char renewpwd[20];
    strcpy(tmp.Accnum, Accnum);
    while (1){// while语句 根据循环条件控制循环次数
        printf("请输入旧密码:\n");
        scanf("%s", tmp.pwd);
        printf("请输入新密码:\n");
        scanf("%s", newpwd);
        printf("请确认新密码:\n");
        scanf("%s", renewpwd);

        int i;
        if (strcmp(newpwd, renewpwd) == 0){  //检查新密码与确认密码是否相同
            User* user;
            if (user = link_user_scaner(&tmp, user_cmp_operator), user != NULL){
                strcpy(user->pwd, newpwd);
                printf("密码修改成功\n");
                return;
            }
            else{
                printf("原始密码输入错误=====请重新输入\n");
            }
        }
        else{
            printf("新密码确认错误=====请重新输入\n");
        }
        printf("是否继续:(任意键继续,0 退出)\n");
        int op;
        scanf("%d", &op);
        if (op == 0){
            return;
        }
    }
}

//客户下的充值系统
void Recharge(){

    int a;
    printf("请输入您要充值的金额: ");
    scanf("%d", &a);
    printf("===========\n");
    printf("尊敬的超级会员==恭喜您充值成功\n");
    printf("尊敬的超级会员==您的余额为:%d\n", a);
}


//客户绑定手机号
void addphone(){
    char phone[20];
    printf("=====您当前正进行手机绑定=====\n");
    printf("请输入您的手机号:\n");
    scanf("%s", phone);
    printf("===========\n");
    printf("尊敬的超级会员,您现在可以通过号码:%s 接收本店活动相关通知\n", phone);

}



//管理相关方法
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
        printf("请输入账号:\n");
        scanf("%s", tmp.bossAccnum);
        printf("请输入密码:\n");
        scanf("%s", tmp.bosspwd);

        //判断链中的账号是否与输入的账号相同
        if (link_boss_find(&tmp, boss_cmp_operator)){
            //成功 进入管理界面
            printf("登陆成功\n");
            Bossmenu(tmp.bossAccnum);
        }
        else{//失败
            printf("账号或密码输入有误\n");
            int op;
            printf("是否重新登陆:(1 继续 0 退出 )\n");
            scanf("%d", &op);
            if (op){

            }
            else{
                printf("回到欢迎界面\n");
                break;
            }
        }
    }
}


//管理界面
void Bossmenu(char bossAccnum[]){
    while (1){
        printf("WELCOME======BOSS\n");
        printf("1.添加会员\n");
        printf("2.查看库存\n");
        printf("0.重新登陆\n");
        int op;
        scanf("%d", &op);
        switch (op){
        case 1:
            //添加会员
            addvip();
            break;
        case 2:
            //查看库存
            Stock();
            break;
        case 0:
            //重新登陆
            printf("重新登陆\n");
            return;
            break;
        default:
            printf("WARNING==WARNING==WARNING\n        REENTER\n");
            break;
        }
    }
}



//管理添加会员
void addvip(){
    printf("==========添加会员\n");
    User s;
    printf("请输入新会员账号:\n");
    scanf("%s", s.Accnum);
    printf("请输入密码:\n");
    scanf("%s", s.pwd);
    link_user_push(&s);

    printf("恭喜您加入本店会员\n");
    saveDate();

}

//管理查看库存
void Stock(){
    printf("============香草黑巧克力蛋糕:2\n");
    printf("============葡式蛋挞:20\n");
    printf("============榴莲椰香蛋糕:6\n");
    printf("============梦幻马卡龙:5\n");
    printf("============蓝莓千层:4\n");
    printf("============百分百全麦吐司:16\n");
    printf("============私人订制生日蛋糕:请询问当日店员具体情况\n");
}

//添加管理
void addgl(){
    printf("==========添加管理\n");
    Boss s;
    printf("请输入管理账号:\n");
    scanf("%s", s.bossAccnum);
    printf("请输入管理密码:\n");
    scanf("%s", s.bosspwd);

    link_boss_push(&s);

    printf("管理添加成功\n");
    saveDate();
}



void main()
{
    {
        Boss bossTbl[] = 
        {
            { "722", "722" },
            { "2", "123" }
        };  //管理账号密码
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
            //客户登陆
            CustomerLogin();
            continue;
        case 2:
            //管理登陆
            BossLogin();
            continue;
        case 3:
            //添加管理
            addgl();
            continue;
        case 0://退出
            printf("山水有相逢\n");
            break;
        }
        break;
    }
    link_boss_clear();
}
