#include<stdio.h>
#include<stdlib.h>
#include<search.h>
#include<math.h>
#include<string.h>
int acount,bpcount,bcount,cpcount,ccount,dpcount,dcount,fcount;//กำหนดตัวแปร
double min,max,mean,sd,minmid,maxmid,meanmid,sdmid,minfi,maxfi,meanfi,sdfi,minatt,maxatt,meanatt,sdatt;//กำหนดตัวแปร

struct grade_info //ประกาศเป็นโครงสร้างข้อมูลประเภท struct
{
    long long id; //ประกาศตัวแปร
    char name[40];//ประกาศตัวแปร
    double mid,fi,att,total,gpoint;//ประกาศตัวแปร
    char grade[3];//ประกาศตัวแปร
};
typedef struct grade_info gradetype;//เป็นคำสั่งที่บอกว่า grade_info ก็คือ gradetype

void Load_Student_File (char *name,gradetype st[],int *stcount) //ฟังก์ชั่นเอาไว้ใช้โหลดไฟล์
{
    FILE *fp; //ประกาศตัวแปรเพื่อใชเป็นไฟล์
    gradetype x; // ประกาศตัวแปรเพื่ออ่านข้อมูล 1 ตัว
    char fname[15],lname[30];//ประกาศตัวแปร
    if ((fp = fopen("SCORE.CSV", "r")) != NULL ) // ตรวจสอบการเปิดไฟล์
    {
        *stcount=0; //กำหนดค่าเริ่มตัวนับจำนวนข้อมูล
        while(fscanf(fp,"%llu,%[^,],%lf,%lf,%lf",&x.id,x.name,&x.mid,&x.fi,&x.att)==5)//วนลูปเพื่อรับค่า
    {
        x.total = x.mid+x.fi+x.att; // คำนวณคะแนนรวม
        st[*stcount] = x; // นำข้อมูล x ที่อ่านได้ไปเก็บใน st
        *stcount = *stcount+1; } // นับเพิ่มจำนวนข้อมุลที่อ่านได้
        fclose(fp); // ปิดไฟล์
        printf("\nTotal read %d records. ",*stcount);//ปริ้นค่า stcount ออกมา
    }
    else
    printf("\nError Can't Read File DATA.CSV\n");//ถ้าตรวจสอบการเปิดไฟล์ไม่ได้จะปริ้นคำว่าError Can't Read File DATA.CSV
}

void print_data(gradetype x)//ฟังก์ชั่นเอาไว้แสดงข้อมูล 1 คน
{
    printf("%llu %-40s %5.1lf %5.1lf %5.1lf %5.1lf %5.1lf %s\n", x.id, x.name,x.mid, x.fi, x.att,x.total, x.gpoint, x.grade);//แสดงค่า id,nae,mid,final,total,gpoint,grade ออกมา
}

void Show_All_Data (gradetype st[], int stcount)//ฟังก์ชั่นเอาไว้แสดงข้อมูลทั้งหมด
{
    int i;//ประกาศตัวแปร
    for (i = 0; i<stcount; i++)//วนลูปจนกว่าจะครบถึงตัวสุดท้าย
{
    printf("%3d)",i+1);
    print_data(st[i]);//เรียกใช้ฟังก์ชั่นpriny_data
}
}

void Sort_by_id (gradetype st[], int stcount) //ฟังก์ชั่นเอาไว้เรียงลำดับตามรหัสประจำตัวจากน้อยไปมาก
{
    int i, j ;//กำหนดตัวแปร
    gradetype x;//กำหนดตัวแปร
    for (i = 0; i < stcount-1; i++) //วนรอบจนถึงตัวก่อนสุดท้าย
    for (j = i+1; j < stcount; j++) //วนรอบjโดยที่jมากกว่าi 1 ตำแหน่ง
    if (st[j].id < st[i].id) //ถ้าตำแหน่งถัดไปน้อยกว่าตำแหน่งก่อนหน้า
    {
        x = st[i]; //ค่าตัวแรกเท่ากับX
        st[i] = st[j];//ค่าตัวแรกเท่ากับค่าตัวหลัง
        st[j] = x;//ค่าตัวหลังเท่ากับX(ค่าตัวแรก)
    }
}

