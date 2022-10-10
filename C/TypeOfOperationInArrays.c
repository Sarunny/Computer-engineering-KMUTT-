#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
void addspace(char *buff)//�ѧ�������������ä����ͧ�������͵�Ǩ�ͺ
{
	int i,j;//��С�ȵ����
	char str[255];//��С�ȵ����
	for (i=0,j=0;i<strlen(buff);i++)//ǹ�ٻ�����ҡѺ������Ǣͧ������
	{
		if (strchr("+-*/^()",buff[i])!=NULL)//strchr�繤���觷��������������buff��Ƿ��i��+-*/^()�������
		{
			str[j]=' ';//�����j����á�������ä
      j++;//�������j������ա1
			str[j++]=buff[i];//�����str=buff�����������j������ա1
			str[j]=' ';//�����j����ش�����������ä
      j++;//�������j������ա1
		}
		else
			str[j++]=buff[i];//����Դ����ѹ��Ǩ������ҵ�Ǩ������������ѹ�������ҡѺ��ǹ�����
	}
	str[j]='\0';//����¹����ش���������\0������ҵ����Ѵ���¢ͧstring��ͧ��\0��ͧ�ѹerror������������ҹ���
	strcpy(buff,str);//���str�����㹵���Ѻ��ҷ��������buff
}
int trim(char *buff,char token[][40])//�繿ѧ��������Ѻ�����ä
{
	int count=0;//��С�ȵ����
	char *tok;//��С�ȵ����
	tok=strtok(buff," ");//�繤���觷�������໫��������繵���ش����
	while (tok!=NULL)//ǹ�ͺ������ tok �����NULL
	{
		strcpy(token[count++],tok);//��Ҥ��tok�������token ������Ҥ��tok�����
		tok=strtok(NULL," ");//�繤��������¹���NULL���͵���ش���¢ͧ string ����������ä
	}
	return count;//�׹��� count �͡��
}
int checkoperator(char *str)//�ѧ��������Ѻ��Ǩ�����������ͧ����+-*/()^����
{
    if((strlen(str)==1)&&(strchr("+-*/()^",str[0])!=NULL))//��Ҥ�����ǵ���ѡ����ҡѺ1�����+-*/()^
        return 1;//�׹��� 1 �͡��
    else
        return 0; //�׹���  0 �͡��
}
int checknumber (char *str,double *n)//�ѧ��������Ѻ������繵���Ţ�������
{
    char bug;//��С�ȵ����
    if(sscanf(str,"%lf%c",n,&bug)==1)//�Ѻ���str�ҵ�Ǩ����դ���˹����繵���Ţ�������
        return 1;//�׹��� 1 �͡��
    else
        return 0;//�׹���  0 �͡��
}
int checkfunction(char *str)//����Ѻ�礿ѧ����
{
    char buff[15],namefunction[15][20]={"pow","sin","cos","tan","asin","acos","atan","sqrt","abs","log","exp"};//��С�ȵ��������������繪��Ϳѧ�����������
    int fcount = 11,i=0;//��С�ȵ����
    strcpy(buff,str);//�繤���觷�����buff���Ѻ��Ңͧstr�������������㹿ѧ����
    strlwr(buff);//�繤���觷��������buff�������ҡ����繵�Ǿ�������
    while (i<fcount&&strcmp(namefunction[i],buff)!=0)//ǹ�ͺ�����ҨФú����ӹǹ�ѧ������Ф�ҷ���������ç�Ѻ�ѧ����
        i++;//������� i ����������1
    if(i<fcount)//��Ҥ��i�Ҥ�ҹ��¡��� 11
        return 1;//�Ф׹���1�͡��
    else
        return 0;//�Ф׹���0�͡��
}
int checkidentifier(char *str)//�繿ѧ��������Ѻ����Ҥ�ҷ����������繵�����������
{
    int flag=1,i,len=strlen(str);//��С�ȵ����
    if((isalpha(str[0]))||str[0]=='_')//��ҵ���á�������������繵���ѡ������ __
    {
        for (i=1;i<len;i++)//ǹ�ͺ�����ҨФú����ӹǹ�ͧ������
            if (!(isalpha(str[i])||isdigit(str[i])||str[i]=='_'))//�����������ѡ�� ���͵���Ţ ���� _ ����
                flag = 0;//����������flag = 0
        return flag;//�����Ф׹��� 0
    }
    else
        return 0;//��ҵ���á����������������繵���ѡ������ __ �Ф׹��� 0
}

int check_end(int count,char *str)//�繿ѧ������end �Ѻ exit
{
	if (count==1&&(strcmp("end",str)==0||count==1&&(strcmp("exit",str))==0)) //��ҵ���ѡ��㹿ѧ������ 1 ��� �����Ҵ������ end ���� exit
	{
		return 1; //�׹��� 1 �͡��
	}
	else{
		return 0;//�׹��� 0 �͡��
		}
}

