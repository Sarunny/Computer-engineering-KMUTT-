import java.util.ArrayList;

public class BNODE implements Comparable<BNODE> {
    String word; //อ่านตรงคำศัพย์ในช่องแรกที่ขั้นด้วย ,
    ArrayList<String> mean; //จองช่องใหม่เพือสร้าง node ใหม่เราจองเป็น array ไว้เพราะว่าคำ1คำอาจมีหลายความหมาย

    public BNODE() //เป็นการสร้างกล่องเปล่าขึ้นมา
    {
        word = "";//ค่าเริ่มต้นของ word เป็นช่องเปล่าๆ
        mean = new ArrayList<String>();//สร้าง array list ที่ชื่อ mean ให้เสร็จ
        mean.add(""); //ใส่ช่องเปล่าๆเข้าไปใน array list ที่ชื่อ mean
    }

    public BNODE(String buff)
    {
        buff = buff.trim().replaceAll("\\s+", " ");//เอาเว้นวรรคข้างหน้าและข้างหลังออก และเอาพวกช่องว่างอื่นๆออก
        String[] str = buff.split(",");//มันจะตัดตามคอมมา
        word = str[0]; //ให้ word อยู่ในช่องแรกของ arrays
        String meaning;
        if(str.length == 1) //ถ้าความยาวของ array มีเท่ากับ 1 แสดงว่ามันมีแค่คำศัพท์อันเดียว
            meaning = "";
        else if(str.length == 2)//ถ้าความยาวของ array มีเท่ากับ 2 แสดงว่ามันมี 1 ความหมาย
            meaning = str[1];
        else //อันนี้คือมันมีความยาว arrays เท่ากับ 3 แสดงว่ามันมีทั้ง word/mean/typeเลย
            meaning = str[1] + "(" + str[2] + ")";//ให้ array ที่ชื่อ meaningเก็บความหมายของคำและ(ประเภคของคำ)ไปด้วย
        mean = new ArrayList<String>();//สร้างarray ที่ชื่อ meaningให้สมบูรณ์ 
        mean.add(meaning);//ใส่ความหมายเข้าไป
    }
    public int compareTo(BNODE x)//ใช้เปรียบเทียบ word
    {
        return (int)this.word.compareToIgnoreCase(x.word);
    }
}
