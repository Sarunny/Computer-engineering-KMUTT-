#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<windows.h>

void Add_Data(double data[],int *count) //สร้างฟังก์ชั่นนี้เพื่่อรับข้อมูล
	{ int i;//ประกาศตัวแปร
		double a;//ประกาศตัวแปร
		char ch;//ประกาศตัวแปร
		printf("Input your number : ");//แสดงค่านี้ออกมา
		do {
		i = scanf("%lf%c",&a,&ch);//รับค่าiเพื่อตรวจสอบจำนวนตัวแปร
		if (i>0&&a>0)//ถ้าi>0และa>0
		{
			data[*count] = a;//รับค่า a ใส่ในอาเรย์
			*count = *count +1; } //นับจำนวนข้อมูลเพิ่มไปทีละ1
		}
		while (i!=0 && ch!='\n');//ตรวจสอบความถูกต้องของข้อมูลและเมื่อเรากด enter ที่ใส่ไป
		rewind(stdin);//กันพลาด
	}

void printdata (double data[],int count)//สร้างฟังก์ชั่นนี้มาเพื่อแสดงค่าข้อมูล
	{
		int i;//ประกาศตัวแปร
		for(i=0;i<count;i++)//วนลูปจนกว่าจะครบจำนวนข้อมูลที่ใส่ไป
		printf("data (%d) = %lf\n",i,data[i]);//แสดงผลข้อมูลตามตำแหน่งของข้อมูล
		printf("end\n");//แสดงค่านี้ออกมา

}

void sathiti (double data[],int count,double *max,double *min,double *mean,double *sd)//สร้างฟังก์ชั่นนี้มาเพื่อคำนวณข้อมูลทางสถิติ
{
	int i;//ประกาศตัวแปร
	double sum=0,sum2=0;//ประกาศตัวแปร
	*min=data[0];//กำหนดค่าน้อยสุดให้เป็นตัวแรก
	*max=data[0];//กำหนดค่ามากสุดให้เป็นตัวแรก
	for(i=0;i<count;i++)//วนลูปเพื่อคำนวณข้อมูลให้ครบตามจำนวนที่ใส่ไป
	{
		sum=sum+data[i]; //คำนวณโดยให้บวกข้อมูลไปเรื่อยๆ
		sum2=sum2+(data[i]*data[i]);//คำนวณโดยให้บวกข้อมูลที่ยกกำลังสองไปเรื่อยๆ
		if(*min>data[i])//ถ้าค่าminมากกว่าค่าตัวถัดไป
		*min=data[i];//ให้ค่าminเท่ากับค่านั้น
		if(*max<data[i])//ถ้าค่าmaxน้อยกว่าค่าตัวถัดไป
		*max=data[i];//ให้ค่าmaxเท่ากับค่านั้น
	}
	*mean=sum/count;//คำนวณค่า meanและส่งออกผ่านพ้อยเตอร์
	*sd=sqrt(sum2/count-*mean**mean);//คำนวณค่า sdและส่งออกผ่านพ้อยเตอร์

}

void deletena (double data[],int *count,int po )//สร้างฟังก์ชั่นนี้มาเพื้่อลบข้อมูล
{
	int i;//ประกาศตัวแปร
	for(i=po;i<*count-1;i++)//วนลูปตั้งแต่ตัวที่ต้องการลบจนถึงตัวรองสุดท้าย
	data[i]=data[i+1];//ให้ข้อมูลตัวถัดไปมาแทนตัวที่ถูกลบไปแล้ว
	*count=*count-1;//ลดจำนวนข้อมูล
}

int searchja (double data[],int count,double del )//สร้างฟังก์ชั่นนี้เพื่อตรวจสอบว่าตำแหน่งไหนที่เราต้องการจะลบ
{
	int i;//ประกาศตัวแปร
	for(i=0;i<count;i++)//วนลูปหาทุกตัว
	{
		if(data[i]==del)//ถ้าเจอตัวที่มีค่าเท่ากับตัวที่ต้องการจะลบ
		return i;//ส่งค่า i ออกมา

	}
	return -1;//ส่งค่า -1 ออกมา
}
int get_int(int min,int max)//สร้างฟังก์ชั่นนี้มาเพื่อรับค่าจำนวนเต็ม
{
	int ans;//ประกาศตัวแปร
	char ch;//ประกาศตัวแปร
	while((scanf("%d%c",&ans,&ch)!=1&&ch!='\n')||ans<min||ans>max)//ตรวจสอบค่าตัวแปรและขอบเขตที่กำหนด
	{
	rewind(stdin);//กันพลาด
	printf("Input error please input again.");//แสดงค่านี้ออกมา
	}
	return ans;//ส่งค่า ans ออกมา
}
int get_manu()//ฟังก์ชั่นสำหรับเลือกฟังก์ชันที่ต้องการใช้
{
	int select;//ประกาศตัวแปร
	printf("##################################################\n");//แสดงค่านี้ออกมา
	printf("#                 Menu of Calculate              #\n");//แสดงค่านี้ออกมา
	printf("##################################################\n");//แสดงค่านี้ออกมา
	printf("#              1. Add Data                       #\n");//แสดงค่านี้ออกมา
	printf("#              2. Delete Data                    #\n");//แสดงค่านี้ออกมา
	printf("#              3. Calculate Stats                #\n");//แสดงค่านี้ออกมา
	printf("#              0. Exit                           #\n");//แสดงค่านี้ออกมา
	printf("##################################################\n");//แสดงค่านี้ออกมา
	printf("Enter your number :");//แสดงค่านี้ออกมา
	select = get_int(0,3);//รับค่าโดยมีขอบเขตที่อยู่ระหว่าง 0-3
	return select;//ส่งค่าselectออกมา
}

