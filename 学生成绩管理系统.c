#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct student{                                                                 //����һ���ṹ��
       long num;
       char name[40];
       char Class[20];
       char *gender;
       char Pnum[20];
       float *grade;
       float sum;
       };
void help(void);                                                                //��ʾ��������
int input(FILE *);                                                              //����ѧ����Ϣ�������ļ�
void numfind(FILE *);                                                           //ͨ��ѧ�Ų���ѧ��
void namefind(FILE *);                                                          //ͨ����������ѧ��
void output(FILE *);                                                            //���ѧ����Ϣ����ʾ��
void sortsum(FILE *);                                                           //�����ֽܷ�������
void sortcou(FILE *);                                                           //����ĳһ��Ŀ��������
void statistics(FILE *);                                                        //ͳ�������ʺͼ�����

int main(void)
{
    FILE *p;                                                                    //����һ���ļ�ָ��
    int key = 1;                                                                //����һ�����ͱ������ڲ��񰴼�

    while(1)
    {
        system("CLS");                                                          //�����ʾ���ϵ�����
        printf("**************************** \n");                              //��ʾϵͳ������
        printf("ѧ���ɼ�����ϵͳ  \n");
        printf("**************************** \n");
        printf("************************************ \n");
        printf("**    F1 --����                   ** \n");
        printf("**    F2 --�������ݲ������ļ�     ** \n");
        printf("**    F3 --����ѧ�Ų�ѯ�ɼ�       ** \n");
        printf("**    F4 --����������ѯ�ɼ�       ** \n");
        printf("**    F5 --����ļ�����           ** \n");
        printf("**    F6 �C�ɼ�����               ** \n");
        printf("**    F7 --ͳ�Ƽ������������     ** \n");
        printf("**    ESC--�˳�ϵͳ               ** \n");
        printf("************************************ \n");

        key = getch();                                                          //���񰴼�
        switch(key)
        {
            case 59:
                system("CLS");                                                  //�����ʾ���ϵ�����
                help();                                                         //��ʾ��������
                system("Pause");                                                //�����������
                break;
            case 60:
                system("CLS");                                                  //�����ʾ���ϵ�����
                input(p);                                                       //����ѧ����Ϣ�������ļ�
                break;
            case 61:
                system("CLS");                                                  //�����ʾ���ϵ�����
                numfind(p);                                                     //ͨ��ѧ�Ų���ѧ��
                system("Pause");
                break;
            case 62:
                system("CLS");                                                  //�����ʾ���ϵ�����
                namefind(p);                                                    //ͨ����������ѧ��
                system("Pause");
                break;
            case 63:
                system("CLS");                                                  //�����ʾ���ϵ�����
                output(p);                                                      //���ѧ����Ϣ����ʾ��
                system("Pause");
                break;
            case 64:
                system("CLS");                                                  //�����ʾ���ϵ�����
                printf("��ѡ��\n");                                           //�����ʾ��Ϣ
                printf("1.��ĳ�ųɼ���������\n");
                printf("2.���ֽܷ�������\n");
                while(1)
                {
                    key = getch();                                              //���񰴼�
                    if(key == 49)
                    {
                        system("CLS");                                          //�����ʾ���ϵ�����
                        sortcou(p);                                             //����ĳһ��Ŀ��������
                        break;
                    }
                    if(key == 50)
                    {
                        system("CLS");                                          //�����ʾ���ϵ�����
                        sortsum(p);                                             //�����ֽܷ�������
                        break;
                    }
                }
                system("Pause");
                break;
            case 65:
                system("CLS");                                                  //�����ʾ���ϵ�����
                statistics(p);                                                  //ͳ�������ʺͼ�����
                system("Pause");
                break;
            case 27:
                system("CLS");                                                  //�����ʾ���ϵ�����
                return 0;                                                       //���ص�0
        }
    }
}
/*---------------------------------------------------------
 *  ������ ��help
 *  ����   ����ʾ������Ϣ
 *  ����   ����
 *  ����ֵ ����
---------------------------------------------------------*/