void Sort_by_total ( gradetype st[], int stcount) // ฟังก์ชั่นเอาไว้เรียงลำดับตามคะแนนจากมากไปน้อย
{
    int i, j ;//ประกาศตัวแปร
    gradetype x;//ประกาศตัวแปรประเภท gradetype
        for (i = 0; i < stcount-1; i++) //วนรอบจนถึงตัวก่อนสุดท้าย
        for (j = i+1; j < stcount; j++) //วนรอบjโดยที่jมากกว่าi 1 ตำแหน่ง
        if (st[j].total > st[i].total) //เรียงจากมากไปน้อย
    {
        x = st[i]; //แลกเปลี่ยน data
        st[i] = st[j];//ค่าตัวแรกเท่ากับค่าตัวหลัง

        st[j] = x;//ค่าตัวหลังเท่ากับX(ค่าตัวแรก)
    }
}

void Search_Score (gradetype st[], int stcount)// ฟังก์ชั่นเอาไว้ค้นหาจากคะแนนที่ได้ระหว่างน้อยไปมาก
{
    double min, max; // ประกาศตัวแปร
    int i , count;// ประกาศตัวแปร
    char ch ;// ประกาศตัวแปร
    do
    {
        printf("\n Enter Range of min score and max score "); //แสดงค่าพวกนี้ออกมา
        scanf("%lf %lf", &min , &max);// อ่านค่า min max
        count = 0;
    printf("\n========================================================================================\n");//แสดงค่าพวกนี้ออกมา
    printf("     ID     ||                  NAME                  ||MID||FINAL||ATTEN||TOTAL||GRADE||\n");//แสดงค่าพวกนี้ออกมา
    printf("=========================================================================================\n");//แสดงค่าพวกนี้ออกมา
        for (i = 0; i<stcount; i++) //วนรอบเท่ากับจำนวนนศ.
        {
            if (st[i].total >= min && st[i].total <= max)//กรองข้อมูลที่อยู่ในช่วง min - max
            {
                count = count + 1;//นับจำนวน
                printf("%2d)",count);//แสดงผลนักศึกษาคนที่
                print_data(st[i]);//แสดงข้อมูลนักศึกษา
            }
        }
    printf("========================================================================================\n");//แสดงค่าพวกนี้ออกมา
    }
    while (ch == 'y');//วนรอบจนกว่าจะถูกป้อนค่า y
}

void Search_Grade (gradetype st[], int stcount) //ฟังก์ชั่นเอาไว้ค้นหาจากเกรด
{
    char key[3];//ประกาศตัวแปร
    int i , count ; //ประกาศตัวแปร
    do
    {
        printf("\n Search Grade (A, B+, B, ... F or 0 = Exit) ");//แสดงค่าพวกนี้ออกมา
        scanf("%2s", key); // อ่านสตริงไม่เกิน 2 ตัวอักษร
        count = 0;//setค่า countให้=0
    if (strcmp(key,"0") != 0)//ถ้า key ไม่เท่ากับ 0
    {
    printf("\n=======================================================================================\n");//แสดงค่าพวกนี้ออกมา
    printf("     ID     ||                  NAME                  ||MID||FINAL||ATTEN||TOTAL||GRADE||\n");//แสดงค่าพวกนี้ออกมา
    printf("=========================================================================================\n");//แสดงค่าพวกนี้ออกมา
    }
    for (i = 0; i<stcount; i++)//วนรอบเท่ากับจำนวนนักศึกษา
    {
        if (strcmp(st[i].grade,key)==0)//ถ้าgrade=keyที่รับมา
        {
            count = count + 1;//นับจำนวน
            printf("%2d)",count);//แสดงผลนักศึกษาคนที่
            print_data(st[i]);//แสดงข้อมูลนักศึกษา
        }
    }
    printf("========================================================================================\n");//แสดงค่าพวกนี้ออกมา
    }while (strcmp(key, "0") !=0);//วนรอบจนกว่า key จะเป็น 0
}

