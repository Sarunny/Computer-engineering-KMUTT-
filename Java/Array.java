import java.io.FileNotFoundException;
import java.util.Scanner;
import java.io.File;


public class Array {
    CSVnode [] data; // CSVnode มีอาเรย์ชื่อ data
    int count;//เป็นcountของnode ค่าที่มีdata
public Array(int max)//เอาไว้ดูว่าเราจองarrayกี่ตัว
    {
        data = new CSVnode[max];
        count = 0;//nodeที่ยังไม่ได้ใส่ data
    }
public void addData(int a,long b,String c,String d)
    {
        CSVnode x = new CSVnode(a,b,c,d);//nodeที่ใส่a b c dเข้าไปแล้ว
        data[count++] = x;
    }

public void swap (int i, int j)//สลับกัน
    {
        CSVnode x = new CSVnode();
        x = data[i];
        data[i] = data[j];
        data[j] = x;
    }
public void scansort(int start,int stop)
    {
    int i,j;
    for (i=start;i<stop;i++)
        for (j=i+1;j<=stop;j++)
            if(data[j].num<data[i].num)
            swap(i,j);
    }
public void scansort2(int start,int stop)
    {
    int i,j;
    for (i=start;i<stop;i++)
        for (j=i+1;j<=stop;j++)
            if(data[j].num>data[i].num)
            swap(i,j);
    }
public void selectionsort(int start, int stop) {
    int i, j, min;
    for (i = start; i < stop; i++) //
        {
            min = i;
            for (j = i + 1; j <= stop; j++) 
            {
                if (data[j].num < data[min].num) 
                {
                    min = j;
                }
            }
            swap(i, min);
        }
    }
public void selectionsort2(int start, int stop) {
    int i, j, min;
    for (i = start; i < stop; i++) 
        {
            min = i;
            for (j = i + 1; j <= stop; j++) 
            {
                if (data[j].num > data[min].num) 
                {
                        min = j;
                }
            }
            swap(min, i);
            }
        }
public void insertionSort(int start,int stop){
    int i,j;
    CSVnode x = new CSVnode();
        for(i=start+1;i<=stop;i++){
            x = data[i];
            for(j=i;((j>start)&&(x.num < data[j-1].num));j--)
                data[j] = data[j-1];
                data[j] = x;
            }
        }
public void insertionSort2(int start,int stop){
    int i,j;
    CSVnode x = new CSVnode();
        for(i=start+1;i<=stop;i++)
        {
            x = data[i];
            for(j=i;((j>start)&&(x.num > data[j-1].num));j--)
                data[j] = data[j-1];
                data[j] = x;
        }
    }
public void bubble(int start,int stop)
{
    int i,j;
    for(i=start;i<=stop-1;i++)
        for(j=stop;j>i;j--)
            if(data[j].num<data[j-1].num)
                swap(j,(j-1));
        }
public void bubble2(int start,int stop)
{
    int i,j;
    for(i=start;i<=stop-1;i++)
        for(j=stop;j>i;j--)
            if(data[j].num>data[j-1].num)
                swap(j,(j-1));
}

public boolean TestSorted(int start,int stop){ // function สร้างไว้เพื่อ test ว่าโปรแกรมอ่านไฟล์ถูกหรือไม่
    int i;
    for (i=0;i<count-1;i++){

        if(data[i].num >data[i+1].num)
            return false;
    }
    return true;
}
public void printtest(){
    System.out.printf("|       data[0]      |      %9d|    %9d| %s | %s |\n",data[0].id,data[0].num,data[0].str1,data[0].str2);
    System.out.printf("|     data[49999]    |      %9d|    %9d| %s | %s |\n",data[49999].id,data[49999].num,data[49999].str1,data[49999].str2);
    System.out.printf("|     data[99999]    |      %9d|    %9d| %s | %s |\n",data[99999].id,data[99999].num,data[99999].str1,data[99999].str2);
    System.out.printf("|____________________|_______________|________________|______________________________________________________|______________________________________________________|");
    
}

public int Downlodefiledata(String filename){

    int count = 0;//เอาไว้รีเทิร์นเพื่อให้รู้ว่ามันอ่านได้หรืออ่านไม่ได้
    try
    {
        File fr = new File(filename);
        Scanner sc = new Scanner(fr);
        int a;
        long b;
        String c,d;
        sc.useDelimiter(",|\n|\r\n");//เป็นตัวขั้นข้อมูล
        while (sc.hasNextInt())//ดูว่ามันมีอยู่ในนั้นไหม ถ้ามันมีก็อ่าน4ตัวนั้นต่อ
        {
            a = sc.nextInt();
            b = sc.nextLong();
            c = sc.next();
            d = sc.next();
            addData(a,b,c,d);//เรียกaddDataมาใช้
            count++;
        }
        sc.close();
        return count;
    }

    catch(FileNotFoundException error) {
        System.out.println("Error cant open"+filename);
        return 0;
    }
    }
public void mergesort(int first,int last)
{
    int mid;
    if(first < last)
    {
        mid = (first+last)/2;
        mergesort(first,mid);
        mergesort(mid+1,last);
        mergesdata(first,mid,last);
    }
}
public void mergesdata(int first,int mid,int last)
{
    CSVnode [] temp = new CSVnode[last-first+1];
    int i,i1,i2;
    i1 = first;
    i2 = mid +1;
    for(i=0 ; i<=last-first ;i++ )
        { if(i1<=mid&&i2<=last)
            { if(data[i1].num<data[i2].num)
                        temp[i] = data[i1++];
                    else 
                        temp[i] = data[i2++];}
                    else if (i1>mid)
                        temp[i] = data[i2++];
                    else if (i2>last)
                        temp[i] = data[i1++];
        }
        for(i=0;i<=last-first;i++)
        data[first+i]=temp[i];
    }
public void quicksort(int first,int last)
{
    int i=first, j=last;
    if(first<last)
    {do
        { while ((data[i].num <= data[j].num)&&(i<j)){j--;}
            if(data[i].num>data[j].num){ swap(i,j); i++;}
        while((data[i].num<=data[j].num)&&(i<j)){i++; }
            if(data[i].num>data[j].num){ swap(i,j); j--;}
        }while(i<j);
        if(first<j-1)
            quicksort(first,j-1);
        if(i+1<last)
            quicksort(i+1,last);  
    }
}
public void middleguicksort(int first,int last)
{
    int i=first,j=last;
    long pivot;
    if(first<last)
    {
        pivot = data[(first+last)/2].num;
        while (i<j)
        {while(data[i].num<pivot)
            i++;
            while(data[j].num>pivot)
            j--;
            if(i<=j)
            {
                swap(i,j);
                i++;
                j--;
            }
        }
        if (first<j)
        middleguicksort(first,j);
        if(i<last)
        middleguicksort(i,last);
    }
}
public void mergesortstr(int first,int last)
{
    int mid;
    if(first < last)
    {
        mid = (first+last)/2;
        mergesortstr(first,mid);
        mergesortstr(mid+1,last);
        mergesdatastr(first,mid,last);
    }
}
public void mergesdatastr(int first,int mid,int last)
{
    CSVnode [] temp = new CSVnode[last-first+1];
    int i,i1,i2;
    i1 = first;
    i2 = mid +1;
    for(i=0 ; i<=last-first ;i++ )
        { if(i1<=mid&&i2<=last)
            { if(data[i1].str2.compareToIgnoreCase(data[i2].str2)<0)
                        temp[i] = data[i1++];
                    else 
                        temp[i] = data[i2++];}
                    else if (i1>mid)
                        temp[i] = data[i2++];
                    else if (i2>last)
                        temp[i] = data[i1++];
        }
        for(i=0;i<=last-first;i++)
        data[first+i]=temp[i];
    }
public void quicksortstr(int first,int last)
{
    int i=first, j=last;
    if(first<last)
    {do
        { 
        while ((data[i].str2.compareToIgnoreCase(data[j].str2) <=0)&&(i<j)){j--; }
            if(data[i].str2.compareToIgnoreCase(data[j].str2)>0){swap(i,j);i++;}
        while((data[i].str2.compareToIgnoreCase(data[j].str2)<=0)&&(i<j)){ i++;} 
            if(data[i].str2.compareToIgnoreCase(data[j].str2)>0){ swap(i,j); j--;}
        }while(i<j);
        if(first<j-1)
            quicksortstr(first,j-1);
        if(i+1<last)
            quicksortstr(i+1,last);  
    }
}
public void middleguicksortstr(int first,int last)
{
    int i=first,j=last;
    String pivot;
    if(first<last)
    {
        pivot = data[(first+last)/2].str2;
        while (i<j)
        {
            while(data[i].str2.compareToIgnoreCase(pivot)<0)
            i++;
            while(data[j].str2.compareToIgnoreCase(pivot)>0)
            j--;
            if(i<=j)
            {
                swap(i,j);
                i++;
                j--;
            }
        }
        if (first<j)
        middleguicksortstr(first,j);
        if(i<last)
        middleguicksortstr(i,last);
    }
}
}