void help(void)
{
    printf("ʹ�ð�����\n\n");
    printf("�������ݲ������ļ���\n");
    printf("�������水��F2�����ģʽ��\n");
    printf("����һ���������ݣ�����Ҫ������γ̵��������Իس����������ٸ�����ʾ��������γ̵����ƣ��Իس���������\n");
    printf("������γ������Ϳγ����ƺ�����ظ���������ʱ����Ҫ������ʾ����������ѧ������Ϣ��\n");
    printf("����Ҫ��������ʱ��������ʾѡ��������뼴�ɡ�\n\n");
    printf("����ѧ�Ų�ѯ�ɼ���\n");
    printf("�������水��F3�����ģʽ��\n");
    printf("������ʾ������Ҫ���ҵ�ѧ����ѧ�ţ��Իس���������\n");
    printf("�����ļ��д���ѧ��������ѧ�ŵ�ѧ���������ʾ��ѧ������Ϣ��\n");
    printf("�����ļ���û�д���ѧ��������ѧ�ŵ�ѧ���������ʾδ�ҵ���ѧ����\n");
    printf("���ҽ����󣬰�������˳���\n\n");
    printf("����������ѯ�ɼ���\n");
    printf("�������水��F4�����ģʽ��\n");
    printf("������ʾ������Ҫ���ҵ�ѧ�����������Իس���������\n");
    printf("�����ļ��д�������������������ѧ���������ʾ��ѧ������Ϣ��\n");
    printf("�����ļ���û�д�������������������ѧ���������ʾδ�ҵ���ѧ����\n");
    printf("���ҽ����󣬰�������˳���\n\n");
    printf("����ļ����ݣ�\n");
    printf("�������水��F5�����ģʽ��\n");
    printf("�ļ��е�ѧ����Ϣ���������ʾ���ϡ�\n");
    printf("��������˳���\n\n");;
    printf("�ɼ�����\n");
    printf("�������水��F6�����ģʽ��\n");
    printf("������ʾѡ���ĳ�ųɼ������������ֽܷ�������\n");
    printf("��ѡ���ĳ�ųɼ������������������ʾѡ��Ҫ��������Ŀγ̣�����γ���ţ��Իس�������\n");
    printf("��������󣬻������ʾ����ʱ�ļ��е�ѧ����Ϣ���������Ķ������ϵ��½������С�\n");
    printf("��������˳���\n\n");
    printf("ͳ�Ƽ��������������\n");
    printf("�������水��F7�����ģʽ��\n");
    printf("������ʾѡ��Ҫ����ͳ�ƵĿγ̣�����γ���ţ��Իس�������\n");
    printf("�ÿγ̵������ʺͼ����ʻ���ʾ������\n");
    printf("��������˳�\n\n");
    printf("�˳�ϵͳ��\n");
    printf("����ESC�˳�ϵͳ��\n");
}

