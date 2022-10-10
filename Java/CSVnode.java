import java.util.Comparator;
public class CSVnode implements Comparable <CSVnode> {
    int id;
    long num; 
    String str1,str2;

public CSVnode(){

}
public int compareTo(CSVnode x){
    if(num - x.num > 0)
    return 1;
    else if (num - x.num ==0)
    return 0;
    else return -1;

}
public CSVnode (int a,long b, String c,String d){
    id = a;
    num = b;
    str1 = c;
    str2 = d;

}
public void printdata(){
    System.out.printf("%6d  %d  %s  %s\n",id,num,str1,str2);
    
}
}
class cmpnum implements Comparator <CSVnode>{
    public int compare(CSVnode x,CSVnode y){
        if(x.num == y.num)
        return 0;
        else if (x.num > y.num)
        return 1;
        else
        return -1;
    }
}
class cmpstring1 implements Comparator <CSVnode>{
    public int compare(CSVnode x,CSVnode y){
        return (int) x.str1.compareToIgnoreCase(y.str1);
    }
}
class cmpstring2 implements Comparator <CSVnode>{
    public int compare(CSVnode x,CSVnode y){
        return (int) x.str2.compareToIgnoreCase(y.str2);
    }
}