void Search_Name (gradetype st[], int stcount) //ฟังก์ชัั่นที่ค้นหาคนจากชื่อ
{
    char key[16];//ประกาศตัวแปร
    int i, count;//ประกาศตัวแปร
    do
    {
        printf("\n Enter Search key (0 = Exit) ");//แสดงค่าพวกนี้ออกมา
        scanf("%15s", key); // อ่านสตริงไม่เกิน 15 ตัวอักษร
        count = 0;//ตั้งให้ค่าcount = 0
    if (strcmp(key,"0") != 0)//ถ้า keyไม่เท่ากับ 0
    {
    printf("\n=======================================================================================\n");//แสดงค่าพวกนี้ออกมา
    printf("     ID     ||                  NAME                  ||MID||FINAL||ATTEN||TOTAL||GRADE||\n");//แสดงค่าพวกนี้ออกมา
    printf("=========================================================================================\n");//แสดงค่าพวกนี้ออกมา

    }
    for (i = 0; i<stcount; i++)//วนรอบเท่ากับจำนวนนักศึกษา
    if (strstr(st[i].name, key) != NULL) //ถา้คน้ บางสว่ นเจอ
        {
            count = count + 1;//นับจำนวน
            printf("%2d)",count);//แสดงผลนักศึกษาคนที่
            print_data(st[i]);//แสดงข้อมูลนักศึกษา
        }
    } while (strcmp(key,"0")!=0);//วนรอบจนกว่า key จะเป็น 0
}

void grade_setting(gradetype st[], int stcount, double *a, double *bp,double *b, double *cp, double *c, double *dp, double *d,double A,double Bp,double B,double Cp,double C,double Dp,double D) //ฟังก์ชั่นที่เอาไว้คำนวณเกรด
{
    int i ;//ประกาศตัวแปร
    acount=bpcount=bcount=cpcount=ccount=dpcount=dcount=fcount=0;//เซ็ตค่าจำนวนเกรดทั้งหมด เท่ากับ0
    for (i=0; i<stcount; i++)//วนรอบเท่ากับจำนวนนักศึกษา
    if (st[i].total >=A)//ถ้าคะแนนรวมมากกว่าหรือเท่ากับค่าของ A
    {
        strcpy(st[i].grade,"A"); st[i].gpoint=4.0;//ให้เกรดเท่ากับ A และ 4.0
        acount++;//เพิ่มค่าคนที่ได้เกรดนี้
    }
    else if (st [i].total >=Bp)//ถ้าคะแนนรวมมากกว่าหรือเท่ากับค่าของ B+
    {
        strcpy(st[i].grade,"B+"); st[i].gpoint=3.5;////ให้เกรดเท่ากับ B+ และ 3.5
        bpcount++;//เพิ่มค่าคนที่ได้เกรดนี้
    }
    else if (st[i].total >=B)//ถ้าคะแนนรวมมากกว่าหรือเท่ากับค่าของ B
    {
        strcpy(st[i].grade,"B"); st[i].gpoint=3.0;//ให้เกรดเท่ากับ B และ 3.0
        bcount++;//เพิ่มค่าคนที่ได้เกรดนี้
    }
    else if (st[i].total >=Cp)//ถ้าคะแนนรวมมากกว่าหรือเท่ากับค่าของ C+
    {
        strcpy(st[i].grade,"C+"); st[i].gpoint=2.5;//ให้เกรดเท่ากับ C+ และ 2.5
        cpcount++;//เพิ่มค่าคนที่ได้เกรดนี้
    }
    else if (st[i].total >=C)//ถ้าคะแนนรวมมากกว่าหรือเท่ากับค่าของ C
    {
        strcpy(st[i].grade,"C"); st[i].gpoint=2.0;//ให้เกรดเท่ากับ C และ 2.0
        ccount++;//เพิ่มค่าคนที่ได้เกรดนี้
    }
    else if (st[i].total >=Dp)//ถ้าคะแนนรวมมากกว่าหรือเท่ากับค่าของ D+
    {
        strcpy(st[i].grade,"D+"); st[i].gpoint=1.5;//ให้เกรดเท่ากับ D+ และ 1.5
        dpcount++;//เพิ่มค่าคนที่ได้เกรดนี้
    }
    else if (st[i].total >=D)//ถ้าคะแนนรวมมากกว่าหรือเท่ากับค่าของ D
    {
        strcpy(st[i].grade,"D"); st[i].gpoint=1.0;//ให้เกรดเท่ากับ D และ 1.0
        dcount++;//เพิ่มค่าคนที่ได้เกรดนี้
    }
    else
    {
        strcpy(st[i].grade,"F") ; st[i].gpoint=0;//ให้เกรดเท่ากับ F และ 0
        fcount++;//เพิ่มค่าคนที่ได้เกรดนี้
    }
}