/*---------------------------------------------------------
 *  ������ ��input
 *  ����   ������ѧ����Ϣ
 *  ����   ��FILE *p
 *  ����ֵ ����
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
            printf("�ļ�����/��ʧ�ܣ�");
            exit(0);
        }

        fprintf(p,"%s,%s,%s,%s,%s,","ѧ��","����","�༶","�Ա�","��ϵ�绰");

        printf("������γ̵�������");
        scanf("%d",&i);
        getchar();

        cou = (char**)malloc(i*sizeof(char*));
        if(cou == NULL)
        {
            printf("�����ڴ�ʧ�ܣ�");
            exit(1);
        }
        for(j = 0;j < i;j++)
        {
            cou[j] = (char*)malloc(sizeof(char[40]));
            if(cou[j] == NULL)
            {
                printf("�����ڴ�ʧ�ܣ�");
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
            printf("�����ڴ�ʧ�ܣ�");
            for(j = 0;j < i;j++)
            {
                free(cou[j]);
            }
            free(cou);
            exit(1);
        }

        for( j = 0 ; j < i ; j++ )
        {
            printf("������γ�%d�����ƣ�",j+1);
            gets(*(cou+j));
            fprintf(p,"%s,",cou[j]);
        }

        fprintf(p,"%s\n","�ܷ�");

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
            printf("�����ڴ�ʧ�ܣ�");
            exit(1);
            }
            for(j = 0;j < i;j++)
            {
                cou[j] = (char*)malloc(sizeof(char[40]));
                if(cou[j] == NULL)
                {
                    printf("�����ڴ�ʧ�ܣ�");
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
            printf("�����ڴ�ʧ�ܣ�");
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

    printf("������ѧ�������ݣ�\n");

    printf("������ѧ����ѧ�ţ�");
    scanf("%ld",&a.num);
    getchar();
    fprintf(p,"%ld,",a.num);

    printf("������ѧ��Ϊ%ld��ѧ����������",a.num);
    gets(a.name);
    fprintf(p,"%s,",a.name);

    printf("������ѧ��Ϊ%ld��ѧ���İ༶��",a.num);
    gets(a.Class);
    fprintf(p,"%s,",a.Class);

    printf("��ѡ��ѧ��Ϊ%ld��ѧ�����Ա�\n",a.num);
    printf("1:��\n2:Ů\n");

    while(1)
    {
        key = getch();

        if(key == 49)
        {
            a.gender = "��";
            break;
        }
        else if(key == 50)
        {
            a.gender = "Ů";
            break;
        }
    }
    fprintf(p,"%s,",a.gender);

    printf("������ѧ��Ϊ%ld��ѧ������ϵ�绰��",a.num);
    gets(a.Pnum);
    fprintf(p,"%s,",a.Pnum);


    for( j = 0 ; j < i ; j++ )
    {
        printf("������ѧ��Ϊ%ld��ѧ����%s�ĳɼ���",a.num,cou[j]);
        scanf("%f",&a.grade[j]);
        getchar();
        a.sum = a.sum + a.grade[j];
        fprintf(p,"%f,",a.grade[j]);
    }

    fprintf(p,"%f\n",a.sum);

    while(1)
    {
        system("CLS");
        printf("Enter:��������\nEsc:��������\n");
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
 *  ������ ��numfind
 *  ����   ������ѧ�Ų�ѯѧ����Ϣ
 *  ����   ��FILE *p
 *  ����ֵ ����
 -----------------------------------------------*/
