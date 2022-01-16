#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct student{                                                                 //定义一个结构体
       long num;
       char name[40];
       char Class[20];
       char *gender;
       char Pnum[20];
       float *grade;
       float sum;
       };
void help(void);                                                                //显示帮助内容
int input(FILE *);                                                              //输入学生信息并存入文件
void numfind(FILE *);                                                           //通过学号查找学生
void namefind(FILE *);                                                          //通过姓名查找学生
void output(FILE *);                                                            //输出学生信息到显示屏
void sortsum(FILE *);                                                           //根据总分进行排序
void sortcou(FILE *);                                                           //根据某一科目进行排序
void statistics(FILE *);                                                        //统计优秀率和及格率

int main(void)
{
    FILE *p;                                                                    //定义一个文件指针
    int key = 1;                                                                //定义一个整型变量用于捕获按键

    while(1)
    {
        system("CLS");                                                          //清空显示屏上的内容
        printf("**************************** \n");                              //显示系统主界面
        printf("学生成绩管理系统  \n");
        printf("**************************** \n");
        printf("************************************ \n");
        printf("**    F1 --帮助                   ** \n");
        printf("**    F2 --输入数据并存入文件     ** \n");
        printf("**    F3 --根据学号查询成绩       ** \n");
        printf("**    F4 --根据姓名查询成绩       ** \n");
        printf("**    F5 --输出文件内容           ** \n");
        printf("**    F6 –成绩排序               ** \n");
        printf("**    F7 --统计及格和优秀人数     ** \n");
        printf("**    ESC--退出系统               ** \n");
        printf("************************************ \n");

        key = getch();                                                          //捕获按键
        switch(key)
        {
            case 59:
                system("CLS");                                                  //清空显示屏上的内容
                help();                                                         //显示帮助内容
                system("Pause");                                                //按任意键继续
                break;
            case 60:
                system("CLS");                                                  //清空显示屏上的内容
                input(p);                                                       //输入学生信息并存入文件
                break;
            case 61:
                system("CLS");                                                  //清空显示屏上的内容
                numfind(p);                                                     //通过学号查找学生
                system("Pause");
                break;
            case 62:
                system("CLS");                                                  //清空显示屏上的内容
                namefind(p);                                                    //通过姓名查找学生
                system("Pause");
                break;
            case 63:
                system("CLS");                                                  //清空显示屏上的内容
                output(p);                                                      //输出学生信息到显示屏
                system("Pause");
                break;
            case 64:
                system("CLS");                                                  //清空显示屏上的内容
                printf("请选择：\n");                                           //输出提示信息
                printf("1.对某门成绩进行排序\n");
                printf("2.对总分进行排序\n");
                while(1)
                {
                    key = getch();                                              //捕获按键
                    if(key == 49)
                    {
                        system("CLS");                                          //清空显示屏上的内容
                        sortcou(p);                                             //根据某一科目进行排序
                        break;
                    }
                    if(key == 50)
                    {
                        system("CLS");                                          //清空显示屏上的内容
                        sortsum(p);                                             //根据总分进行排序
                        break;
                    }
                }
                system("Pause");
                break;
            case 65:
                system("CLS");                                                  //清空显示屏上的内容
                statistics(p);                                                  //统计优秀率和及格率
                system("Pause");
                break;
            case 27:
                system("CLS");                                                  //清空显示屏上的内容
                return 0;                                                       //返回到0
        }
    }
}
/*---------------------------------------------------------
 *  函数名 ：help
 *  功能   ：显示帮助信息
 *  参数   ：无
 *  返回值 ：无
---------------------------------------------------------*/

