

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.TreeSet;


        public class dicttreeset {
        static TreeSet<BNODE> dict = new TreeSet<BNODE>(); //สร้างตัวแปลเอาไว้เก็บข้อมูลที่เป็น array มันจะเกิดขึ้นมาพร้อมกับการสร้าง class เป็นประเภท tree
        public static int readfile() {
            String str = null;
            int count = 0;
            try {
                FileInputStream fr = new FileInputStream("utf8lexitron.csv");
                InputStreamReader csv = new InputStreamReader(fr, "UTF8");
                BufferedReader fsc = new BufferedReader(csv);
                fsc.read();
                while((str = fsc.readLine()) != null) {
                    Linkdictnode(str);
                    count++;
                }
                fsc.close();
            } catch(FileNotFoundException e) {
                System.out.println(e.getMessage());
                System.out.println("File not found");
            } catch (Exception e) {
                System.out.println("Error " + e.getMessage());
                System.out.println("Operation error");
            }
            return count;
        }
        public static void Linkdictnode(String str){ //เป็นฟังก์ชันที่เอาข้อมูลเข้ามา 1 บรรทัดแล้วมาเก็บใน BNODE
            BNODE x = new BNODE(str);
            if(dict.contains(x))//หาว่าไอ้ข้อมูลที่เราใส่เข้ามามันมีใน dict รึป่าว หาแค่คำยังไม่ได้หาความหมาย
            {
                TreeSet<BNODE> z = (TreeSet<BNODE>) dict.subSet(x, true,x,true); //ดึงตัวที่มันซ้ำกันออกมา แค่ตัวเดียวเก็บไว้ใน Z
                if(!z.first().mean.contains(x.mean.get(0)))
                    z.first().mean.add(x.mean.get(0));
            }
            else
                    dict.add(x);//
        }
        
            public static void dictSearch(String str) { //เป็นฟังก์ชันที่มีเพื่อค้นหาคำศัพทย์
                str = str.trim().replaceAll("\\s+", " ");//เอาเว้นวรรคข้างหน้าและข้างหลังออก และเอาพวกช่องว่างอื่นๆออก
                BNODE key = new BNODE(str);//รับค่ามาใส่ใน key ในรูปแบบ string แล้วมาอยู่ใน BNODE 
                    if(dict.contains(key)) //ดูว่าใน dict มี keyอยู่หรือไม่
                    {
                        TreeSet<BNODE> z = (TreeSet<BNODE>) 
                        dict.subSet(key, true,key,true);// subset ของข้อมูลเพื่อวนรอบปริ้นความหมายของคำนั้น
                        System.out.printf("%s have %d meaning words\n",str,z.first().mean.size());//ปริ้นความหมาย
                        int i = 0;
                        for(String x : z.first().mean)//วนรอบว่าคำนั้นมีความหมายกี่คำ
                        
                            System.out.printf("%d) %s\n",++i,x);//ปริ้นความหมายทั้งหมดของคำ
                    }else //ถ้าเกิดว่าหาไม่เจอ
                        System.out.printf("%s not found!!! \n",str);
            }
            
            public static void printstat() //เป็นฟังก์ชันที่สร้างมาเพื่อแสดงจำนวนคำและความหมายทั้งหมด
            {
                System.out.printf("Total word %d words\n",dict.size()); //แสดงจำนวนคำและความหมายทั้งหมด
                int sum = 0, max = 0;
                BNODE z = new BNODE();
                for(BNODE itr : dict){ //วนรอบเทียบตัวใน dict ทีละคำ
                    sum = sum + itr.mean.size();//sum คือค่าความหมายของทุกคำว่ามันมีทั้งหมดเท่าไหร่
                    if(max < itr.mean.size()){ //หาค่าที่มีความหมายมากที่สุดใน dict ว่ามีกี่คำ
                        max = itr.mean.size();//max เก็บค่าที่มันมีมากที่สุดใน dict
                        z = itr;// z มันเก็บทั้งคำศัพท์และความหมายทั้งหมดของคำนั้นที่มันรู้แล้วว่ามีความหมายมากที่สุด
                    }
                    
                }
                System.out.printf("Total meaning %d \n",sum);// ปริ้นค่าความหมายทั้งหมดของคำศัพท์
                System.out.printf("%s have %d meaning\n ", z.word,z.mean.size());//ปริ้นว่าคำคำนั้นที่มีความหมายมากที่สุดมีกี่ความหมาย
                int i = 0;
                for(String x : z.mean){//วนloopเพื่อปริ้นความหมายของคำที่มีความหมายมากที่สุดน
                    System.out.println((++i) + ")" + x); //ปริ้นความหมายของคำที่มีความหมายมากที่สุดน
                }
            }
        
    public static void main(String[] args){
        int count = 0;
        count = readfile();
       System.out.printf("Total read %d records.\n",count);
       printstat();
       Scanner in = new Scanner(System.in);
       String str = "";
       while(!str.equalsIgnoreCase("end"))
       {
        System.out.print("Enter word : ");
        str = in.nextLine();
        dictSearch(str);
       }
       in.close();
        System.out.println("END PROGRAM");
        System.out.println("WRITH BY 63070501058 Monthida");
        
    }
}
