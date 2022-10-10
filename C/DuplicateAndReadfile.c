#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <time.h>
int cmpfunc (const void * a, const void * b)//ฟังก์ชันเพื่อเปรียบเทียบฟังก์ชัน
{
    return ( *(int*)a - *(int*)b );
}
void loadfiletext(char *tname,int tdata[],int *tcount)//ประกาศฟังก์ชันสำหรับเปิดไฟล์ Text
{
    FILE *fp;//ประกาศตัวแปรประเภทไฟล์
    int a;//ประกาศตัวแปร
    *tcount = 0;//ให้ tcount เริ่มต้นที่ 0
    if((fp = fopen(tname,"r"))!=NULL)//ถ้าเปิดไฟล์ได้
    {
        while((fscanf(fp,"%d",&a))==1)//วนรอบจนกว่าจะตรงกับเงื่อนไข
        {
            tdata[*tcount]=a;// เอา a มาเก็บไว้ในอาร์เรย์ชื่อ tdata
            *tcount = *tcount +1;//เพิ่มค่า tcount ไปอีก 1
        }
        fclose(fp);//ปิดไฟล์
    }
    else//ถ้าอ่านไม่ได้
    {
        printf("Can't read  file!!!");//จะแสดงค่าพวกนี้ออกมา
    }
}
void loadfilebin(char *bname,int bdata[],int *bcount)//ฟังก์ชันเปิดไฟล์ Binary
{
    FILE *fp;//ประกาศตัวแปรประเภทไฟล์
    int a;//ประกาศตัวแปร
    *bcount = 0;//ให้ bcount เริ่มที่ 0
    fp = fopen(bname,"rb");//เปิดไฟล์
    while(!feof(fp))//วนรอบจนกว่าจะหมดไฟล์
    {
        if(fread(&a,sizeof(int),1,fp)==1)//ถ้าหากอ่านข้อมูลของ int=1ได้
        {
            bdata[*bcount] = a;//เอา a มาเก็บไว้ในอาร์เรย์ชื่อ bdata
            *bcount = *bcount + 1;//เพิ่มค่า bcount ไปอีก 1
        }
    }
    fclose(fp);//ปิดไฟล์
}
double Solution1(int tdata[],int bdata[],int tcount,int bcount)//ฟังก์ชันหาข้อมูลซ้ำแบบที่ 1
{
    int i,j,count = 1;//ประกาศตัวแปร
    double time;//ประกาศตัวแปร
    clock_t start,stop;//ประกาศตัวแปรเพื่อจับเวลา
    start = clock();//จับค่าเวลาเริ่ม
    for(i=0;i<tcount;i++)//วนรอบเท่ากับจำนวนข้อมูล
    {
        for(j=0;j<bcount;j++)//วนรอบเท่ากับจำนวนข้อมูล
        {
            if(tdata[i]==bdata[j])//หากเท่ากัน
            {
                printf("\nFound (%d) = %d",count,tdata[i]);//แสดงผลว่าเจอตัวที่เหมือนกัน
                count++;//เพื่ม count
            }
        }
    }
    stop = clock();//จับเวลาตอนสิ้นสุด
    time = (double)(stop-start)/CLOCKS_PER_SEC;//นำเวลามาลบกันแล้วเปลี่ยนเป็นหน่วยวินาที
    return time;//คืนค่า time
}
double Solution2(int tdata[],int bdata[],int tcount,int bcount)//ฟังก์ชันหาข้อมูลซ้ำแบบที่สอง
{
    int i,j,count = 1;//กำนหดตัวแปรเพื่อวนรอบ
    double time;//กำหนดตัวแปรเพื่อคำนวณเวลา
    clock_t start,stop;//กำหนดตัวแปรเพื่อจับเวลา
    start = clock();//จับค่าเวลาเริ่มต้น
    for(i=0;i<tcount;i++)//วนรอบเท่ากับจำนวนข้อมูล
    {
        if((int*)bsearch(&tdata[i],bdata,bcount,sizeof(int),cmpfunc)!= NULL)//ใช้คำสั่ง bsearch จาก array แรก หากับ array ที่สองที่เรียงมาแล้ว
        {
            printf("\nFound (%d) = %d",count,tdata[i]);//ถ้าเจอให้แสดงผลว่าเจอ
            count++;//เพิ่ม count
        }
    }
    stop = clock();//จับเวลาตอนสิ้นสุด
    time = (double)(stop-start)/CLOCKS_PER_SEC;//นำเวลามาลบกันแล้วเปลี่ยนเป็นหน่วยวินาที
    return time;//คืนค่า time
}
double Solution3(int tdata[],int bdata[],int tcount,int bcount)//ฟังก์ชันหาข้อมูลซ้ำแบบที่สาม
{
    int i=0,j=0,count = 1;//กำนหดตัวแปรเพื่อวนรอบ
    double time;//กำหนดตัวแปรเพื่อคำนวณเวลา
    clock_t start,stop;//กำหนดตัวแปรเพื่อจับเวลา
    start = clock();//จับค่าเวลาเริ่มต้น
     while(i<tcount && j<bcount)//วนรอบเมื่อยังหาไม่หมดทุกตัว
    {
        if(tdata[i]<bdata[j])//ถ้าเกิดว่าข้อมูลใน array แรกยังน้อยกว่า array ที่สองอยู่
        {
            i++;//เลื่อนไปอีกตำแหน่งของ array แรก
        }
        else if(tdata[i]>bdata[j])//ถ้าเกิดว่าข้อมูลใน array ที่สองน้อยกว่าใน array แรก
        {
            j++;//เลื่อนไปอีกตำแหน่งของ array ที่สอง
        }
        else//ถ้าเกิดข้อมูลทั้งสองเท่ากัน
        {
            printf("\nFound (%d) = %d",count,tdata[i]);//แสดงผลว่าเจอ
            count++;//เพิ่มจำนวน count
            i++;//เลื่อนไปอีกตำแหน่งของ array แรก
            j++;//เลื่อนไปอีกตำแหน่งของ array ที่สอง
        }
    }
    stop = clock();//จับเวลาตอนสิ้นสุด
    time = (double)(stop-start)/CLOCKS_PER_SEC;//นำเวลามาลบกันแล้วเปลี่ยนเป็นหน่วยวินาที
    return time;//คืนค่า time
}
int main()
{
    double time1,time2,time3;//กำหนดตัวแปรสำหรับรับค่าเวลา
    int tdata[100010],bdata[100010],tcount,bcount;//กำหนดตัวแปรสำหรับเป็น parameter

    loadfiletext("txt100000.txt",tdata,&tcount);//เปิดไฟล์ text
    loadfilebin("bin100000.bin",bdata,&bcount);//เปิดไฟล์ binary
    printf("\nread \"txt100000.txt\" complete(%d units)",tcount);//แสดงผลว่ามีทั้งหมดกี่ตัว
    printf("\nread \"bin100000.bin\" complete(%d units)\n\n",bcount);//แสดงผลว่ามีทั้งหมดกี่ตัว

    printf("\nsolution 1");//แสดงผลชื่อวิธี
    time1 = Solution1(tdata,bdata,tcount,bcount);//เรียกใช้ฟังก์ชันหาตัวซ้ำด้วยวิธีแรกและเอาตัวแปรมารับค่าเวลา
    printf("\n use %g s\n\n",time1);//แสดงผลว่าใช้เวลาไปเท่าไหร่

    printf("\nsolution 2 ");//แสดงผลชื่อวิธี
    qsort(bdata,bcount,sizeof(int),cmpfunc);//เรียงข้อมูลจากน้อยไปมากใน array ที่สอง
    time2 = Solution2(tdata,bdata,tcount,bcount);//เรียกใช้ฟังก์ชันหาตัวซ้ำด้วยวิธีที่สองและเอาตัวแปรมารับค่าเวลา
    printf("\n use %g s\n\n",time2);//แสดงผลว่าใช้เวลาไปเท่าไหร่

    printf("\nsolution 3 ");//แสดงผลชื่อวิธี
    qsort(tdata,tcount,sizeof(int),cmpfunc);//เรียงข้อมูลจากน้อยไปมากใน array แรก
    time3 = Solution3(tdata,bdata,tcount,bcount);//เรียกใช้ฟังก์ชันหาตัวซ้ำด้วยวิธีที่สามและเอาตัวแปรมารับค่าเวลา
    printf("\n use %g s\n\n",time3);//แสดงผลว่าใช้เวลาไปเท่าไหร่
    return 0;
}