int main ()//ฟังก์ชันหลัก
{
	double data[100],max,min,mean,sd,del;//ประกาศตัวแปร
	int select,count=0,po;//ประกาศตัวแปร
	char ch;//ประกาศตัวแปร
	do
	{
		select = get_manu();//เรียกใช้เมนู
		if (select==1)//ถ้าselect==1
		{
			Add_Data(data,&count);//เรียกใช้ฟังก์ชั่นAdd_Data
			printdata (data,count);//เรียกใช้ฟังก์ชั่นprintdata
			getchar();//กดEnterเพื่อกลับไปฟังก์ชัน menu

		}
		else if (select==2)//ถ้าselect==2
		{
			if(count<=0)//ถ้าcount<=0
        {
            printf("cant delete\n");//แสดงค่านี้ออกมา
            printf("Enter to back to menu\n");//แสดงค่านี้ออกมา
            getchar();//กดEnterเพื่อกลับไปฟังก์ชัน menu
        }

        else {
                printdata(data,count);
                do
                {
                printf("Input delete data : ");//แสดงค่านี้ออกมา
                scanf("%lf",&del);//รับค่าที่ต้องการลบ
                po = searchja(data,count,del);//หาว่ามีค่าที่ต้องการลบอยู่ในข้อมูลของเราหรือไม่
                if(po==-1)//ถ้าไม่มีค่าที่ต้องการจะลบ
                    printf("cant find\n",del);//แสดงค่านี้ออกมา
                }
                while(po==-1);//วนลูปจนกว่าจะมีค่าที่ต้องการจะลบ
                    do{
                    po = searchja(data,count,del);//หาว่ามีค่าที่ต้องการลบอยู่ในข้อมูลของเราหรือไม่
                    if(po==-1)//ถ้าไม่มีค่าที่ต้องการจะลบ
                    	{
                    		printf("cant find\n",del);//แสดงค่านี้ออกมา
						}
                    else if(po>=0)//ถ้ามีค่าที่ต้องกาารจะลบ
                    {
					printf("R U sure? (y or n)",po,del);//แสดงค่านี้ออกมา
                    scanf(" %c",&ch);//รับค่า y หรือ n
                    if(ch=='y'||ch=='Y')//ถ้าใส่ y,Y
                    {
                        deletena(data,&count,po);//เรียกใช้ฟังก์ชั่นdeletenaเพื่อลบค่า
                        printdata(data,count);//เรียกใช้ฟังก์ชั่นprintdataเพื่อแสดงค่า
                    }
                    else if(ch=='n'||ch=='N')//ถ้าใส่ n,N
					printf("Cancel delete.\n");//แสดงค่านี้ออกมา
                    }
					}
                    while(po>=0&&ch!='n'&&ch!='N');//ออกจากลูปก็ต่อเมื่อมีเงื่อนไขที่ผิด

             }
             getchar();//กดEnterเพื่อกลับไปฟังก์ชัน menu
		}
		else if (select==3)//ถ้าselect==3
		{
			if(count<=1) //ถ้าcount=0
			{
			printf("cant calculate!!!!!!");//แสดงค่านี้ออกมา
			getchar();//กดEnterเพื่อกลับไปฟังก์ชัน menu
			}
			else{

			sathiti (data,count,&max,&min,&mean,&sd);//เรียกใช้ฟังก์ชั่นsathitiเพื่อคำนวณ
			printf("mean = %lf\n",mean);//แสดงค่าmean
			printf("sd = %lf\n",sd);//แสดงค่าsd
			printf("max = %lf\n",max);//แสดงค่าmax
			printf("min = %lf\n",min);//แสดงค่าmin
			getchar();//กดEnterเพื่อกลับไปฟังก์ชัน menu
		}
		}

}while (select!=0);//ออกจากเมนูเมื่อselect=0
return 0;//จบโปรแกรม
}