void find_stat ( gradetype st[], int stcount,
                      double *min, double *max,double *mean, double *sd,
                      double *minmid,double *maxmid,double *meanmid,double *sdmid,
                      double *minfi,double *maxfi,double *meanfi,double *sdfi,
                      double *minatt,double *maxatt,double *meanatt,double *sdatt) //เป็นฟังก์ชั่นที่ใช้คำนวณหาค่าทางสถิติ
{
    int i; //ประกาศตัวแปร
    double sum=0,sumsqr=0,summid=0,sumsqrmid=0,sumfi=0,sumsqrfi=0,sumatt=0,sumsqratt=0;//ประกาศตัวแปร
    *min = *max = st[0].total;//กำหนดค่าเริ่มต้นของmin,maxของคะแนนรวมให้เท่ากับ 0
    *minmid = *maxmid = st[0].mid;//กำหนดค่าเริ่มต้นของmin,maxของคะแนน midterm ให้เท่ากับ 0
    *minfi = *maxfi = st[0].fi;//กำหนดค่าเริ่มต้นของmin,maxของคะแนน final ให้เท่ากับ 0
    *minatt = *maxatt = st[0].att;//กำหนดค่าเริ่มต้นของmin,maxของคะแนนเก็บให้เท่ากับ 0
    for (i=0; i<stcount; i++)//วนลูปจนกว่าจะถึงข้อมูลตัวสุดท้าย
    {
        if (st[i].total < *min)//ถ้าคะแนนรวมน้อยกว่าค่าที่น้อยที่สุด
        {
            *min = st[i].total;//คำนวณหาค่าที่ต่ำที่สุดของคะแนนรวม
        }
        if (st[i].total > *max)//ถ้าคะแนนรวมมากกว่าค่าที่มากที่สุด
        {
            *max = st[i].total;//คำนวณหาค่าที่สูงที่สุดของคะแนนรวม
        }
        if (st[i].mid < *minmid)//ถ้าคะแนนกลางภาคน้อยกว่าค่าที่น้อยที่สุด
        {
            *minmid = st[i].mid;//คำนวณหาค่าที่ต่ำที่สุดของคะแนน midterm
        }
        if (st[i].mid > *maxmid)//ถ้าคะแนนกลางภาคมากกว่าค่าที่มากที่สุด
        {
            *maxmid = st[i].mid;//คำนวณหาค่าที่สูงที่สุดของคะแนน midterm
        }
        if (st[i].fi < *minfi)//ถ้าคะแนนปลายภาคน้อยกว่าค่าที่น้อยที่สุด
        {
            *minfi = st[i].fi;//คำนวณหาค่าที่ต่ำที่สุดของคะแนน final
        }
        if (st[i].fi > *maxfi)//ถ้าคะแนนปลายภาคมากกว่าค่าที่มากที่สุด
        {
            *maxfi = st[i].fi;//คำนวณหาค่าที่สูงที่สุดของคะแนน final
        }
        if (st[i].att < *minatt)//ถ้าคะแนนงานน้อยกว่าค่าที่น้อยที่สุด
        {
            *minatt = st[i].att;//คำนวณหาค่าที่ต่ำที่สุดของคะแนน atten
        }
        if (st[i].att > *maxatt)//ถ้าคะแนนงานมากกว่าค่าที่มากที่สุด
        {
            *maxatt = st[i].att;//คำนวณหาค่าที่สูงที่สุดของคะแนน atten
        }
        sum = sum+st[i].total; //คำนวณหาค่า sum
        sumsqr = sumsqr + pow(st[i].total,2);//คำนวณหาค่า sumsqr
        summid = summid +st[i].mid;//คำนวณหาค่า summid
        sumsqrmid = sumsqrmid + pow(st[i].mid,2);//คำนวณหาค่า sumsqrmid
        sumfi = sumfi+st[i].fi;//คำนวณหาค่า sumfi
        sumsqrfi = sumsqrfi + pow(st[i].fi,2);//คำนวณหาค่า sumsqrfi
        sumatt = sumatt+st[i].att;//คำนวณหาค่า sumatt
        sumsqratt = sumsqratt + pow(st[i].att,2);//คำนวณหาค่า sumsqratt
    }
    *mean = sum/stcount;//คำนวณหา mean ของคะแนนรวม
    *meanmid = summid/stcount;//คำนวณหา meanmid  ของคะแนนmidterm
    *sdmid = sqrt(sumsqrmid/stcount - pow(*meanmid,2));//คำนวณหา sdmid ของคะแนนmidterm
    *sd = sqrt(sumsqr/stcount - pow(*mean,2));//คำนวณหา sd ของคะแนนรวม
    *meanfi = sumfi/stcount;//คำนวณหา mean ของคะแนน final
    *sdfi = sqrt(sumsqrfi/stcount - pow(*meanfi,2));//คำนวณหาsdของคะแนนfinal
    *meanatt = sumatt/stcount;//คำนวณหา mean ของคะแนนเก็บ
    *sdatt = sqrt(sumsqratt/stcount - pow(*meanatt,2));//คำนวณหา sd ของคะแนนเก็บ
}
void show_stat(gradetype st[],int stcount)//ฟังก์ชั่นแสดงผลค่าสถิติ
{
    int i;//ประกาศตัวแปร
    double gpa=0;//ประกาศตัวแปร
    find_stat(st,stcount,&min,&max,&mean,&sd,&minmid,&maxmid,&meanmid,&sdmid,&minfi,&maxfi,&meanfi,&sdfi,&minatt,&maxatt,&meanatt,&sdatt);//เรียกใช้ฟังก์ชั่นคำนวณค่าสถิติ
    for(i=0; i<stcount; i++)//วนลูปจนกว่าจะถึงข้อมูลตัวสุดท้าย
    {
        gpa = gpa + st[i].gpoint;//คำนวณ GPA
    }
    gpa = gpa/stcount;//คำนวณ GPA
    printf("\n****************************************************************\n");//แสดงค่าพวกนี้ออกมา
    printf("*   Score   *    mid    *    final   *    atten   *    total   *\n");//แสดงค่าพวกนี้ออกมา
    printf("****************************************************************\n");//แสดงค่าพวกนี้ออกมา
    printf("*   min     *   %6.2lf  *   %6.2lf   *   %6.2lf   *   %6.2lf   *\n", minmid,minfi,minatt,min);//แสดงค่าน้อยสุดของแต่ละคะแนน
    printf("*   max     *   %6.2lf  *   %6.2lf   *   %6.2lf   *   %6.2lf   *\n", maxmid,maxfi,maxatt,max);//แสดงค่านมากสุดของแต่ละคะแนน
    printf("*   mean    *   %6.2lf  *   %6.2lf   *   %6.2lf   *   %6.2lf   *\n", meanmid,meanfi,meanatt,mean);//แสดงค่าเฉลี่ยของแต่ละคะแนน
    printf("*   sd      *   %6.2lf  *   %6.2lf   *   %6.2lf   *   %6.2lf   *\n", sdmid,sdfi,sdatt,sd);//แสดงค่าSDของแต่ละคะแนน
    printf("****************************************************************\n");//แสดงค่าพวกนี้ออกมา
    printf("\n");
    printf("*************************************************************\n");//แสดงค่าพวกนี้ออกมา
    printf("*   score   *   A *  B+ *   B *  C+ *   C *  D+ *  D  *  F  *\n");//แสดงค่าพวกนี้ออกมา
    printf("*   count   *  %2d *  %2d *  %2d *  %2d *  %2d *  %2d *  %1d  *  %2d *\n", acount, bpcount, bcount, cpcount, ccount, dpcount, dcount, fcount);//แสดงผลตัวเลขจำนวนคนที่ได้กรดแต่ละเกรด
    printf("*************************************************************\n");//แสดงค่าพวกนี้ออกมา
    printf("\nGPA : %.2lf\n", gpa);//แสดงผล GPA
}

