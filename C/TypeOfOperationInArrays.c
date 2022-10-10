#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
void addspace(char *buff)//ฟังก์ชั่นเพื่อเว้นวรรคเครื่องหมายเพื่อตรวจสอบ
{
	int i,j;//ประกาศตัวแปร
	char str[255];//ประกาศตัวแปร
	for (i=0,j=0;i<strlen(buff);i++)//วนลูปให้เท่ากับความยาวของข้อมูล
	{
		if (strchr("+-*/^()",buff[i])!=NULL)//strchrเป็นคำสั่งที่เอาไว้เช็คว่าในbuffตัวที่iมี+-*/^()หรือไม่
		{
			str[j]=' ';//ให้ค่าjตัวแรกเป็นเว้นวรรค
      j++;//เพิ่มค่าjเพิ่มไปอีก1
			str[j++]=buff[i];//ให้ค่าstr=buffแล้วเพิ่มค่าjเพิ่มไปอีก1
			str[j]=' ';//ให้ค่าjตัวสุดท้ายเป็นเว้นวรรค
      j++;//เพิ่มค่าjเพิ่มไปอีก1
		}
		else
			str[j++]=buff[i];//ถ้าเกิดว่ามันตรวจแล้วว่าตรวจดูแล้วไม่เจอมันจะให้เท่ากับตัวนั้นเลย
	}
	str[j]='\0';//เปลี่ยนตัวสุดท้ายให้เป็น\0เพราะว่าตัวสุัดท้ายของstringต้องเป็น\0ป้องกันerrorเพื่อไม่ให้อ่านต่อ
	strcpy(buff,str);//ให้strมาใส่ในตัวรับค่าที่ชื่อว่าbuff
}
int trim(char *buff,char token[][40])//เป็นฟังก์ชั่นสำหรับเว้นวรรค
{
	int count=0;//ประกาศตัวแปร
	char *tok;//ประกาศตัวแปร
	tok=strtok(buff," ");//เป็นคำสั่งที่ทำให้สเปซบาร์กลายเป็นตัวสุดท้าย
	while (tok!=NULL)//วนรอบจนกว่า tok จะเท่าNULL
	{
		strcpy(token[count++],tok);//เอาค่าtokไปเก็บไว้ในtoken แล้วเอาค่าtokไปใช้ต่อ
		tok=strtok(NULL," ");//เป็นคำสั่งเปลี่ยนค่าNULLหรือตัวสุดท้ายของ string ให้เป็นเว้นวรรค
	}
	return count;//คืนค่า count ออกมา
}
int checkoperator(char *str)//ฟังก์ชั่นสำหรับตรวจดูว่ามีเครื่องหมาย+-*/()^มั้ย
{
    if((strlen(str)==1)&&(strchr("+-*/()^",str[0])!=NULL))//ถ้าความยาวตัวอักษรเท่ากับ1และเป็น+-*/()^
        return 1;//คืนค่า 1 ออกมา
    else
        return 0; //คืนค่า  0 ออกมา
}
int checknumber (char *str,double *n)//ฟังก์ชั่นสำหรับเช็คว่าเป็นตัวเลขหรือไม่
{
    char bug;//ประกาศตัวแปร
    if(sscanf(str,"%lf%c",n,&bug)==1)//รับค่าstrมาตรวจว่ามีค่าไหนที่เป็นตัวเลขหรือไม่
        return 1;//คืนค่า 1 ออกมา
    else
        return 0;//คืนค่า  0 ออกมา
}
int checkfunction(char *str)//สำหรับเช็คฟังก์ชั่น
{
    char buff[15],namefunction[15][20]={"pow","sin","cos","tan","asin","acos","atan","sqrt","abs","log","exp"};//ประกาศตัวแปรเพื่อเช็คว่าเป็นชื่อฟังก์ชั่นหรือไม่
    int fcount = 11,i=0;//ประกาศตัวแปร
    strcpy(buff,str);//เป็นคำสั่งที่เอาbuffมารับค่าของstrแล้วเอามาใช้ต่อในฟังก์ชั่น
    strlwr(buff);//เป็นคำสั่งที่ทำให้ค่าbuffที่เข้ามากลายเป็นตัวพิมพ์เล็ก
    while (i<fcount&&strcmp(namefunction[i],buff)!=0)//วนรอบจนกว่าจะครบตามจำนวนฟังก์ชั่นและค่าที่ใส่ไปไม่ตรงกับฟังก์ชั่น
        i++;//เพิ่มค่า i เรื่อยๆทีละ1
    if(i<fcount)//ถ้าค่าiมาค่าน้อยกว่า 11
        return 1;//จะคืนค่า1ออกมา
    else
        return 0;//จะคืนค่า0ออกมา
}
int checkidentifier(char *str)//เป็นฟังก์ชั่นสำหรับดูว่าค่าที่ใส่เข้าไปเป็นตัวแปรหรือไม่
{
    int flag=1,i,len=strlen(str);//ประกาศตัวแปร
    if((isalpha(str[0]))||str[0]=='_')//ถ้าตัวแรกที่ใส่ค่าเข้าไปเป็นตัวอักษรหรือ __
    {
        for (i=1;i<len;i++)//วนรอบจนกว่าจะครบตามจำนวนของข้อมูล
            if (!(isalpha(str[i])||isdigit(str[i])||str[i]=='_'))//ถ้าไม่ใช่ตัวอักษร หรือตัวเลข หรือ _ มั้ย
                flag = 0;//ถ้าไม่ใช่ค่าflag = 0
        return flag;//ถ้าใช่จะคืนค่า 0
    }
    else
        return 0;//ถ้าตัวแรกที่ใส่ค่าเข้าไปไม่เป็นตัวอักษรหรือ __ จะคืนค่า 0
}

