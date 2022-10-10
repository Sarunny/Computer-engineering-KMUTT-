import java.util.Comparator;
import java.util.ArrayList;

public class Dnode implements Comparable<Dnode>{ //ประกาศตัวแปลที่เราต้องใช้ใน main ที่ต้องเอาไว้ไปเปรียบเทียบ
    String word;
    String mean;
    String type;
    public Dnode(){ //สร้าง node เปล่า
        word = "";
        mean = "";
        type = "";
    }
    public Dnode(String buff){//อ่านข้อมูลมา 1 บรรทัดแล้วเอาใส่เข้ามาในนี้ และมันจะแยกเป็นตัวๆ
        buff = buff.trim().replaceAll("\\s+"," ");//เอาเว้นวรรคข้างหน้าและข้างหลังออก และเอาพวกช่องว่างอื่นๆออก
        String[] str = buff.split(",");//มันจะตัดตามคอมมา
        word = str[0];
        mean = str[1];
        type = str[2];
    }
    public int compareTo(Dnode x){ // เป็นฟังก์ชั่นที่ใช้เปรียบเทียบกับค่า x
        return (int) this.word.compareToIgnoreCase(x.word);//เปรียบเทียบค่าของมันเอง(word)กับค่า xแบบไม่สนใจตัวใหญ่ตัวเล็ก
    }
    boolean compareAll(Dnode x) //เป็นฟังก์ชันในการเช็คว่ามันเป็นword,mean,typeเหมือนกันหรือไใ่
    {
        if(this.word.equalsIgnoreCase(x.word) && this.mean.equalsIgnoreCase(x.mean)&&this.type.equalsIgnoreCase(x.type))//ถ้าเหมือนกันทุกอย่าง
        return true;//ส่งคืนค่าtrue
        else return false;//ถ้าไม่เหมือนกันทุกอย่างส่งคืนค่าfalse
    }
    void print(){ //ปริ้นข้อมูลในตัวของมันออกมาแบบไม่มีหมายเลขนำหน้า
        System.out.printf("%-15s %s(%s)\n",word,mean,type);
    }
    void print(int i){//ปริ้นข้อมูลในตัวของมันออกมาแบบมีหมายเลข i นำหน้า
        System.out.printf("%d)%-15s %s(%s)\n",i,word,mean,type);
    }

}