void help(void)
{
    printf("使用帮助：\n\n");
    printf("输入数据并存入文件：\n");
    printf("在主界面按下F2进入此模式。\n");
    printf("若第一次输入数据，则需要先输入课程的数量（以回车结束），再根据提示依次输入课程的名称（以回车结束）。\n");
    printf("在输入课程数量和课程名称后或是重复输入数据时，需要根据提示依次输入多个学生的信息。\n");
    printf("当需要结束输入时，根据提示选择结束输入即可。\n\n");
    printf("根据学号查询成绩：\n");
    printf("在主界面按下F3进入此模式。\n");
    printf("根据提示输入需要查找的学生的学号（以回车结束）。\n");
    printf("若是文件中存有学号是输入学号的学生，则会显示该学生的信息。\n");
    printf("若是文件中没有存入学号是输入学号的学生，则会提示未找到该学生。\n");
    printf("查找结束后，按任意键退出。\n\n");
    printf("根据姓名查询成绩：\n");
    printf("在主界面按下F4进入此模式。\n");
    printf("根据提示输入需要查找的学生的姓名（以回车结束）。\n");
    printf("若是文件中存有姓名是输入姓名的学生，则会显示该学生的信息。\n");
    printf("若是文件中没有存入姓名是输入姓名的学生，则会提示未找到该学生。\n");
    printf("查找结束后，按任意键退出。\n\n");
    printf("输出文件内容：\n");
    printf("在主界面按下F5进入此模式。\n");
    printf("文件中的学生信息会输出到显示屏上。\n");
    printf("按任意键退出。\n\n");;
    printf("成绩排序：\n");
    printf("在主界面按下F6进入此模式。\n");
    printf("根据提示选择对某门成绩进行排序或对总分进行排序。\n");
    printf("若选择对某门成绩进行排序，则需根据提示选择要进行排序的课程（输入课程序号，以回车结束）\n");
    printf("排序结束后，会进行提示，此时文件中的学生信息会根据排序的对象由上到下降序排列。\n");
    printf("按任意键退出。\n\n");
    printf("统计及格和优秀人数：\n");
    printf("在主界面按下F7进入此模式。\n");
    printf("根据提示选择要进行统计的课程（输入课程序号，以回车结束）\n");
    printf("该课程的优秀率和及格率会显示出来。\n");
    printf("按任意键退出\n\n");
    printf("退出系统：\n");
    printf("按下ESC退出系统。\n");
}

/*---------------------------------------------------------
 *  函数名 ：input
 *  功能   ：输入学生信息
 *  参数   ：FILE *p
 *  返回值 ：无
---------------------------------------------------------*/
int input(FILE *p)
{
    struct student a;
    int key,i,j,m,n;
    char c;
    char **cou = NULL;

    a.grade = NULL;

    p = fopen("student.csv","r+");
    if(p == NULL)
    {
        p = fopen("student.csv","w");
        if(p == NULL)
        {
            printf("文件创建/打开失败！");
            exit(0);
        }

        fprintf(p,"%s,%s,%s,%s,%s,","学号","姓名","班级","性别","联系电话");

        printf("请输入课程的数量：");
        scanf("%d",&i);
        getchar();

        cou = (char**)malloc(i*sizeof(char*));
        if(cou == NULL)
        {
            printf("分配内存失败！");
            exit(1);
        }
        for(j = 0;j < i;j++)
        {
            cou[j] = (char*)malloc(sizeof(char[40]));
            if(cou[j] == NULL)
            {
                printf("分配内存失败！");
                for(m = 0;m < j;m++)
                {
                    free(cou[m]);
                }
                free(cou);
                exit(1);
            }
        }

        a.grade = (float*)malloc(i*sizeof(float));
        if(a.grade == NULL)
        {
            printf("分配内存失败！");
            for(j = 0;j < i;j++)
            {
                free(cou[j]);
            }
            free(cou);
            exit(1);
        }

        for( j = 0 ; j < i ; j++ )
        {
            printf("请输入课程%d的名称：",j+1);
            gets(*(cou+j));
            fprintf(p,"%s,",cou[j]);
        }

        fprintf(p,"%s\n","总分");

        system("CLS");
    }
    else
    {
        for( i = 0 ; c != '\n' ; )
        {
            c = fgetc(p);
            if( c == ',')
            {
                i++;
            }
        }
        i = i - 5;

        if(cou == NULL)
        {
            cou = (char**)malloc(i*sizeof(char*));
            if(cou == NULL)
            {
            printf("分配内存失败！");
            exit(1);
            }
            for(j = 0;j < i;j++)
            {
                cou[j] = (char*)malloc(sizeof(char[40]));
                if(cou[j] == NULL)
                {
                    printf("分配内存失败！");
                    for(m = 0;m < j;m++)
                    {
                        free(cou[m]);
                    }
                    free(cou);
                    exit(1);
                }
            }
        }

        if(a.grade == NULL)
        {
            a.grade = (float*)malloc(i*sizeof(float));
            if(a.grade == NULL)
            {
            printf("分配内存失败！");
            for(j = 0;j < i;j++)
            {
                free(cou[j]);
            }
            free(cou);
            exit(1);
            }
        }

        rewind(p);

        for( j = 0 ; j < 5 ;)
        {
            c = fgetc(p);
            if( c == ',' )
            {
                j++;
            }
        }

        for( m = 0 ; m < i ; m++ )
        {
            for( n = 0 ;  ; n++ )
            {
                cou[m][n] = fgetc(p);
                if( cou[m][n] == ',' || cou[m][n] == '\n' )
                {
                    cou[m][n] = '\0';
                    break;
                }
            }
        }

        fseek(p,0,2);
    }
    do
    {
    a.sum = 0.0f;

    printf("请输入学生的数据！\n");

    printf("请输入学生的学号：");
    scanf("%ld",&a.num);
    getchar();
    fprintf(p,"%ld,",a.num);

    printf("请输入学号为%ld的学生的姓名：",a.num);
    gets(a.name);
    fprintf(p,"%s,",a.name);

    printf("请输入学号为%ld的学生的班级：",a.num);
    gets(a.Class);
    fprintf(p,"%s,",a.Class);

    printf("请选择学号为%ld的学生的性别：\n",a.num);
    printf("1:男\n2:女\n");

    while(1)
    {
        key = getch();

        if(key == 49)
        {
            a.gender = "男";
            break;
        }
        else if(key == 50)
        {
            a.gender = "女";
            break;
        }
    }
    fprintf(p,"%s,",a.gender);

    printf("请输入学号为%ld的学生的联系电话：",a.num);
    gets(a.Pnum);
    fprintf(p,"%s,",a.Pnum);


    for( j = 0 ; j < i ; j++ )
    {
        printf("请输入学号为%ld的学生的%s的成绩：",a.num,cou[j]);
        scanf("%f",&a.grade[j]);
        getchar();
        a.sum = a.sum + a.grade[j];
        fprintf(p,"%f,",a.grade[j]);
    }

    fprintf(p,"%f\n",a.sum);

    while(1)
    {
        system("CLS");
        printf("Enter:继续输入\nEsc:结束输入\n");
        key = getch();
        if(key == 13)
        {
            system("CLS");
            break;
        }
        if(key == 27)
        {
            for(j = 0;j < i;j++)
            {
                free(cou[j]);
            }
            free(cou);
            free(a.grade);
            fclose(p);
            return 0;
        }
    }
    }while(1);

}
/*------------------------------------------------
 *  函数名 ：numfind
 *  功能   ：根据学号查询学生信息
 *  参数   ：FILE *p
 *  返回值 ：无
 -----------------------------------------------*/
