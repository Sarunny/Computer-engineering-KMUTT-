#include<stdio.h>
#include<stdlib.h>
#include<search.h>
#include<math.h>
#include<string.h>
int acount,bpcount,bcount,cpcount,ccount,dpcount,dcount,fcount;//��˹������
double min,max,mean,sd,minmid,maxmid,meanmid,sdmid,minfi,maxfi,meanfi,sdfi,minatt,maxatt,meanatt,sdatt;//��˹������

struct grade_info //��С�����ç���ҧ�����Ż����� struct
{
    long long id; //��С�ȵ����
    char name[40];//��С�ȵ����
    double mid,fi,att,total,gpoint;//��С�ȵ����
    char grade[3];//��С�ȵ����
};
typedef struct grade_info gradetype;//�繤���觷��͡��� grade_info ���� gradetype

void Load_Student_File (char *name,gradetype st[],int *stcount) //�ѧ��������������Ŵ���
{
    FILE *fp; //��С�ȵ��������������
    gradetype x; // ��С�ȵ����������ҹ������ 1 ���
    char fname[15],lname[30];//��С�ȵ����
    if ((fp = fopen("SCORE.CSV", "r")) != NULL ) // ��Ǩ�ͺ����Դ���
    {
        *stcount=0; //��˹�����������ǹѺ�ӹǹ������
        while(fscanf(fp,"%llu,%[^,],%lf,%lf,%lf",&x.id,x.name,&x.mid,&x.fi,&x.att)==5)//ǹ�ٻ�����Ѻ���
    {
        x.total = x.mid+x.fi+x.att; // �ӹǳ��ṹ���
        st[*stcount] = x; // �Ӣ����� x �����ҹ������ st
        *stcount = *stcount+1; } // �Ѻ�����ӹǹ�����ŷ����ҹ��
        fclose(fp); // �Դ���
        printf("\nTotal read %d records. ",*stcount);//���鹤�� stcount �͡��
    }
    else
    printf("\nError Can't Read File DATA.CSV\n");//��ҵ�Ǩ�ͺ����Դ��������л��鹤����Error Can't Read File DATA.CSV
}

void print_data(gradetype x)//�ѧ�����������ʴ������� 1 ��
{
    printf("%llu %-40s %5.1lf %5.1lf %5.1lf %5.1lf %5.1lf %s\n", x.id, x.name,x.mid, x.fi, x.att,x.total, x.gpoint, x.grade);//�ʴ���� id,nae,mid,final,total,gpoint,grade �͡��
}

void Show_All_Data (gradetype st[], int stcount)//�ѧ�����������ʴ������ŷ�����
{
    int i;//��С�ȵ����
    for (i = 0; i<stcount; i++)//ǹ�ٻ�����ҨФú�֧����ش����
{
    printf("%3d)",i+1);
    print_data(st[i]);//���¡��ѧ����priny_data
}
}

void Sort_by_id (gradetype st[], int stcount) //�ѧ�������������§�ӴѺ������ʻ�Шӵ�Ǩҡ������ҡ
{
    int i, j ;//��˹������
    gradetype x;//��˹������
    for (i = 0; i < stcount-1; i++) //ǹ�ͺ���֧��ǡ�͹�ش����
    for (j = i+1; j < stcount; j++) //ǹ�ͺj�·��j�ҡ����i 1 ���˹�
    if (st[j].id < st[i].id) //��ҵ��˹觶Ѵ仹��¡��ҵ��˹觡�͹˹��
    {
        x = st[i]; //��ҵ���á��ҡѺX
        st[i] = st[j];//��ҵ���á��ҡѺ��ҵ����ѧ
        st[j] = x;//��ҵ����ѧ��ҡѺX(��ҵ���á)
    }
}

void Sort_by_total ( gradetype st[], int stcount) // �ѧ�������������§�ӴѺ�����ṹ�ҡ�ҡ仹���
{
    int i, j ;//��С�ȵ����
    gradetype x;//��С�ȵ���û����� gradetype
        for (i = 0; i < stcount-1; i++) //ǹ�ͺ���֧��ǡ�͹�ش����
        for (j = i+1; j < stcount; j++) //ǹ�ͺj�·��j�ҡ����i 1 ���˹�
        if (st[j].total > st[i].total) //���§�ҡ�ҡ仹���
    {
        x = st[i]; //�š����¹ data
        st[i] = st[j];//��ҵ���á��ҡѺ��ҵ����ѧ

        st[j] = x;//��ҵ����ѧ��ҡѺX(��ҵ���á)
    }
}

