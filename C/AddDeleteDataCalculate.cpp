#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>

void Add_Data(double data[],int *count) //���ҧ�ѧ���蹹��������Ѻ������
	{ int i;//��С�ȵ����
		double a;//��С�ȵ����
		char ch;//��С�ȵ����
		printf("Input your number : ");//�ʴ���ҹ���͡��
		do {
		i = scanf("%lf%c",&a,&ch);//�Ѻ���i���͵�Ǩ�ͺ�ӹǹ�����
		if (i>0&&a>0)//���i>0���a>0
		{
			data[*count] = a;//�Ѻ��� a ����������
			*count = *count +1; } //�Ѻ�ӹǹ����������价���1
		}
		while (i!=0 && ch!='\n');//��Ǩ�ͺ�����١��ͧ�ͧ����������������ҡ� enter �������
		rewind(stdin);//�ѹ��Ҵ
	}

void printdata (double data[],int count)//���ҧ�ѧ���蹹���������ʴ���Ң�����
	{
		int i;//��С�ȵ����
		for(i=0;i<count;i++)//ǹ�ٻ�����ҨФú�ӹǹ�����ŷ������
		printf("data (%d) = %lf\n",i,data[i]);//�ʴ��Ţ����ŵ�����˹觢ͧ������
		printf("end\n");//�ʴ���ҹ���͡��

}

void sathiti (double data[],int count,double *max,double *min,double *mean,double *sd)//���ҧ�ѧ���蹹�������ͤӹǳ�����ŷҧʶԵ�
{
	int i;//��С�ȵ����
	double sum=0,sum2=0;//��С�ȵ����
	*min=data[0];//��˹���ҹ����ش����繵���á
	*max=data[0];//��˹�����ҡ�ش����繵���á
	for(i=0;i<count;i++)//ǹ�ٻ���ͤӹǳ���������ú����ӹǹ�������
	{
		sum=sum+data[i]; //�ӹǳ�����ǡ��������������
		sum2=sum2+(data[i]*data[i]);//�ӹǳ�����ǡ�����ŷ��¡���ѧ�ͧ��������
		if(*min>data[i])//��Ҥ��min�ҡ���Ҥ�ҵ�ǶѴ�
		*min=data[i];//�����min��ҡѺ��ҹ��
		if(*max<data[i])//��Ҥ��max���¡��Ҥ�ҵ�ǶѴ�
		*max=data[i];//�����max��ҡѺ��ҹ��
	}
	*mean=sum/count;//�ӹǳ��� mean������͡��ҹ��������
	*sd=sqrt(sum2/count-*mean**mean);//�ӹǳ��� sd������͡��ҹ��������

}

void deletena (double data[],int *count,int po )//���ҧ�ѧ���蹹���������ź������
{
	int i;//��С�ȵ����
	for(i=po;i<*count-1;i++)//ǹ�ٻ������Ƿ���ͧ���ź���֧����ͧ�ش����
	data[i]=data[i+1];//�������ŵ�ǶѴ���᷹��Ƿ��١ź�����
	*count=*count-1;//Ŵ�ӹǹ������
}

int searchja (double data[],int count,double del )//���ҧ�ѧ���蹹�����͵�Ǩ�ͺ��ҵ��˹��˹�����ҵ�ͧ��è�ź
{
	int i;//��С�ȵ����
	for(i=0;i<count;i++)//ǹ�ٻ�ҷء���
	{
		if(data[i]==del)//����͵�Ƿ���դ����ҡѺ��Ƿ���ͧ��è�ź
		return i;//�觤�� i �͡��

	}
	return -1;//�觤�� -1 �͡��
}
int get_int(int min,int max)//���ҧ�ѧ���蹹���������Ѻ��Ҩӹǹ���
{
	int ans;//��С�ȵ����
	char ch;//��С�ȵ����
	while((scanf("%d%c",&ans,&ch)!=1&&ch!='\n')||ans<min||ans>max)//��Ǩ�ͺ��ҵ������Тͺࢵ����˹�
	{
	rewind(stdin);//�ѹ��Ҵ
	printf("Input error please input again.");//�ʴ���ҹ���͡��
	}
	return ans;//�觤�� ans �͡��
}
int get_manu()//�ѧ��������Ѻ���͡�ѧ��ѹ����ͧ�����
{
	int select;//��С�ȵ����
	printf("##################################################\n");//�ʴ���ҹ���͡��
	printf("#                 Menu of Calculate              #\n");//�ʴ���ҹ���͡��
	printf("##################################################\n");//�ʴ���ҹ���͡��
	printf("#              1. Add Data                       #\n");//�ʴ���ҹ���͡��
	printf("#              2. Delete Data                    #\n");//�ʴ���ҹ���͡��
	printf("#              3. Calculate Stats                #\n");//�ʴ���ҹ���͡��
	printf("#              0. Exit                           #\n");//�ʴ���ҹ���͡��
	printf("##################################################\n");//�ʴ���ҹ���͡��
	printf("Enter your number :");//�ʴ���ҹ���͡��
	select = get_int(0,3);//�Ѻ������բͺࢵ������������ҧ 0-3
	return select;//�觤��select�͡��
}

