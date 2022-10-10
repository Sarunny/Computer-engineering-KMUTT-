import java.io.*;
import java.text.CollationKey;
import java.util.Collection;
import java.util.Collections;
import java.util.Scanner;
import java.util.ArrayList;
import javax.imageio.stream.ImageInputStreamImpl;
import javax.lang.model.util.ElementScanner14;

        public class Dictarraylist {
        static ArrayList<Dnode> dict = new ArrayList<Dnode>(); //สร้างตัวแปลเอาไว้เก็บข้อมูลที่เป็น array มันจะเกิดขึ้นมาพร้อมกับการสร้าง class
        public static int readfile(){
            String str = null;
            int count = 0;
            try{
                InputStream fcsv = new FileInputStream("D:\\CPE111term2java\\utf8lexitron.csv"); //InputStreamมันจะทำหน้าที่อ่านหรือแปลงไฟล์ของเราให้เป็น byte รับเข้ามาใน stream ของเรา
                InputStreamReader utf = new InputStreamReader(fcsv,"UTF8"); //อ่านข้อมูลจากไฟล์แล้วเปลี่ยนให้เป็นรูปแบบ byte 
                BufferedReader fbuff = new BufferedReader(utf);//อ่านข้อความหรือตัวอักษรของข้อมูลที่ input เข้ามา
                System.out.printf("BOM = %X\n",fbuff.read());// อ่านข้อมูล BOM ทิ้งไป แล้วค่อยเริ่มอ่านข้อมูลจริง
                while((str = fbuff.readLine()) !=null) { //วนรอบอ่านข้อมูลเพื่อดูว่ามันอ่านได้หรือไม่
                    Dnode x = new Dnode(str); // สร้าง node จากข้อมูลที่อ่านได้
                    dict.add(x); // เอาข้อมูลที่อ่านได้ (x) ไปใส่ไว้ใน Array ที่ชื่อ dict
                    count++; //นับจำนวนบรรทัดที่อ่านได้
                }
                fbuff.close();//ปิดไฟล์     
            }
            //ตรวจดูerror
            catch(FileNotFoundException e){// ถ้าไม่เจอไฟล์
                System.out.println(e.getMessage());
                System.out.println("NOT FOUND!");
            }
            catch(Exception e){//ถ้าไม่รู้จักว่าเกิดอะไรบ้างก็ไม่รู้
                System.out.println("Error"+ e.getMessage());
                System.out.println("Operation error!");
            }
            return count;//ส่งคืนค่า count
        }
        //ฟังก์ชันที่เปรียบเทียบตัวที่มันอยู่ติดกัน ถ้าตัวที่มันติดกันมันเหมือนกันมันจะตัดทิ้งไป1ตัวและวนรอบต่อไปเรื่อยๆ
        static void removesamedata(){ 
            int count =0,i = 0;
            for( i = 0; i < dict.size()-1 ; i++)//วนนรอบตั้งแต่ตัวแรกจนแว่าจะถึงตัวก่อนสุดท้ายเพราะว่ามันจะต้องเปรียบเทียบตัวที่ถัดจากมัน
                while (dict.get(i).compareAll(dict.get(i+1)))//วนรอบเปรียบเทียบโดยใช้ฟังก์ชันcompareAllว่ามันเหมือนกันทั้งword,mean,typeหรือไม่
                {
                    dict.remove(i+1);//ถ้าซ้ำกันก็ลบทิ้ง
                    count++;//วนหาครั้งต่อไปเรื่อยๆ
                }
                System.out.printf("Total same data found %d\n", count);//ปริ้นว่ามันลบกี่ตัว
        }
        static int countmaxmean(){ //เป็นฟังก์ชั่นที่ดูว่าตัวไหนมีความหมายมากที่สุด
            int j = 1,max = 0,index = 0;
            for(int i =0 ;i<dict.size()-1;i++)// วนรอบเปรียบเทียบตั้งแต่ตัวแรกถึงตัวก่อนสุดท้าย
                if(dict.get(i).compareTo(dict.get(i+1))==0){//ถ้าเปรียบเทียบตัวมันเอากับตัวถัดไป ถ้าเหมือนกัน
                    j++; //j เป็นตัวนับคำที่เหมือนกันถ้ามันเจอตัวคำที่เหมือนกัน มันจะนับเพิ่มไปอีก1
                    if(max<j){
                        max = j;//ถ้า max<j เราจะจำค่า j แทน
                        index = i;//เป็นจุดเริ่มต้นของคำสั่งว่ามันอยู่ที่ array ตัวที่เท่าไหร่
                    }
                }
                else
                j = 1;
                System.out.printf("Maximum Meaning word %d\n",max);//ปริ้นตัวที่มันมีค่ามากที่สุด
                return index;
            }
            public static void dictlist(int start,int stop){
                for(int i = start; i<=stop;i++)
                    dict.get(i).print(i-start+1);
            }
            public static int dictSheach(String str){
                    Dnode key = new Dnode();
                    int start = 0,stop = 0;
                    key.word = str;
                    int j = Collections.binarySearch(dict,key);
                    if(j>=0){
                        for(start = j; start>0 && (dict.get(start - 1).compareTo(key)==0); start--);
                        for(stop = j; (stop<dict.size()-1)&&(dict.get(stop+1).compareTo(key)==0);stop++);
                    }
                    if(j>=0)
                    {
                        System.out.printf("found %s %d token at %d - %d\n",str,stop-start-1,start,stop);
                        dictlist(start,stop);
                    }
                    else
                        System.out.printf("%s Not found\n",str);
                        return start;
            }
            
            public static void printstat()
            {
                System.out.printf("Total remaining size %d\n",dict.size());
                int j = countmaxmean(); //เก็บข้อมูลที่มากที่สุด(index)มาเก็บไว้ใน j
                Dnode x = new Dnode();
                x = dict.get(j); //เอาค่า j มาเก็บไว้ในค่า x
                j = dictSheach(x.word); //เราจะค้นหาคำว่าอะไร
            }
        
    public static void main(String[] args){
        readfile();
        System.out.printf("Total read %d\n",dict.size());
        Collections.sort(dict);
        removesamedata();
        printstat();
        Scanner in = new Scanner(System.in);
        String str = "";
        while(!str.equalsIgnoreCase("end")){
            System.out.print("Enter word ");
            str = in.nextLine();
            str = str.trim().replaceAll("\\s+", " ");
            dictSheach(str);

        }
        in.close();
        System.out.println("END PROGRAM");
        System.out.println("WRITH BY 63070501058 SARUNWARIN WONGUDOMTANAKOL");

    }
}