void numfind(FILE *p)
{
    struct student a;
    long num;
    char c,**cou;
    int i,j,m,n;

    printf("请输入要查找的学号：");
    scanf("%ld",&num);
    getchar();

    p = fopen("student.csv","r");
    if(p == NULL)
    {
        printf("打开文件失败！\n");
        exit(0);
    }

    for( i = 0 ; c != '\n' ; )
    {
        c = fgetc(p);
        if( c == ',')
        {
            i++;
        }
    }
    i = i - 5;
    rewind(p);

    a.grade = (float*)malloc(i*sizeof(float));
    if(a.grade == NULL)
    {
        printf("分配内存失败！");
        exit(1);
    }

    cou = (char**)malloc(i*sizeof(char*));
    if(cou == NULL)
    {
        printf("分配内存失败！");
        free(a.grade);
        exit(1);
    }
    for(j = 0;j < i;j++)
    {
        cou[j] = (char*)malloc(sizeof(char[40]));
        if(cou[j] == NULL)
        {
            printf("分配内存失败！");
            free(a.grade);
            for(m = 0;m < j;m++)
            {
                free(cou[m]);
            }
            free(cou);
            exit(1);
        }
    }

    for( j = 0 ; j < 5 ;)
    {
        c = fgetc(p);
        if( c == ',' )
        {
            j++;
        }
    }

    for( m = 0 ; m < i ; m++ )
    {
        for( n = 0 ;  ; n++ )
        {
            cou[m][n] = fgetc(p);
            if( cou[m][n] == ',' || cou[m][n] == '\n' )
            {
                cou[m][n] = '\0';
                break;
            }
        }
    }

    rewind(p);

    do
    {
        c = fgetc(p);
        if(c == '\n')
        {
            fscanf(p,"%ld,",&a.num);
        }
        if(a.num == num)
        {
            for(j = 0;;j++)
            {
                a.name[j] = fgetc(p);
                if(a.name[j] == ',')
                {
                    a.name[j] = '\0';
                    break;
                }
            }
            for(j = 0;;j++)
            {
                a.Class[j] = fgetc(p);
                if(a.Class[j] == ',')
                {
                    a.Class[j] = '\0';
                    break;
                }
            }
            for(j = 0;;j++)
            {
                a.gender[j] = fgetc(p);
                if(a.gender[j] == ',')
                {
                    a.gender[j] = '\0';
                    break;
                }
            }
            for(j = 0;;j++)
            {
                a.Pnum[j] = fgetc(p);
                if(a.Pnum[j] == ',')
                {
                    a.Pnum[j] = '\0';
                    break;
                }
            }
            printf("查找结果为：\n");
            printf("学号：%ld\n",a.num);
            printf("姓名：%s\n",a.name);
            printf("班级：%s\n",a.Class);
            printf("性别：%s\n",a.gender);
            printf("联系电话：%s\n",a.Pnum);

            for(j = 0;j < i;j++)
            {
                fscanf(p,"%f,",&a.grade[j]);
                printf("%s的成绩为：%.2f\n",cou[j],a.grade[j]);
            }
            fscanf(p,"%f\n",&a.sum);
            printf("总分为：%.2f\n",a.sum);
            break;
        }
        if(c == EOF)
        {
            printf("未找到该学号！\n");
        }
    }
    while(c!=EOF);

    for(j = 0;j < i;j++)
    {
        free(cou[j]);
    }
    free(cou);
    free(a.grade);
    fclose(p);
}
/*---------------------------------------------------------
 *  函数名 ：namefind
 *  功能   ：根据姓名查询学生信息
 *  参数   ：FILE *p
 *  返回值 ：无
---------------------------------------------------------*/
void namefind(FILE *p)
{
    struct student a;
    char name[40],**cou;
    char c;
    int i,j,m,n;

    printf("请输入要查找的姓名：");
    gets(name);

    p = fopen("student.csv","r");
    if(p == NULL)
    {
        printf("打开文件失败！\n");
        exit(0);
    }

    for( i = 0 ; c != '\n' ; )
    {
        c = fgetc(p);
        if( c == ',')
        {
            i++;
        }
    }
    i = i - 5;
    rewind(p);

    a.grade = (float*)malloc(i*sizeof(float));
    if(a.grade == NULL)
    {
        printf("分配内存失败！");
        exit(1);
    }

    cou = (char**)malloc(i*sizeof(char*));
    if(cou == NULL)
    {
        printf("分配内存失败！");
        free(a.grade);
        exit(1);
    }
    for(j = 0;j < i;j++)
    {
        cou[j] = (char*)malloc(sizeof(char[40]));
        if(cou[j] == NULL)
        {
            printf("分配内存失败！");
            free(a.grade);
            for(m = 0;m < j;m++)
            {
                free(cou[m]);
            }
            free(cou);
            exit(1);
        }
    }

    for( j = 0 ; j < 5 ;)
    {
        c = fgetc(p);
        if( c == ',' )
        {
            j++;
        }
    }

    for( m = 0 ; m < i ; m++ )
    {
        for( n = 0 ;  ; n++ )
        {
            cou[m][n] = fgetc(p);
            if( cou[m][n] == ',' || cou[m][n] == '\n' )
            {
                cou[m][n] = '\0';
                break;
            }
        }
    }

    rewind(p);

    do
    {
        c = fgetc(p);
        if(c == '\n')
        {
            fscanf(p,"%ld,",&a.num);
            for(j = 0;;j++)
            {
                a.name[j] = fgetc(p);
                if(a.name[j] == ',')
                {
                     a.name[j] = '\0';
                     break;
                }
                if(a.name[j] == EOF)
                {
                    break;
                }
            }

            if(strcmp(a.name,name) == 0)
            {
            for(j = 0;;j++)
            {
                a.Class[j] = fgetc(p);
                if(a.Class[j] == ',')
                {
                    a.Class[j] = '\0';
                    break;
                }
            }
            for(j = 0;;j++)
            {
                a.gender[j] = fgetc(p);
                if(a.gender[j] == ',')
                {
                    a.gender[j] = '\0';
                    break;
                }
            }
            for(j = 0;;j++)
            {
                a.Pnum[j] = fgetc(p);
                if(a.Pnum[j] == ',')
                {
                    a.Pnum[j] = '\0';
                    break;
                }
            }

            printf("查找结果为：\n");
            printf("学号：%ld\n",a.num);
            printf("姓名：%s\n",a.name);
            printf("班级：%s\n",a.Class);
            printf("性别：%s\n",a.gender);
            printf("联系电话：%s\n",a.Pnum);

            for(j = 0;j < i;j++)
            {
                fscanf(p,"%f,",&a.grade[j]);
                printf("%s的成绩为：%.2f\n",cou[j],a.grade[j]);
            }
            fscanf(p,"%f\n",&a.sum);
            printf("总分为：%.2f\n",a.sum);
            break;
            }
        }

        if(c == EOF)
        {
            printf("未找到该姓名！\n");
        }
    }while(c != EOF);

    for(j = 0;j < i;j++)
    {
        free(cou[j]);
    }
    free(cou);
    free(a.grade);
    fclose(p);
}
/*---------------------------------------------------------
 *  函数名 ：output
 *  功能   ：输出学生信息
 *  参数   ：FILE *p
 *  返回值 ：无
---------------------------------------------------------*/
void output(FILE *p)
{
    struct student a;
    char c,**cou;
    int i,j,m,n;

    p = fopen("student.csv","r");
    if(p == NULL)
    {
        printf("打开文件失败！\n");
        exit(0);
    }

    for( i = 0 ; c != '\n' ; )
    {
        c = fgetc(p);
        if( c == ',')
        {
            i++;
        }
    }
    i = i - 5;
    rewind(p);

    a.grade = (float*)malloc(i*sizeof(float));
    if(a.grade == NULL)
    {
        printf("分配内存失败！");
        exit(1);
    }

    cou = (char**)malloc(i*sizeof(char*));
    if(cou == NULL)
    {
        printf("分配内存失败！");
        free(a.grade);
        exit(1);
    }
    for(j = 0;j < i;j++)
    {
        cou[j] = (char*)malloc(sizeof(char[40]));
        if(cou[j] == NULL)
        {
            printf("分配内存失败！");
            free(a.grade);
            for(m = 0;m < j;m++)
            {
                free(cou[m]);
            }
            free(cou);
            exit(1);
        }
    }

    for( j = 0 ; j < 5 ;)
    {
        c = fgetc(p);
        if( c == ',' )
        {
            j++;
        }
    }

    for( m = 0 ; m < i ; m++ )
    {
        for( n = 0 ;  ; n++ )
        {
            cou[m][n] = fgetc(p);
            if( cou[m][n] == ',' || cou[m][n] == '\n' )
            {
                cou[m][n] = '\0';
                break;
            }
        }
    }

    rewind(p);

    printf("%-15s","学号");
    printf("%-15s","姓名");
    printf("%-15s","班级");
    printf("%-15s","性别");
    printf("%-15s","联系电话");
    for(j = 0;j < i;j++)
    {
        printf("%-15s",cou[j]);
    }
    printf("%-15s\n","总分");
    while(fgetc(p)!='\n');
    do
    {
            fscanf(p,"%ld,",&a.num);

            for(j = 0;;j++)
            {
                a.name[j] = fgetc(p);
                if(a.name[j] == ',')
                {
                    a.name[j] = '\0';
                    break;
                }
            }
            for(j = 0;;j++)
            {
                a.Class[j] = fgetc(p);
                if(a.Class[j] == ',')
                {
                    a.Class[j] = '\0';
                    break;
                }
            }
            for(j = 0;;j++)
            {
                a.gender[j] = fgetc(p);
                if(a.gender[j] == ',')
                {
                    a.gender[j] = '\0';
                    break;
                }
            }
            for(j = 0;;j++)
            {
                a.Pnum[j] = fgetc(p);
                if(a.Pnum[j] == ',')
                {
                    a.Pnum[j] = '\0';
                    break;
                }
            }
            printf("%-15ld",a.num);
            printf("%-15s",a.name);
            printf("%-15s",a.Class);
            printf("%-15s",a.gender);
            printf("%-15s",a.Pnum);
            for(j = 0;j < i;j++)
            {
                fscanf(p,"%f,",&a.grade[j]);
                printf("%-15.2f",a.grade[j]);
            }
            fscanf(p,"%f\n",&a.sum);
            printf("%-15.2f\n",a.sum);
    }
    while(feof(p) == 0);

    for(j = 0;j < i;j++)
    {
        free(cou[j]);
    }
    free(cou);
    free(a.grade);
    fclose(p);
}
/*---------------------------------------------------------
 *  函数名 ：output
 *  功能   ：根据学生总分对学生进行降序排序
 *  参数   ：FILE *p
 *  返回值 ：无
---------------------------------------------------------*/
void sortsum(FILE *p)
{
    struct student a,*b;
    char c,**cou;
    int i,j,m,n,peo;

    p = fopen("student.csv","r");
    if(p == NULL)
    {
        printf("打开文件失败！\n");
        exit(0);
    }

    for(peo = 0; c != EOF ; )
    {
        c = fgetc(p);
        if( c == '\n' )
        {
            peo++;
        }
    }

    peo = peo - 1;

    rewind(p);

    b = (struct student *)malloc(peo*sizeof(struct student));
    if(b == NULL)
    {
        printf("分配内存失败！");
        exit(1);
    }

    for( i = 0 ; c != '\n' ; )
    {
        c = fgetc(p);
        if( c == ',')
        {
            i++;
        }
    }

    i = i - 5;

    rewind(p);

    a.grade = (float*)malloc(i*sizeof(float));
    if(a.grade == NULL)
    {
        printf("分配内存失败！");
        free(b);
        exit(1);
    }

    for(j = 0;j < peo;j++)
    {
        b[j].grade = (float*)malloc(i*sizeof(float));
        b[j].gender = (char*)malloc(5*sizeof(char));
        if(b[j].grade == NULL)
        {
            printf("分配内存失败！");
            free(b);
            free(a.grade);
            for(m = 0;m < j;m++)
            {
                free(b[m].grade);
                free(b[m].gender);
            }
            exit(1);
        }
        if(b[j].gender == NULL)
        {
            printf("分配内存失败！");
            free(b);
            free(a.grade);
            for(m = 0;m < j;m++)
            {
                free(b[m].grade);
                free(b[m].gender);
            }
            free(b[j].grade);
            exit(1);
        }
    }

    cou = (char**)malloc(i*sizeof(char*));
    if(cou == NULL)
    {
        printf("分配内存失败！");
        free(b);
        free(a.grade);
        for(j = 0;j < peo;j++)
        {
            free(b[j].grade);
            free(b[j].gender);
        }
        exit(1);
    }
    for(j = 0;j < i;j++)
    {
        cou[j] = (char*)malloc(sizeof(char[40]));
        if(cou[j] == NULL)
        {
            printf("分配内存失败！");
            free(b);
            free(a.grade);
            for(m = 0;m < peo;m++)
            {
                free(b[m].grade);
                free(b[m].gender);
            }
            for(m = 0;m < j;m++)
            {
                free(cou[m]);
            }
            free(cou);
            exit(1);
        }
    }

    for( j = 0 ; j < 5 ;)
    {
        c = fgetc(p);
        if( c == ',' )
        {
            j++;
        }
    }

    for( m = 0 ; m < i ; m++ )
    {
        for( n = 0 ;  ; n++ )
        {
            cou[m][n] = fgetc(p);
            if( cou[m][n] == ',' || cou[m][n] == '\n' )
            {
                cou[m][n] = '\0';
                break;
            }
        }
    }

    rewind(p);

    while(fgetc(p)!='\n');

    for(j = 0;j < peo;j++)
    {
        fscanf(p,"%ld,",&b[j].num);

        for(m = 0;;m++)
        {
            b[j].name[m] = fgetc(p);
            if(b[j].name[m] == ',')
            {
                b[j].name[m] = '\0';
                break;
            }
        }

        for(m = 0;;m++)
        {
            b[j].Class[m] = fgetc(p);
            if(b[j].Class[m] == ',')
            {
                b[j].Class[m] = '\0';
                break;
            }
        }

        for(m = 0;;m++)
        {
            b[j].gender[m] = fgetc(p);
            if(b[j].gender[m] == ',')
            {
                b[j].gender[m] = '\0';
                break;
            }
        }

        for(m = 0;;m++)
        {
            b[j].Pnum[m] = fgetc(p);
            if(b[j].Pnum[m] == ',')
            {
                b[j].Pnum[m] = '\0';
                break;
            }
        }

        for(m = 0;m < i;m++)
        {
            fscanf(p,"%f,",&b[j].grade[m]);
        }

        fscanf(p,"%f\n",&b[j].sum);
    }

    for(m = 0;m < peo - 1;m++)
    {
        for(n = m + 1;n < peo;n++)
        {
            if(b[m].sum < b[n].sum)
            {
                a = b[m];
                b[m] = b[n];
                b[n] = a;
            }
        }
    }

    fclose(p);

    p = fopen("student.csv","w");
    if(p == NULL)
    {
        printf("文件打开失败！");
        exit(0);
    }

    fprintf(p,"%s,%s,%s,%s,%s,","学号","姓名","班级","性别","联系电话");

    for(j = 0;j < i;j++)
    {
        fprintf(p,"%s,",cou[j]);
    }

    fprintf(p,"%s\n","总分");

    for(j = 0;j < peo;j++)
    {
        fprintf(p,"%ld,",b[j].num);
        fprintf(p,"%s,",b[j].name);
        fprintf(p,"%s,",b[j].Class);
        fprintf(p,"%s,",b[j].gender);
        fprintf(p,"%s,",b[j].Pnum);
        for(m = 0;m < i;m++)
        {
            fprintf(p,"%f,",b[j].grade[m]);
        }
        fprintf(p,"%f\n",b[j].sum);
    }

    free(a.grade);
    for(j = 0;j < i;j++)
    {
        free(cou[j]);
    }
    free(cou);
    for(m = 0;m < peo;m++)
    {
        free(b[m].grade);
        free(b[m].gender);
    }
    fclose(p);

    printf("成绩排序完成！\n");
}
/*---------------------------------------------------------
 *  函数名 ：output
 *  功能   ：根据学生某一课程的成绩对学生进行降序排序
 *  参数   ：FILE *p
 *  返回值 ：无
---------------------------------------------------------*/
void sortcou(FILE *p)
{
    struct student a,*b;
    char c,**cou;
    int i,j,m,n,peo,k;

    p = fopen("student.csv","r");
    if(p == NULL)
    {
        printf("打开文件失败！\n");
        exit(0);
    }

    for(peo = 0; c != EOF ; )
    {
        c = fgetc(p);
        if( c == '\n' )
        {
            peo++;
        }
    }

    peo = peo - 1;

    rewind(p);

    b = (struct student *)malloc(peo*sizeof(struct student));
    if(b == NULL)
    {
        printf("分配内存失败！");
        exit(1);
    }

    for( i = 0 ; c != '\n' ; )
    {
        c = fgetc(p);
        if( c == ',')
        {
            i++;
        }
    }

    i = i - 5;

    rewind(p);

    a.grade = (float*)malloc(i*sizeof(float));
    if(a.grade == NULL)
    {
        printf("分配内存失败！");
        free(b);
        exit(1);
    }

    for(j = 0;j < peo;j++)
    {
        b[j].grade = (float*)malloc(i*sizeof(float));
        b[j].gender = (char*)malloc(5*sizeof(char));
        if(b[j].grade == NULL)
        {
            printf("分配内存失败！");
            free(b);
            free(a.grade);
            for(m = 0;m < j;m++)
            {
                free(b[m].grade);
                free(b[m].gender);
            }
            exit(1);
        }
        if(b[j].gender == NULL)
        {
            printf("分配内存失败！");
            free(b);
            free(a.grade);
            for(m = 0;m < j;m++)
            {
                free(b[m].grade);
                free(b[m].gender);
            }
            free(b[j].grade);
            exit(1);
        }
    }

    cou = (char**)malloc(i*sizeof(char*));
    if(cou == NULL)
    {
        printf("分配内存失败！");
        free(b);
        free(a.grade);
        for(j = 0;j < peo;j++)
        {
            free(b[j].grade);
            free(b[j].gender);
        }
        exit(1);
    }
    for(j = 0;j < i;j++)
    {
        cou[j] = (char*)malloc(sizeof(char[40]));
        if(cou[j] == NULL)
        {
            printf("分配内存失败！");
            free(b);
            free(a.grade);
            for(m = 0;m < peo;m++)
            {
                free(b[m].grade);
                free(b[m].gender);
            }
            for(m = 0;m < j;m++)
            {
                free(cou[m]);
            }
            free(cou);
            exit(1);
        }
    }

    for( j = 0 ; j < 5 ;)
    {
        c = fgetc(p);
        if( c == ',' )
        {
            j++;
        }
    }

    for( m = 0 ; m < i ; m++ )
    {
        for( n = 0 ;  ; n++ )
        {
            cou[m][n] = fgetc(p);
            if( cou[m][n] == ',' || cou[m][n] == '\n' )
            {
                cou[m][n] = '\0';
                break;
            }
        }
    }

    rewind(p);

    printf("请选择要进行排序的课程：\n");

    for(j = 0;j < i;j++)
    {
        printf("%d.%s\n",j+1,cou[j]);
    }

    do
    {
        scanf("%d",&k);
        if(k <= 0 || k > i)
        {
            printf("输入错误，请重新输入！\n");
        }
    }
    while(k <= 0 || k > i);

    while(fgetc(p)!='\n');

    for(j = 0;j < peo;j++)
    {
        fscanf(p,"%ld,",&b[j].num);

        for(m = 0;;m++)
        {
            b[j].name[m] = fgetc(p);
            if(b[j].name[m] == ',')
            {
                b[j].name[m] = '\0';
                break;
            }
        }

        for(m = 0;;m++)
        {
            b[j].Class[m] = fgetc(p);
            if(b[j].Class[m] == ',')
            {
                b[j].Class[m] = '\0';
                break;
            }
        }

        for(m = 0;;m++)
        {
            b[j].gender[m] = fgetc(p);
            if(b[j].gender[m] == ',')
            {
                b[j].gender[m] = '\0';
                break;
            }
        }

        for(m = 0;;m++)
        {
            b[j].Pnum[m] = fgetc(p);
            if(b[j].Pnum[m] == ',')
            {
                b[j].Pnum[m] = '\0';
                break;
            }
        }

        for(m = 0;m < i;m++)
        {
            fscanf(p,"%f,",&b[j].grade[m]);
        }

        fscanf(p,"%f\n",&b[j].sum);
    }

    for(m = 0;m < peo - 1;m++)
    {
        for(n = m + 1;n < peo;n++)
        {
            if(b[m].grade[k-1] < b[n].grade[k-1])
            {
                a = b[m];
                b[m] = b[n];
                b[n] = a;
            }
        }
    }

    fclose(p);

    p = fopen("student.csv","w");
    if(p == NULL)
    {
        printf("文件打开失败！");
        exit(0);
    }

    fprintf(p,"%s,%s,%s,%s,%s,","学号","姓名","班级","性别","联系电话");

    for(j = 0;j < i;j++)
    {
        fprintf(p,"%s,",cou[j]);
    }

    fprintf(p,"%s\n","总分");

    for(j = 0;j < peo;j++)
    {
        fprintf(p,"%ld,",b[j].num);
        fprintf(p,"%s,",b[j].name);
        fprintf(p,"%s,",b[j].Class);
        fprintf(p,"%s,",b[j].gender);
        fprintf(p,"%s,",b[j].Pnum);
        for(m = 0;m < i;m++)
        {
            fprintf(p,"%f,",b[j].grade[m]);
        }
        fprintf(p,"%f\n",b[j].sum);
    }

    free(a.grade);
    for(j = 0;j < i;j++)
    {
        free(cou[j]);
    }
    free(cou);
    for(m = 0;m < peo;m++)
    {
        free(b[m].grade);
        free(b[m].gender);
    }
    fclose(p);

    printf("成绩排序完成！\n");
}