void Search_Score (gradetype st[], int stcount)// �ѧ������������Ҩҡ��ṹ����������ҧ������ҡ
{
    double min, max; // ��С�ȵ����
    int i , count;// ��С�ȵ����
    char ch ;// ��С�ȵ����
    do
    {
        printf("\n Enter Range of min score and max score "); //�ʴ���Ҿǡ����͡��
        scanf("%lf %lf", &min , &max);// ��ҹ��� min max
        count = 0;
    printf("\n========================================================================================\n");//�ʴ���Ҿǡ����͡��
    printf("     ID     ||                  NAME                  ||MID||FINAL||ATTEN||TOTAL||GRADE||\n");//�ʴ���Ҿǡ����͡��
    printf("=========================================================================================\n");//�ʴ���Ҿǡ����͡��
        for (i = 0; i<stcount; i++) //ǹ�ͺ��ҡѺ�ӹǹ��.
        {
            if (st[i].total >= min && st[i].total <= max)//��ͧ�����ŷ������㹪�ǧ min - max
            {
                count = count + 1;//�Ѻ�ӹǹ
                printf("%2d)",count);//�ʴ��Źѡ�֡�Ҥ����
                print_data(st[i]);//�ʴ������Źѡ�֡��
            }
        }
    printf("========================================================================================\n");//�ʴ���Ҿǡ����͡��
    }
    while (ch == 'y');//ǹ�ͺ�����Ҩж١��͹��� y
}

void Search_Grade (gradetype st[], int stcount) //�ѧ������������Ҩҡ�ô
{
    char key[3];//��С�ȵ����
    int i , count ; //��С�ȵ����
    do
    {
        printf("\n Search Grade (A, B+, B, ... F or 0 = Exit) ");//�ʴ���Ҿǡ����͡��
        scanf("%2s", key); // ��ҹʵ�ԧ����Թ 2 ����ѡ��
        count = 0;//set��� count���=0
    if (strcmp(key,"0") != 0)//��� key �����ҡѺ 0
    {
    printf("\n=======================================================================================\n");//�ʴ���Ҿǡ����͡��
    printf("     ID     ||                  NAME                  ||MID||FINAL||ATTEN||TOTAL||GRADE||\n");//�ʴ���Ҿǡ����͡��
    printf("=========================================================================================\n");//�ʴ���Ҿǡ����͡��
    }
    for (i = 0; i<stcount; i++)//ǹ�ͺ��ҡѺ�ӹǹ�ѡ�֡��
    {
        if (strcmp(st[i].grade,key)==0)//���grade=key����Ѻ��
        {
            count = count + 1;//�Ѻ�ӹǹ
            printf("%2d)",count);//�ʴ��Źѡ�֡�Ҥ����
            print_data(st[i]);//�ʴ������Źѡ�֡��
        }
    }
    printf("========================================================================================\n");//�ʴ���Ҿǡ����͡��
    }while (strcmp(key, "0") !=0);//ǹ�ͺ������ key ���� 0
}

void Search_Name (gradetype st[], int stcount) //�ѧ����蹷����Ҥ��ҡ����
{
    char key[16];//��С�ȵ����
    int i, count;//��С�ȵ����
    do
    {
        printf("\n Enter Search key (0 = Exit) ");//�ʴ���Ҿǡ����͡��
        scanf("%15s", key); // ��ҹʵ�ԧ����Թ 15 ����ѡ��
        count = 0;//��������count = 0
    if (strcmp(key,"0") != 0)//��� key�����ҡѺ 0
    {
    printf("\n=======================================================================================\n");//�ʴ���Ҿǡ����͡��
    printf("     ID     ||                  NAME                  ||MID||FINAL||ATTEN||TOTAL||GRADE||\n");//�ʴ���Ҿǡ����͡��
    printf("=========================================================================================\n");//�ʴ���Ҿǡ����͡��

    }
    for (i = 0; i<stcount; i++)//ǹ�ͺ��ҡѺ�ӹǹ�ѡ�֡��
    if (strstr(st[i].name, key) != NULL) //��餹� �ҧ��� ���
        {
            count = count + 1;//�Ѻ�ӹǹ
            printf("%2d)",count);//�ʴ��Źѡ�֡�Ҥ����
            print_data(st[i]);//�ʴ������Źѡ�֡��
        }
    } while (strcmp(key,"0")!=0);//ǹ�ͺ������ key ���� 0
}