int get_int(int min,int max)//ฟังก์ชั่นเอาไว้ดักค่าสูงสุดต่ำสุด
{
	int ans;//กำหนดตัวแปร
	char ch;//กำหนดตัวแปร
	while((scanf("%d%c",&ans,&ch)!=1&&ch!='\n')||ans<min||ans>max)//เช็คจำนวนตัวแปรและดูว่าอยู่ในของเขตที่กำหนดmin max ไว้มั้ย
	{
	rewind(stdin);
	printf("error please input again!!.");//แสดงerror please input again!!. ออกมา
	}
	return ans;//ส่งค่าansไปใช้
}

int get_menu()//เป็นฟังก์ชั่นเรียกใช้เมนู
{
	int select;//กำหนดตัวแปร
	printf("##################################################\n");//output พวกนี้ออกมา
	printf("#                 Manu of Calculate              #\n");//output พวกนี้ออกมา
	printf("##################################################\n");//output พวกนี้ออกมา
	printf("#              1. Read file                      #\n");//output พวกนี้ออกมา
	printf("#              2. Calculate grade                #\n");//output พวกนี้ออกมา
	printf("#              3. Calculate stat                 #\n");//output พวกนี้ออกมา
	printf("#              4. Show all student               #\n");//output พวกนี้ออกมา
	printf("#              5. Show student by score          #\n");//output พวกนี้ออกมา
    printf("#              6. Show student by ID             #\n");//output พวกนี้ออกมา
    printf("#              7. Show student by min,max        #\n");//output พวกนี้ออกมา
    printf("#              8. Show student by grade          #\n");//output พวกนี้ออกมา
    printf("#              9. Show student by name           #\n");//output พวกนี้ออกมา
    printf("#              0. EXIT                           #\n");//output พวกนี้ออกมา
	printf("##################################################\n");//output พวกนี้ออกมา
	printf("Input your number >o< :");//output พวกนี้ออกมา
	select = get_int(0,9);//กำหนดตัวแปรให้เรียกใช้ฟังก์ชั่น get_int โดยใส่เลขได้แค่ 0-9
	return select;//ส่งค่า select ไปใช้
}