void numfind(FILE *p)
{
    struct student a;
    long num;
    char c,**cou;
    int i,j,m,n;

    printf("������Ҫ���ҵ�ѧ�ţ�");
    scanf("%ld",&num);
    getchar();

    p = fopen("student.csv","r");
    if(p == NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
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
        printf("�����ڴ�ʧ�ܣ�");
        exit(1);
    }

    cou = (char**)malloc(i*sizeof(char*));
    if(cou == NULL)
    {
        printf("�����ڴ�ʧ�ܣ�");
        free(a.grade);
        exit(1);
    }
    for(j = 0;j < i;j++)
    {
        cou[j] = (char*)malloc(sizeof(char[40]));
        if(cou[j] == NULL)
        {
            printf("�����ڴ�ʧ�ܣ�");
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
            printf("���ҽ��Ϊ��\n");
            printf("ѧ�ţ�%ld\n",a.num);
            printf("������%s\n",a.name);
            printf("�༶��%s\n",a.Class);
            printf("�Ա�%s\n",a.gender);
            printf("��ϵ�绰��%s\n",a.Pnum);

            for(j = 0;j < i;j++)
            {
                fscanf(p,"%f,",&a.grade[j]);
                printf("%s�ĳɼ�Ϊ��%.2f\n",cou[j],a.grade[j]);
            }
            fscanf(p,"%f\n",&a.sum);
            printf("�ܷ�Ϊ��%.2f\n",a.sum);
            break;
        }
        if(c == EOF)
        {
            printf("δ�ҵ���ѧ�ţ�\n");
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
 *  ������ ��namefind
 *  ����   ������������ѯѧ����Ϣ
 *  ����   ��FILE *p
 *  ����ֵ ����
---------------------------------------------------------*/
void namefind(FILE *p)
{
    struct student a;
    char name[40],**cou;
    char c;
    int i,j,m,n;

    printf("������Ҫ���ҵ�������");
    gets(name);

    p = fopen("student.csv","r");
    if(p == NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
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
        printf("�����ڴ�ʧ�ܣ�");
        exit(1);
    }

    cou = (char**)malloc(i*sizeof(char*));
    if(cou == NULL)
    {
        printf("�����ڴ�ʧ�ܣ�");
        free(a.grade);
        exit(1);
    }
    for(j = 0;j < i;j++)
    {
        cou[j] = (char*)malloc(sizeof(char[40]));
        if(cou[j] == NULL)
        {
            printf("�����ڴ�ʧ�ܣ�");
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

            printf("���ҽ��Ϊ��\n");
            printf("ѧ�ţ�%ld\n",a.num);
            printf("������%s\n",a.name);
            printf("�༶��%s\n",a.Class);
            printf("�Ա�%s\n",a.gender);
            printf("��ϵ�绰��%s\n",a.Pnum);

            for(j = 0;j < i;j++)
            {
                fscanf(p,"%f,",&a.grade[j]);
                printf("%s�ĳɼ�Ϊ��%.2f\n",cou[j],a.grade[j]);
            }
            fscanf(p,"%f\n",&a.sum);
            printf("�ܷ�Ϊ��%.2f\n",a.sum);
            break;
            }
        }

        if(c == EOF)
        {
            printf("δ�ҵ���������\n");
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
 *  ������ ��output
 *  ����   �����ѧ����Ϣ
 *  ����   ��FILE *p
 *  ����ֵ ����
---------------------------------------------------------*/
void output(FILE *p)
{
    struct student a;
    char c,**cou;
    int i,j,m,n;

    p = fopen("student.csv","r");
    if(p == NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
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
        printf("�����ڴ�ʧ�ܣ�");
        exit(1);
    }

    cou = (char**)malloc(i*sizeof(char*));
    if(cou == NULL)
    {
        printf("�����ڴ�ʧ�ܣ�");
        free(a.grade);
        exit(1);
    }
    for(j = 0;j < i;j++)
    {
        cou[j] = (char*)malloc(sizeof(char[40]));
        if(cou[j] == NULL)
        {
            printf("�����ڴ�ʧ�ܣ�");
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

    printf("%-15s","ѧ��");
    printf("%-15s","����");
    printf("%-15s","�༶");
    printf("%-15s","�Ա�");
    printf("%-15s","��ϵ�绰");
    for(j = 0;j < i;j++)
    {
        printf("%-15s",cou[j]);
    }
    printf("%-15s\n","�ܷ�");
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
 *  ������ ��output
 *  ����   ������ѧ���ֶܷ�ѧ�����н�������
 *  ����   ��FILE *p
 *  ����ֵ ����
---------------------------------------------------------*/
void sortsum(FILE *p)
{
    struct student a,*b;
    char c,**cou;
    int i,j,m,n,peo;

    p = fopen("student.csv","r");
    if(p == NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
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
        printf("�����ڴ�ʧ�ܣ�");
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
        printf("�����ڴ�ʧ�ܣ�");
        free(b);
        exit(1);
    }

    for(j = 0;j < peo;j++)
    {
        b[j].grade = (float*)malloc(i*sizeof(float));
        b[j].gender = (char*)malloc(5*sizeof(char));
        if(b[j].grade == NULL)
        {
            printf("�����ڴ�ʧ�ܣ�");
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
            printf("�����ڴ�ʧ�ܣ�");
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
        printf("�����ڴ�ʧ�ܣ�");
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
            printf("�����ڴ�ʧ�ܣ�");
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
        printf("�ļ���ʧ�ܣ�");
        exit(0);
    }

    fprintf(p,"%s,%s,%s,%s,%s,","ѧ��","����","�༶","�Ա�","��ϵ�绰");

    for(j = 0;j < i;j++)
    {
        fprintf(p,"%s,",cou[j]);
    }

    fprintf(p,"%s\n","�ܷ�");

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

    printf("�ɼ�������ɣ�\n");
}
/*---------------------------------------------------------
 *  ������ ��output
 *  ����   ������ѧ��ĳһ�γ̵ĳɼ���ѧ�����н�������
 *  ����   ��FILE *p
 *  ����ֵ ����
---------------------------------------------------------*/
void sortcou(FILE *p)
{
    struct student a,*b;
    char c,**cou;
    int i,j,m,n,peo,k;

    p = fopen("student.csv","r");
    if(p == NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
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
        printf("�����ڴ�ʧ�ܣ�");
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
        printf("�����ڴ�ʧ�ܣ�");
        free(b);
        exit(1);
    }

    for(j = 0;j < peo;j++)
    {
        b[j].grade = (float*)malloc(i*sizeof(float));
        b[j].gender = (char*)malloc(5*sizeof(char));
        if(b[j].grade == NULL)
        {
            printf("�����ڴ�ʧ�ܣ�");
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
            printf("�����ڴ�ʧ�ܣ�");
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
        printf("�����ڴ�ʧ�ܣ�");
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
            printf("�����ڴ�ʧ�ܣ�");
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

    printf("��ѡ��Ҫ��������Ŀγ̣�\n");

    for(j = 0;j < i;j++)
    {
        printf("%d.%s\n",j+1,cou[j]);
    }

    do
    {
        scanf("%d",&k);
        if(k <= 0 || k > i)
        {
            printf("����������������룡\n");
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
        printf("�ļ���ʧ�ܣ�");
        exit(0);
    }

    fprintf(p,"%s,%s,%s,%s,%s,","ѧ��","����","�༶","�Ա�","��ϵ�绰");

    for(j = 0;j < i;j++)
    {
        fprintf(p,"%s,",cou[j]);
    }

    fprintf(p,"%s\n","�ܷ�");

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

    printf("�ɼ�������ɣ�\n");
}

/*-----------------------------------------------------------------
 *  ������ ��output
 *  ����   ��ͳ��ĳ�ſγ̵������ʡ��������Լ����������뼰������
 *  ����   ��FILE *p
 *  ����ֵ ����
-----------------------------------------------------------------*/
void statistics(FILE *p)
{
    struct student a;
    char c,**cou;
    int i,j,m,n,k,sum = 0;

    p = fopen("student.csv","r");
    if(p == NULL)
    {
        printf("���ļ�ʧ�ܣ�\n");
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
        printf("�����ڴ�ʧ�ܣ�");
        exit(1);
    }

    cou = (char**)malloc(i*sizeof(char*));
    if(cou == NULL)
    {
        printf("�����ڴ�ʧ�ܣ�");
        free(a.grade);
        exit(1);
    }
    for(j = 0;j < i;j++)
    {
        cou[j] = (char*)malloc(sizeof(char[40]));
        if(cou[j] == NULL)
        {
            printf("�����ڴ�ʧ�ܣ�");
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

    printf("��ѡ��Ҫ����ͳ�ƵĿγ̣�\n");

    for(j = 0;j < i;j++)
    {
        printf("%d.%s\n",j+1,cou[j]);
    }

    do
    {
        scanf("%d",&k);
        if(k <= 0 || k > i)
        {
            printf("����������������룡\n");
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

    printf("%s��������Ϊ��%%%.2f\n��������Ϊ��%d\n",cou[k-1],1.0f*m/sum*100.0f,m);
    printf("%s�ļ�����Ϊ��%%%.2f\n��������Ϊ��%d\n",cou[k-1],1.0f*n/sum*100.0f,n);

    free(a.grade);
    for(j = 0;j < i;j++)
    {
        free(cou[j]);
    }
    free(cou);

    fclose(p);
}