void grade_setting(gradetype st[], int stcount, double *a, double *bp,double *b, double *cp, double *c, double *dp, double *d,double A,double Bp,double B,double Cp,double C,double Dp,double D) //�ѧ���蹷��������ӹǳ�ô
{
    int i ;//��С�ȵ����
    acount=bpcount=bcount=cpcount=ccount=dpcount=dcount=fcount=0;//�絤�Ҩӹǹ�ô������ ��ҡѺ0
    for (i=0; i<stcount; i++)//ǹ�ͺ��ҡѺ�ӹǹ�ѡ�֡��
    if (st[i].total >=A)//��Ҥ�ṹ����ҡ����������ҡѺ��Ңͧ A
    {
        strcpy(st[i].grade,"A"); st[i].gpoint=4.0;//����ô��ҡѺ A ��� 4.0
        acount++;//������Ҥ�������ô���
    }
    else if (st [i].total >=Bp)//��Ҥ�ṹ����ҡ����������ҡѺ��Ңͧ B+
    {
        strcpy(st[i].grade,"B+"); st[i].gpoint=3.5;////����ô��ҡѺ B+ ��� 3.5
        bpcount++;//������Ҥ�������ô���
    }
    else if (st[i].total >=B)//��Ҥ�ṹ����ҡ����������ҡѺ��Ңͧ B
    {
        strcpy(st[i].grade,"B"); st[i].gpoint=3.0;//����ô��ҡѺ B ��� 3.0
        bcount++;//������Ҥ�������ô���
    }
    else if (st[i].total >=Cp)//��Ҥ�ṹ����ҡ����������ҡѺ��Ңͧ C+
    {
        strcpy(st[i].grade,"C+"); st[i].gpoint=2.5;//����ô��ҡѺ C+ ��� 2.5
        cpcount++;//������Ҥ�������ô���
    }
    else if (st[i].total >=C)//��Ҥ�ṹ����ҡ����������ҡѺ��Ңͧ C
    {
        strcpy(st[i].grade,"C"); st[i].gpoint=2.0;//����ô��ҡѺ C ��� 2.0
        ccount++;//������Ҥ�������ô���
    }
    else if (st[i].total >=Dp)//��Ҥ�ṹ����ҡ����������ҡѺ��Ңͧ D+
    {
        strcpy(st[i].grade,"D+"); st[i].gpoint=1.5;//����ô��ҡѺ D+ ��� 1.5
        dpcount++;//������Ҥ�������ô���
    }
    else if (st[i].total >=D)//��Ҥ�ṹ����ҡ����������ҡѺ��Ңͧ D
    {
        strcpy(st[i].grade,"D"); st[i].gpoint=1.0;//����ô��ҡѺ D ��� 1.0
        dcount++;//������Ҥ�������ô���
    }
    else
    {
        strcpy(st[i].grade,"F") ; st[i].gpoint=0;//����ô��ҡѺ F ��� 0
        fcount++;//������Ҥ�������ô���
    }
}