int main()//�ѧ������ѡ
{
	char str[255],buff[255],token[20][40];//��С�ȵ����
	int count,i,amount[5]={0,0,0,0,0};//��С�ȵ����
	double n;//��С�ȵ����
    while(check_end(count,*token)!=1){
    printf("Input your message : ");//�ʴ����Input your message :
    gets(str);//�Ѻ��� string
    strcpy(buff,str);//��Ҥ��str ����������buff�����������㹿ѧ������ѡ
    strlwr(buff);//�������buff����͹���仡����繵�Ǿ�������
    addspace(buff);//���¡��ѧ���� addspace
    while(buff[strlen(buff)]==' ') //��� buff �� �����ä
        buff[strlen(buff)]=='\0';//�������¹�� \0
    printf("%s\n",buff);//�ʴ��Ť�� buff�����������ä����
    count = trim(buff,token);//��� count ���Ѻ���㹡����ѧ��ѹtrim �����������ա���觡���ͺ
    printf("%d tokens\n",count);//�͡����բ����š���ѹ
    if (check_end(count,*token)==1) //�����ѧ���� check end ����Ǥ�ҷ�������침ҡ�ѧ���蹹������ 1
		{
			printf("End Progarm\n"); //���鹤��End Progarm
		}
		else
		{
    for(i=0;i<count;i++)//ǹ�ٻ�����Ҩ���ҡѺ�ӹǹ������
    {
        printf("  <%d> = %s \n",i+1,token[i]);//�ʴ����˹觢ͧ������ ����ʴ���Ң����Ź������ç�˹
        if(checkoperator(token[i])==1)//��Ң����ŷ�����仵�ǹ����operator
        {
            printf("%s = operator><\n",token[i]);//�л��鹢����ŵ�ǹ�����=operator><
            amount[0]++;//���������������˹�amount[0]��ա1���
        }
        else if(checkfunction(token[i])==1)//��Ң����ŷ�����仵�ǹ����function
        {
            printf("%s = function>3<\n",token[i]);//�л��鹢����ŵ�ǹ�����= function>3<
            amount[1]++;//���������������˹�amount[1]��ա1���

        }
        else if(checknumber(token[i],&n)==1)//��Ң����ŷ�����仵�ǹ����number
        {
            printf("%s = number = %g >-<\n",token[i],n);//�л��鹢����ŵ�ǹ�����= number
            amount[2]++;//���������������˹�amount[2]��ա1���
        }
        else if(checkidentifier(token[i])==1)//��Ң����ŷ�����仵�ǹ����identifier
        {
            printf("%s = identifier >.<\n",token[i]);//�л��鹢����ŵ�ǹ������
            amount[3]++;//���������������˹�amount[3]��ա1���
        }
        else//���������������
        {
            printf("%s = error! T^T \n",token[i]);//�л��鹢����ŵ�ǹ��� ���error! T^T
            amount[4]++;//���������������˹�amount[4]��ա1���
        }
    }
        printf("\nhave %d operator : ",amount[0]);//�����͡������� operater �����
        for(i=0;i<count;i++)//ǹ�ͺ�����Ҩ���ҡѺ�ӹǹ count
        {
            if (checkoperator(token[i])==1)//��� token ����� Operator
                printf(" %s",token[i]);//���鹤�� token����� operater�͡��
        }
        printf("\nhave %d function : ",amount[1]);//�����͡������� function �����
        for(i=0;i<count;i++)//ǹ�ͺ�����Ҩ���ҡѺ�ӹǹ count
        {
            if (checkfunction(token[i])==1)//��� token����� function
                printf(" %s",token[i]);//���鹤�� token����� function �͡��
        }
        printf("\nhave %d number : ",amount[2]);//�����͡������� number �����
        for(i=0;i<count;i++)//ǹ�ͺ�����Ҩ���ҡѺ�ӹǹ count
        {
            if (checknumber(token[i],&n)==1)//��� token����� number
                printf(" %s",token[i]);//���鹤�� token����� number �͡��
        }
        printf("\nhave %d identifier : ",amount[3]);//�����͡������� identifier �����
        for(i=0;i<count;i++)//ǹ�ͺ�����Ҩ���ҡѺ�ӹǹ count
        {
            if (checkfunction(token[i])==1)//��� token �� funtion
            {
                //����ʴ�������������ʹѡ���Ϳѧ��ѹ����� Identifier
            }
            else if(checkidentifier(token[i])==1)//��� token ����� identifier
                printf(" %s",token[i]);//���鹤�� token����� identifier �͡��
        }

        printf("\nhave %d error : ",amount[4]);//���鹨ӹǹ����ѹerror
        for(i=0;i<count;i++)//ǹ�ͺ�����Ҩ���ҡѺ�ӹǹ count
        {
            if (checkoperator(token[i])!=1&&checkidentifier(token[i])!=1&&checkfunction(token[i])!=1&&checknumber(token[i],&n)!=1)//��������ǡ���
                printf(" %s",token[i]);//�ʴ����token���������͡��
        }
        rewind(stdin);//�ѹ�Ѥ
        printf("\nTry again y.y\n");//����Try again y.y
        getch();//�Ѻ��� String

        amount[0]=0;//���絤������������鹨ҡ0
        amount[1]=0;//���絤������������鹨ҡ0
        amount[2]=0;//���絤������������鹨ҡ0
        amount[3]=0;//���絤������������鹨ҡ0
        amount[4]=0;//���絤������������鹨ҡ0
    }
    }
    return 0;//����÷ӧҹ�ͧ�����
}