int check_end(int count,char *str)//เป็นฟังก์ชั่นเช็คend กับ exit
{
	if (count==1&&(strcmp("end",str)==0||count==1&&(strcmp("exit",str))==0)) //ถ้าตัวอักษรในฟังก์ชั่นมี 1 ค่า เเละมาดูว่าเป็น end หรือ exit
	{
		return 1; //คืนค่า 1 ออกมา
	}
	else{
		return 0;//คืนค่า 0 ออกมา
		}
}

int main()//ฟังก์ชั่นหลัก
{
	char str[255],buff[255],token[20][40];//ประกาศตัวแปร
	int count,i,amount[5]={0,0,0,0,0};//ประกาศตัวแปร
	double n;//ประกาศตัวแปร
    while(check_end(count,*token)!=1){
    printf("Input your message : ");//แสดงค่าInput your message :
    gets(str);//รับค่า string
    strcpy(buff,str);//เอาค่าstr ที่มาใส่มนbuffเพิ้อเอามาใช้ในฟังก์ชั่นหลัก
    strlwr(buff);//ทำให้ค่าbuffที่ป้อนเข้าไปกลายเป็นตัวพิมพ์เล็ก
    addspace(buff);//เรียกใช้ฟังก็ชั่น addspace
    while(buff[strlen(buff)]==' ') //ถ้า buff เป็น เว้นวรรค
        buff[strlen(buff)]=='\0';//ให้เปลี่ยนเป็น \0
    printf("%s\n",buff);//แสดงผลค่า buffที่ใส่เว้นวรรคแล้ว
    count = trim(buff,token);//เอา count มารับค่าในการใช้ฟังก์ชันtrim จะได้รู้ว่ามีการแบ่งกี่รอบ
    printf("%d tokens\n",count);//บอกว่ามีข้อมูลกี่อัน
    if (check_end(count,*token)==1) //ถ้าใช้ฟังก์ชั่น check end เเล้วค่าที่รีเทิร์นจากฟังก์ชั่นนั้นมาเป็น 1
		{
			printf("End Progarm\n"); //ปริ้นค่าEnd Progarm
		}
		else
		{
    for(i=0;i<count;i++)//วนลูปจนกว่าจะเท่ากับจำนวนข้อมูล
    {
        printf("  <%d> = %s \n",i+1,token[i]);//แสดงตำแหน่งของข้อมูล และแสดงว่าข้อมูลนั้นอยู่ตรงไหน
        if(checkoperator(token[i])==1)//ถ้าข้อมูลที่ใส่ไปตัวนั้นเป็นoperator
        {
            printf("%s = operator><\n",token[i]);//จะปริ้นข้อมูลตัวนั้นและ=operator><
            amount[0]++;//เพิ่มค่าอาเรย์ตำแหน่งamount[0]ไปอีก1ค่า
        }
        else if(checkfunction(token[i])==1)//ถ้าข้อมูลที่ใส่ไปตัวนั้นเป็นfunction
        {
            printf("%s = function>3<\n",token[i]);//จะปริ้นข้อมูลตัวนั้นและ= function>3<
            amount[1]++;//เพิ่มค่าอาเรย์ตำแหน่งamount[1]ไปอีก1ค่า

        }
        else if(checknumber(token[i],&n)==1)//ถ้าข้อมูลที่ใส่ไปตัวนั้นเป็นnumber
        {
            printf("%s = number = %g >-<\n",token[i],n);//จะปริ้นข้อมูลตัวนั้นและ= number
            amount[2]++;//เพิ่มค่าอาเรย์ตำแหน่งamount[2]ไปอีก1ค่า
        }
        else if(checkidentifier(token[i])==1)//ถ้าข้อมูลที่ใส่ไปตัวนั้นเป็นidentifier
        {
            printf("%s = identifier >.<\n",token[i]);//จะปริ้นข้อมูลตัวนนั้นและ
            amount[3]++;//เพิ่มค่าอาเรย์ตำแหน่งamount[3]ไปอีก1ค่า
        }
        else//ถ้าไม่ใช่อะไรเลย
        {
            printf("%s = error! T^T \n",token[i]);//จะปริ้นข้อมูลตัวนนั้น และerror! T^T
            amount[4]++;//เพิ่มค่าอาเรย์ตำแหน่งamount[4]ไปอีก1ค่า
        }
    }
        printf("\nhave %d operator : ",amount[0]);//ปริ้นออกมาว่ามี operater กี่ตัว
        for(i=0;i<count;i++)//วนรอบจนกว่าจะเท่ากับจำนวน count
        {
            if (checkoperator(token[i])==1)//ถ้า token นั้นเป็น Operator
                printf(" %s",token[i]);//ปริ้นค่า tokenที่เป็น operaterออกมา
        }
        printf("\nhave %d function : ",amount[1]);//ปริ้นออกมาว่ามี function กี่ตัว
        for(i=0;i<count;i++)//วนรอบจนกว่าจะเท่ากับจำนวน count
        {
            if (checkfunction(token[i])==1)//ถ้า tokenนั้นเป็น function
                printf(" %s",token[i]);//ปริ้นค่า tokenที่เป็น function ออกมา
        }
        printf("\nhave %d number : ",amount[2]);//ปริ้นออกมาว่ามี number กี่ตัว
        for(i=0;i<count;i++)//วนรอบจนกว่าจะเท่ากับจำนวน count
        {
            if (checknumber(token[i],&n)==1)//ถ้า tokenนั้นเป็น number
                printf(" %s",token[i]);//ปริ้นค่า tokenที่เป็น number ออกมา
        }
        printf("\nhave %d identifier : ",amount[3]);//ปริ้นออกมาว่ามี identifier กี่ตัว
        for(i=0;i<count;i++)//วนรอบจนกว่าจะเท่ากับจำนวน count
        {
            if (checkfunction(token[i])==1)//ถ้า token เป็น funtion
            {
                //ไม่แสดงผลอะไรเลยเพื่อดักชื่อฟังก์ชันที่เป็น Identifier
            }
            else if(checkidentifier(token[i])==1)//ถ้า token นั้นเป็น identifier
                printf(" %s",token[i]);//ปริ้นค่า tokenที่เป็น identifier ออกมา
        }

        printf("\nhave %d error : ",amount[4]);//ปริ้นจำนวนที่มันerror
        for(i=0;i<count;i++)//วนรอบจนกว่าจะเท่ากับจำนวน count
        {
            if (checkoperator(token[i])!=1&&checkidentifier(token[i])!=1&&checkfunction(token[i])!=1&&checknumber(token[i],&n)!=1)//ถ้าไม่ใช่พวกนี้
                printf(" %s",token[i]);//แสดงค่าtokenที่ไม่ใช่ออกมา
        }
        rewind(stdin);//กันบัค
        printf("\nTry again y.y\n");//ปริ้นTry again y.y
        getch();//รับค่า String

        amount[0]=0;//รีเซ็ตค่าให้เริ่มตั้นจาก0
        amount[1]=0;//รีเซ็ตค่าให้เริ่มตั้นจาก0
        amount[2]=0;//รีเซ็ตค่าให้เริ่มตั้นจาก0
        amount[3]=0;//รีเซ็ตค่าให้เริ่มตั้นจาก0
        amount[4]=0;//รีเซ็ตค่าให้เริ่มตั้นจาก0
    }
    }
    return 0;//จบการทำงานของโปรแกรม
}