void find_stat ( gradetype st[], int stcount,
                      double *min, double *max,double *mean, double *sd,
                      double *minmid,double *maxmid,double *meanmid,double *sdmid,
                      double *minfi,double *maxfi,double *meanfi,double *sdfi,
                      double *minatt,double *maxatt,double *meanatt,double *sdatt) //�繿ѧ���蹷����ӹǳ�Ҥ�ҷҧʶԵ�
{
    int i; //��С�ȵ����
    double sum=0,sumsqr=0,summid=0,sumsqrmid=0,sumfi=0,sumsqrfi=0,sumatt=0,sumsqratt=0;//��С�ȵ����
    *min = *max = st[0].total;//��˹����������鹢ͧmin,max�ͧ��ṹ��������ҡѺ 0
    *minmid = *maxmid = st[0].mid;//��˹����������鹢ͧmin,max�ͧ��ṹ midterm �����ҡѺ 0
    *minfi = *maxfi = st[0].fi;//��˹����������鹢ͧmin,max�ͧ��ṹ final �����ҡѺ 0
    *minatt = *maxatt = st[0].att;//��˹����������鹢ͧmin,max�ͧ��ṹ�������ҡѺ 0
    for (i=0; i<stcount; i++)//ǹ�ٻ�����Ҩж֧�����ŵ���ش����
    {
        if (st[i].total < *min)//��Ҥ�ṹ������¡��Ҥ�ҷ����·���ش
        {
            *min = st[i].total;//�ӹǳ�Ҥ�ҷ���ӷ���ش�ͧ��ṹ���
        }
        if (st[i].total > *max)//��Ҥ�ṹ����ҡ���Ҥ�ҷ���ҡ����ش
        {
            *max = st[i].total;//�ӹǳ�Ҥ�ҷ���٧����ش�ͧ��ṹ���
        }
        if (st[i].mid < *minmid)//��Ҥ�ṹ��ҧ�Ҥ���¡��Ҥ�ҷ����·���ش
        {
            *minmid = st[i].mid;//�ӹǳ�Ҥ�ҷ���ӷ���ش�ͧ��ṹ midterm
        }
        if (st[i].mid > *maxmid)//��Ҥ�ṹ��ҧ�Ҥ�ҡ���Ҥ�ҷ���ҡ����ش
        {
            *maxmid = st[i].mid;//�ӹǳ�Ҥ�ҷ���٧����ش�ͧ��ṹ midterm
        }
        if (st[i].fi < *minfi)//��Ҥ�ṹ�����Ҥ���¡��Ҥ�ҷ����·���ش
        {
            *minfi = st[i].fi;//�ӹǳ�Ҥ�ҷ���ӷ���ش�ͧ��ṹ final
        }
        if (st[i].fi > *maxfi)//��Ҥ�ṹ�����Ҥ�ҡ���Ҥ�ҷ���ҡ����ش
        {
            *maxfi = st[i].fi;//�ӹǳ�Ҥ�ҷ���٧����ش�ͧ��ṹ final
        }
        if (st[i].att < *minatt)//��Ҥ�ṹ�ҹ���¡��Ҥ�ҷ����·���ش
        {
            *minatt = st[i].att;//�ӹǳ�Ҥ�ҷ���ӷ���ش�ͧ��ṹ atten
        }
        if (st[i].att > *maxatt)//��Ҥ�ṹ�ҹ�ҡ���Ҥ�ҷ���ҡ����ش
        {
            *maxatt = st[i].att;//�ӹǳ�Ҥ�ҷ���٧����ش�ͧ��ṹ atten
        }
        sum = sum+st[i].total; //�ӹǳ�Ҥ�� sum
        sumsqr = sumsqr + pow(st[i].total,2);//�ӹǳ�Ҥ�� sumsqr
        summid = summid +st[i].mid;//�ӹǳ�Ҥ�� summid
        sumsqrmid = sumsqrmid + pow(st[i].mid,2);//�ӹǳ�Ҥ�� sumsqrmid
        sumfi = sumfi+st[i].fi;//�ӹǳ�Ҥ�� sumfi
        sumsqrfi = sumsqrfi + pow(st[i].fi,2);//�ӹǳ�Ҥ�� sumsqrfi
        sumatt = sumatt+st[i].att;//�ӹǳ�Ҥ�� sumatt
        sumsqratt = sumsqratt + pow(st[i].att,2);//�ӹǳ�Ҥ�� sumsqratt
    }
    *mean = sum/stcount;//�ӹǳ�� mean �ͧ��ṹ���
    *meanmid = summid/stcount;//�ӹǳ�� meanmid  �ͧ��ṹmidterm
    *sdmid = sqrt(sumsqrmid/stcount - pow(*meanmid,2));//�ӹǳ�� sdmid �ͧ��ṹmidterm
    *sd = sqrt(sumsqr/stcount - pow(*mean,2));//�ӹǳ�� sd �ͧ��ṹ���
    *meanfi = sumfi/stcount;//�ӹǳ�� mean �ͧ��ṹ final
    *sdfi = sqrt(sumsqrfi/stcount - pow(*meanfi,2));//�ӹǳ��sd�ͧ��ṹfinal
    *meanatt = sumatt/stcount;//�ӹǳ�� mean �ͧ��ṹ��
    *sdatt = sqrt(sumsqratt/stcount - pow(*meanatt,2));//�ӹǳ�� sd �ͧ��ṹ��
}
void show_stat(gradetype st[],int stcount)//�ѧ�����ʴ��Ť��ʶԵ�
{
    int i;//��С�ȵ����
    double gpa=0;//��С�ȵ����
    find_stat(st,stcount,&min,&max,&mean,&sd,&minmid,&maxmid,&meanmid,&sdmid,&minfi,&maxfi,&meanfi,&sdfi,&minatt,&maxatt,&meanatt,&sdatt);//���¡��ѧ���蹤ӹǳ���ʶԵ�
    for(i=0; i<stcount; i++)//ǹ�ٻ�����Ҩж֧�����ŵ���ش����
    {
        gpa = gpa + st[i].gpoint;//�ӹǳ GPA
    }
    gpa = gpa/stcount;//�ӹǳ GPA
    printf("\n****************************************************************\n");//�ʴ���Ҿǡ����͡��
    printf("*   Score   *    mid    *    final   *    atten   *    total   *\n");//�ʴ���Ҿǡ����͡��
    printf("****************************************************************\n");//�ʴ���Ҿǡ����͡��
    printf("*   min     *   %6.2lf  *   %6.2lf   *   %6.2lf   *   %6.2lf   *\n", minmid,minfi,minatt,min);//�ʴ���ҹ����ش�ͧ���Ф�ṹ
    printf("*   max     *   %6.2lf  *   %6.2lf   *   %6.2lf   *   %6.2lf   *\n", maxmid,maxfi,maxatt,max);//�ʴ���ҹ�ҡ�ش�ͧ���Ф�ṹ
    printf("*   mean    *   %6.2lf  *   %6.2lf   *   %6.2lf   *   %6.2lf   *\n", meanmid,meanfi,meanatt,mean);//�ʴ��������¢ͧ���Ф�ṹ
    printf("*   sd      *   %6.2lf  *   %6.2lf   *   %6.2lf   *   %6.2lf   *\n", sdmid,sdfi,sdatt,sd);//�ʴ����SD�ͧ���Ф�ṹ
    printf("****************************************************************\n");//�ʴ���Ҿǡ����͡��
    printf("\n");
    printf("*************************************************************\n");//�ʴ���Ҿǡ����͡��
    printf("*   score   *   A *  B+ *   B *  C+ *   C *  D+ *  D  *  F  *\n");//�ʴ���Ҿǡ����͡��
    printf("*   count   *  %2d *  %2d *  %2d *  %2d *  %2d *  %2d *  %1d  *  %2d *\n", acount, bpcount, bcount, cpcount, ccount, dpcount, dcount, fcount);//�ʴ��ŵ���Ţ�ӹǹ�������ô�����ô
    printf("*************************************************************\n");//�ʴ���Ҿǡ����͡��
    printf("\nGPA : %.2lf\n", gpa);//�ʴ��� GPA
}