int main ()//�ѧ��ѹ��ѡ
{
	double data[100],max,min,mean,sd,del;//��С�ȵ����
	int select,count=0,po;//��С�ȵ����
	char ch;//��С�ȵ����
	do
	{
		select = get_manu();//���¡������
		if (select==1)//���select==1
		{
			Add_Data(data,&count);//���¡��ѧ����Add_Data
			printdata (data,count);//���¡��ѧ����printdata
			getchar();//��Enter���͡�Ѻ仿ѧ��ѹ menu

		}
		else if (select==2)//���select==2
		{
			if(count<=0)//���count<=0
        {
            printf("cant delete\n");//�ʴ���ҹ���͡��
            printf("Enter to back to menu\n");//�ʴ���ҹ���͡��
            getchar();//��Enter���͡�Ѻ仿ѧ��ѹ menu
        }

        else {
                printdata(data,count);
                do
                {
                printf("Input delete data : ");//�ʴ���ҹ���͡��
                scanf("%lf",&del);//�Ѻ��ҷ���ͧ���ź
                po = searchja(data,count,del);//������դ�ҷ���ͧ���ź����㹢����Ţͧ����������
                if(po==-1)//�������դ�ҷ���ͧ��è�ź
                    printf("cant find\n",del);//�ʴ���ҹ���͡��
                }
                while(po==-1);//ǹ�ٻ�����Ҩ��դ�ҷ���ͧ��è�ź
                    do{
                    po = searchja(data,count,del);//������դ�ҷ���ͧ���ź����㹢����Ţͧ����������
                    if(po==-1)//�������դ�ҷ���ͧ��è�ź
                    	{
                    		printf("cant find\n",del);//�ʴ���ҹ���͡��
						}
                    else if(po>=0)//����դ�ҷ���ͧ���è�ź
                    {
					printf("R U sure? (y or n)",po,del);//�ʴ���ҹ���͡��
                    scanf(" %c",&ch);//�Ѻ��� y ���� n
                    if(ch=='y'||ch=='Y')//������ y,Y
                    {
                        deletena(data,&count,po);//���¡��ѧ����deletena����ź���
                        printdata(data,count);//���¡��ѧ����printdata�����ʴ����
                    }
                    else if(ch=='n'||ch=='N')//������ n,N
					printf("Cancel delete.\n");//�ʴ���ҹ���͡��
                    }
					}
                    while(po>=0&&ch!='n'&&ch!='N');//�͡�ҡ�ٻ��������������͹䢷��Դ

             }
             getchar();//��Enter���͡�Ѻ仿ѧ��ѹ menu
		}
		else if (select==3)//���select==3
		{
			if(count<=1) //���count=0
			{
			printf("cant calculate!!!!!!");//�ʴ���ҹ���͡��
			getchar();//��Enter���͡�Ѻ仿ѧ��ѹ menu
			}
			else{

			sathiti (data,count,&max,&min,&mean,&sd);//���¡��ѧ����sathiti���ͤӹǳ
			printf("mean = %lf\n",mean);//�ʴ����mean
			printf("sd = %lf\n",sd);//�ʴ����sd
			printf("max = %lf\n",max);//�ʴ����max
			printf("min = %lf\n",min);//�ʴ����min
			getchar();//��Enter���͡�Ѻ仿ѧ��ѹ menu
		}
		}

}while (select!=0);//�͡�ҡ���������select=0
return 0;//�������
}











