import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.HashMap;


public class dicthashmap {
    static HashMap<String,Dictnode> dict = new HashMap<String,Dictnode>();
    public static int readfile(){
        String str = null;
        int count = 0;
        try{
            FileInputStream fcsv = new FileInputStream("D:\\CPE111term2java\\utf8lexitron.csv"); //InputStreamมันจะทำหน้าที่อ่านหรือแปลงไฟล์ของเราให้เป็น byte รับเข้ามาใน stream ของเรา
            InputStreamReader utf = new InputStreamReader(fcsv,"UTF8"); //อ่านข้อมูลจากไฟล์แล้วเปลี่ยนให้เป็นรูปแบบ byte 
            BufferedReader fbuff = new BufferedReader(utf);//อ่านข้อความหรือตัวอักษรของข้อมูลที่ input เข้ามา
            System.out.printf("BOM = %X\n",fbuff.read());// อ่านข้อมูล BOM ทิ้งไป แล้วค่อยเริ่มอ่านข้อมูลจริง
            while((str = fbuff.readLine()) !=null) { //วนรอบอ่านข้อมูลเพื่อดูว่ามันอ่านได้หรือไม่
             Dictnode x = new Dictnode(str);
    if(dict.containsKey(x.word)) {
     Dictnode z = dict.get(x.word);
     if(!z.mean.contains(x.mean.get(0))) {
      z.mean.addAll(x.mean);
      dict.put(x.word, z);
     }
    }
    else {
     dict.put(x.word, x);
    }
    count++;
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
    public static void dictSearch(String str){
     str = str.trim().replaceAll("\\s+", " ");
        if(dict.containsKey(str)){
            Dictnode z = dict.get(str);
            System.out.printf("%s have %d meaning\n",str,z.mean.size());
            for(int i=0; i<z.mean.size();i++)
                System.out.println(i + 1 + ")" + z.mean.get(i));
            }else
                System.out.printf("%s not found\n",str);
        }
    public static void printstat(){
        System.out.printf("Total word size %d word\n",dict.size());
        int sum = 0, max = 0;
        Dictnode m = new Dictnode();
        for(String itr : dict.keySet())
        {
            Dictnode z = dict.get(itr);
            sum = sum + z.mean.size();
            if(max < z.mean.size()){
                max = z.mean.size();
                m = z;
            }
        }
        System.out.printf("Total meaning size %d words\n",sum);
        System.out.printf("%s have %d meaning\n", m.word,m.mean.size());
        for(int i = 0; i < m.mean.size(); i++)
            System.out.println(i + 1 + ")" + m.mean.get(i));
    }
    
    public static void main(String[] args){
        int count = 0;
        count = readfile();
        System.out.printf("Total Read %d records.\n",count);
        printstat();
        Scanner in = new Scanner(System.in);
        String str = "";
        while(!str.equalsIgnoreCase("end")){
            System.out.printf("Enter word : ");
            str = in.nextLine();
            dictSearch(str.toLowerCase());
        }
        System.out.println("End program");
        System.out.println("WRITTEN BY SARUNWARIN WONGUDOMTANAKOL 63070501058");
        in.close();
    }
}