int get_int(int min,int max)//�ѧ����������ѡ����٧�ش����ش
{
	int ans;//��˹������
	char ch;//��˹������
	while((scanf("%d%c",&ans,&ch)!=1&&ch!='\n')||ans<min||ans>max)//�礨ӹǹ�������д��������㹢ͧࢵ����˹�min max �������
	{
	rewind(stdin);
	printf("error please input again!!.");//�ʴ�error please input again!!. �͡��
	}
	return ans;//�觤��ans���
}

int get_menu()//�繿ѧ�������¡������
{
	int select;//��˹������
	printf("##################################################\n");//output �ǡ����͡��
	printf("#                 Manu of Calculate              #\n");//output �ǡ����͡��
	printf("##################################################\n");//output �ǡ����͡��
	printf("#              1. Read file                      #\n");//output �ǡ����͡��
	printf("#              2. Calculate grade                #\n");//output �ǡ����͡��
	printf("#              3. Calculate stat                 #\n");//output �ǡ����͡��
	printf("#              4. Show all student               #\n");//output �ǡ����͡��
	printf("#              5. Show student by score          #\n");//output �ǡ����͡��
    printf("#              6. Show student by ID             #\n");//output �ǡ����͡��
    printf("#              7. Show student by min,max        #\n");//output �ǡ����͡��
    printf("#              8. Show student by grade          #\n");//output �ǡ����͡��
    printf("#              9. Show student by name           #\n");//output �ǡ����͡��
    printf("#              0. EXIT                           #\n");//output �ǡ����͡��
	printf("##################################################\n");//output �ǡ����͡��
	printf("Input your number >o< :");//output �ǡ����͡��
	select = get_int(0,9);//��˹������������¡��ѧ���� get_int ������Ţ���� 0-9
	return select;//�觤�� select ���
}