int main()//ฟังก์ชั่นหลัก
{
    gradetype st[100];//กำหนดตัวแปร
    int stcount;//กำหนดตัวแปร
    int select,count=0;//กำหนดตัวแปร
    double a,bp,b,cp,c,dp,d;//กำหนดตัวแปร
    char file_name[100];//กำหนดตัวแปร
    double A,Bp,B,Cp,C,Dp,D;//กำหนดตัวแปร
    double sum_gpa;//กำหนดตัวแปร
    double min,max,mean,sd,minmid,maxmid,meanmid,sdmid,minfi,maxfi,meanfi,sdfi,minatt,maxatt,meanatt,sdatt;//กำหนดตัวแปร
    do
    {
        select = get_menu();//กำหนดให้ sel ไว้เรียกใช้ฟังก์ชัน menu
        if(select==1)//ถ้าselect=1จะเข้าเงื่อนไขนี้
        {
            system("cls");//คำสั่ง clear screen
            Load_Student_File ("SCORE.CSV",st,&stcount);//เรียกใช้ฟังก์ชั่นเปิดไฟล์
            if(stcount==0)//ถ้าเกิดจำนวนนักเรียนเท่ากับ 0
            {
                printf("cant reading file T_T \n");//จะแสดงค่าพวกนี้ออกมา
            }
            else//ถ้าไม่ใช่
            {
                printf("reading COMPLETE!!! \n");//จะแสดงค่าพวกนี้ออกมา
                printf("total : %d \n",stcount);//บอกจำนวนนศ
                count=1;//ตรวจสอบว่าอ่านไฟล์ยัง

            }
        }
        else if(select==2&&count>0)//ถ้า select=2 จะเข้าเงื่อนไขนี้
        {
            system("cls");//คำสั่ง clear screen
            printf("Input grade : ");//จะแสดงค่าพวกนี้ออกมา
            scanf("%lf,%lf,%lf,%lf,%lf,%lf,%lf",&A,&Bp,&B,&Cp,&C,&Dp,&D);//รับค่าเกรด
            grade_setting(st,stcount,&a,&bp,&b,&cp,&c,&dp,&d,A,Bp,B,Cp,C,Dp,D);//เรียกใช้ฟังก์ชั่นgrade_setting
            show_stat(st,stcount);//เรียกใช้ฟังก์ชั่นแสดงค่าสถิติ
        }
        else if(select==3&&count>0)//ถ้าselect=3 จะเข้าเงื่อนไขนี้
        {
            system("cls");//คำสั่ง clear screen
            show_stat(st,stcount);//เรียกใช้ฟังก์ชั่นแสดงค่าสถิติ
        }
        else if(select==4&&count>0)//ถ้าselect=4 จะเข้าเงื่อนไขนี้
        {
            system("cls");//คำสั่ง clear screen
            Show_All_Data(st,stcount);//เรียกใช้ฟังก์ชั่นแสดงข้อมูลนักศึกษา
        }
        else if(select==5&&count>0)//ถ้าselect=5 จะเข้าเงื่อนไขนี้
        {
            system("cls");//คำสั่ง clear screen
            Sort_by_total(st,stcount);//เรียกใช้ฟังก์ชั่น Sort_by_total
            Show_All_Data(st,stcount);//เรียกใช้ฟังก์ชั่นแสดงข้อมูลนักศึกษา
        }
        else if(select==6&&count>0)//ถ้าselect=6 จะเข้าเงื่อนไขนี้
        {
            system("cls");//คำสั่ง clear screen
            Sort_by_id(st,stcount);//เรียกใช้ฟังก์ชั่น Sort_by_id
            Show_All_Data(st,stcount);//เรียกใช้ฟังก์ชั่นแสดงข้อมูลนักศึกษา
        }
        else if(select==7&&count>0)//ถ้าselect=7 จะเข้าเงื่อนไขนี้
        {
            system("cls");//คำสั่ง clear screen
            Search_Score(st,stcount);//เรียกใช้ฟังก์ชั่น Search_Score
        }
        else if(select==8&&count>0)//ถ้าselect=8 จะเข้าเงื่อนไขนี้
        {
            system("cls");//คำสั่ง clear screen
            Search_Grade(st,stcount);//เรียกใช้ฟังก์ชั่น Search_Grade
        }
        else if(select==9&&count>0)//ถ้าselect=9 จะเข้าเงื่อนไขนี้
        {
            system("cls");//คำสั่ง clear screen
            Search_Name(st,stcount);//เรียกใช้ฟังก์ชั่น Search_Name
        }
    }
    while(select!=0);//จะทำต่อเมื่อ sel=0
    printf("**  End Program  **\n");//แสดงค่านี้ออกมา
    return 0;//จบการทำงานของโปรแกรม
}