/*-----------------------------------------------------------------
 *  函数名 ：output
 *  功能   ：统计某门课程的优秀率、及格率以及优秀人数与及格人数
 *  参数   ：FILE *p
 *  返回值 ：无
-----------------------------------------------------------------*/
void statistics(FILE *p)
{
    struct student a;
    char c,**cou;
    int i,j,m,n,k,sum = 0;

    p = fopen("student.csv","r");
    if(p == NULL)
    {
        printf("打开文件失败！\n");
        exit(0);
    }

    for( i = 0 ; c != '\n' ; )
    {
        c = fgetc(p);
        if( c == ',')
        {
            i++;
        }
    }
    i = i - 5;
    rewind(p);

    a.grade = (float*)malloc(i*sizeof(float));
    if(a.grade == NULL)
    {
        printf("分配内存失败！");
        exit(1);
    }

    cou = (char**)malloc(i*sizeof(char*));
    if(cou == NULL)
    {
        printf("分配内存失败！");
        free(a.grade);
        exit(1);
    }
    for(j = 0;j < i;j++)
    {
        cou[j] = (char*)malloc(sizeof(char[40]));
        if(cou[j] == NULL)
        {
            printf("分配内存失败！");
            free(a.grade);
            for(m = 0;m < j;m++)
            {
                free(cou[m]);
            }
            free(cou);
            exit(1);
        }
    }

    for( j = 0 ; j < 5 ;)
    {
        c = fgetc(p);
        if( c == ',' )
        {
            j++;
        }
    }

    for( m = 0 ; m < i ; m++ )
    {
        for( n = 0 ;  ; n++ )
        {
            cou[m][n] = fgetc(p);
            if( cou[m][n] == ',' || cou[m][n] == '\n' )
            {
                cou[m][n] = '\0';
                break;
            }
        }
    }

    rewind(p);

    printf("请选择要进行统计的课程：\n");

    for(j = 0;j < i;j++)
    {
        printf("%d.%s\n",j+1,cou[j]);
    }

    do
    {
        scanf("%d",&k);
        if(k <= 0 || k > i)
        {
            printf("输入错误，请重新输入！\n");
        }
    }
    while(k <= 0 || k > i);

    m = 0;
    n = 0;

    while(fgetc(p)!='\n');

    do
    {
        fscanf(p,"%ld,",&a.num);

        for(j = 0;;j++)
        {
            a.name[j] = fgetc(p);
            if(a.name[j] == ',')
            {
                a.name[j] = '\0';
                break;
            }
        }
        for(j = 0;;j++)
        {
            a.Class[j] = fgetc(p);
            if(a.Class[j] == ',')
            {
                a.Class[j] = '\0';
                break;
            }
        }
        for(j = 0;;j++)
        {
            a.gender[j] = fgetc(p);
            if(a.gender[j] == ',')
            {
                a.gender[j] = '\0';
                break;
            }
        }
        for(j = 0;;j++)
        {
            a.Pnum[j] = fgetc(p);
            if(a.Pnum[j] == ',')
            {
                a.Pnum[j] = '\0';
                break;
            }
        }

        for(j = 0;j < i;j++)
        {
            fscanf(p,"%f,",&a.grade[j]);
        }
        fscanf(p,"%f\n",&a.sum);

        if(a.grade[k-1] >= 90)
        {
            m++;
        }
        if(a.grade[k-1] >= 60)
        {
            n++;
        }
        sum++;
    }
    while(feof(p) == 0);

    printf("%s的优秀率为：%%%.2f\n优秀人数为：%d\n",cou[k-1],1.0f*m/sum*100.0f,m);
    printf("%s的及格率为：%%%.2f\n及格人数为：%d\n",cou[k-1],1.0f*n/sum*100.0f,n);

    free(a.grade);
    for(j = 0;j < i;j++)
    {
        free(cou[j]);
    }
    free(cou);

    fclose(p);
}