int main()//�ѧ������ѡ
{
    gradetype st[100];//��˹������
    int stcount;//��˹������
    int select,count=0;//��˹������
    double a,bp,b,cp,c,dp,d;//��˹������
    char file_name[100];//��˹������
    double A,Bp,B,Cp,C,Dp,D;//��˹������
    double sum_gpa;//��˹������
    double min,max,mean,sd,minmid,maxmid,meanmid,sdmid,minfi,maxfi,meanfi,sdfi,minatt,maxatt,meanatt,sdatt;//��˹������
    do
    {
        select = get_menu();//��˹���� sel ������¡��ѧ��ѹ menu
        if(select==1)//���select=1��������͹䢹��
        {
            system("cls");//����� clear screen
            Load_Student_File ("SCORE.CSV",st,&stcount);//���¡��ѧ�����Դ���
            if(stcount==0)//����Դ�ӹǹ�ѡ���¹��ҡѺ 0
            {
                printf("cant reading file T_T \n");//���ʴ���Ҿǡ����͡��
            }
            else//��������
            {
                printf("reading COMPLETE!!! \n");//���ʴ���Ҿǡ����͡��
                printf("total : %d \n",stcount);//�͡�ӹǹ��
                count=1;//��Ǩ�ͺ�����ҹ����ѧ

            }
        }
        else if(select==2&&count>0)//��� select=2 ��������͹䢹��
        {
            system("cls");//����� clear screen
            printf("Input grade : ");//���ʴ���Ҿǡ����͡��
            scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf",&A,&Bp,&B,&Cp,&C,&Dp,&D);//�Ѻ����ô
            grade_setting(st,stcount,&a,&bp,&b,&cp,&c,&dp,&d,A,Bp,B,Cp,C,Dp,D);//���¡��ѧ����grade_setting
            show_stat(st,stcount);//���¡��ѧ�����ʴ����ʶԵ�
        }
        else if(select==3&&count>0)//���select=3 ��������͹䢹��
        {
            system("cls");//����� clear screen
            show_stat(st,stcount);//���¡��ѧ�����ʴ����ʶԵ�
        }
        else if(select==4&&count>0)//���select=4 ��������͹䢹��
        {
            system("cls");//����� clear screen
            Show_All_Data(st,stcount);//���¡��ѧ�����ʴ������Źѡ�֡��
        }
        else if(select==5&&count>0)//���select=5 ��������͹䢹��
        {
            system("cls");//����� clear screen
            Sort_by_total(st,stcount);//���¡��ѧ���� Sort_by_total
            Show_All_Data(st,stcount);//���¡��ѧ�����ʴ������Źѡ�֡��
        }
        else if(select==6&&count>0)//���select=6 ��������͹䢹��
        {
            system("cls");//����� clear screen
            Sort_by_id(st,stcount);//���¡��ѧ���� Sort_by_id
            Show_All_Data(st,stcount);//���¡��ѧ�����ʴ������Źѡ�֡��
        }
        else if(select==7&&count>0)//���select=7 ��������͹䢹��
        {
            system("cls");//����� clear screen
            Search_Score(st,stcount);//���¡��ѧ���� Search_Score
        }
        else if(select==8&&count>0)//���select=8 ��������͹䢹��
        {
            system("cls");//����� clear screen
            Search_Grade(st,stcount);//���¡��ѧ���� Search_Grade
        }
        else if(select==9&&count>0)//���select=9 ��������͹䢹��
        {
            system("cls");//����� clear screen
            Search_Name(st,stcount);//���¡��ѧ���� Search_Name
        }
    }
    while(select!=0);//�зӵ������� sel=0
    printf("**  End Program  **\n");//�ʴ���ҹ���͡��
    return 0;//����÷ӧҹ�ͧ�����
}
