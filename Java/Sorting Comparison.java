
import java.util.Arrays;
import java.util.Scanner;

public class ASS2 {
    public static void main(String[] args) {
            long starttime,stoptime;
            double scstime,scsaddtime,scsdtime,slstime,slsaddtime,slsdtime,inserttime,insertaddtime,insertdtime,bubbletime,bubbleaddtime ,bubbledtime ;
            char ch = 0;
            Scanner scan = new Scanner(System.in);
            Array test = new Array(100010);
            Array temp = new Array(100010);
            System.out.println(" ______________________________");
            System.out.println("|                              |");
            System.out.println("| This is my sorting program.  |");
            System.out.println("|______________________________|");
            System.out.println("          / (*O*) /            ");                  
            
            if(test.Downlodefiledata("D:\\CPE111term2java\\test (1).csv")>0)
            {
              do{
                
                System.out.println("file read = "+test.count);//ข้อมูลที่เราเก็บ
                temp.data = Arrays.copyOf(test.data,10010);//ก๊อบข้อมูลมา
                starttime = System.nanoTime();
                temp.scansort(0,10000);
                stoptime = System.nanoTime();
                scstime = (stoptime-starttime)/1E6;
                
                starttime = System.nanoTime();
                temp.scansort(0,10001);
                stoptime = System.nanoTime();
                scsaddtime = (stoptime-starttime)/1E6;
             
              //  temp.printtest(0,9); อันนี้ให้มันแสดงผลเฉยๆ
                starttime = System.nanoTime();
                temp.scansort2(0,10001);
                stoptime = System.nanoTime();
                scsdtime = (stoptime-starttime)/1E6;
                
                temp.data = Arrays.copyOf(test.data,10010);//ก๊อบข้อมูลมา
                starttime = System.nanoTime();
                temp.selectionsort(0,10000);
                stoptime = System.nanoTime();
                slstime = (stoptime-starttime)/1E6;
                
                starttime = System.nanoTime();
                temp.selectionsort(0,10001);
                stoptime = System.nanoTime();
                slsaddtime = (stoptime-starttime)/1E6;
           
                starttime = System.nanoTime();
                temp.selectionsort2(0,10001);
                stoptime = System.nanoTime();
                slsdtime = (stoptime-starttime)/1E6;
              

                temp.data = Arrays.copyOf(test.data,10010);//ก๊อบข้อมูลมา
                starttime = System.nanoTime();
                temp.insertionSort(0,10000);
                stoptime = System.nanoTime();
                inserttime = (stoptime-starttime)/1E6;
             
                starttime = System.nanoTime();
                temp.insertionSort(0,10001);
                stoptime = System.nanoTime();
                insertaddtime = (stoptime-starttime)/1E6;
              
                starttime = System.nanoTime();
                temp.insertionSort2(0,10001);
                stoptime = System.nanoTime();
                insertdtime = (stoptime-starttime)/1E6;
       
                temp.data = Arrays.copyOf(test.data,10010);//ก๊อบข้อมูลมา
                starttime = System.nanoTime();
                temp.bubble(0,10000);
                stoptime = System.nanoTime();
                bubbletime = (stoptime-starttime)/1E6;
                
                starttime = System.nanoTime();
                temp.bubble(0,10001);
                stoptime = System.nanoTime();
                bubbleaddtime = (stoptime-starttime)/1E6;

                starttime = System.nanoTime();
                temp.bubble2(0,10001);
                stoptime = System.nanoTime();
                bubbledtime = (stoptime-starttime)/1E6;

                System.out.printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
                System.out.printf("|         SORT         |         RANDOM DATA (n)      |         INSERT DATA (n+1)       |         DESCANDING (n+1)     |\n");
                System.out.printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
                System.out.printf("| SCAN SORT            |          %f          |            %f           |           %f         |\n",scstime,scsaddtime,scsdtime);
                System.out.printf("| SELECTION SORT       |          %f          |            %f           |           %f         |\n",slstime,slsaddtime,slsdtime);
                System.out.printf("| INSERTION SORT       |          %f           |            %f             |           %f         |\n",inserttime,insertaddtime,insertdtime);
                System.out.printf("| BUBBLE SORT          |          %f          |            %f           |           %f         |\n",bubbletime,bubbleaddtime ,bubbledtime);
                System.out.printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
               
                System.out.printf("press[y] to continue, others to exit.");
                if(scan.hasNext())
                ch = scan.next().charAt(0); 
                
              }while (ch=='y'||ch=='Y');
              System.out.println("End program.");
              System.out.println("Program writen by 63070501058 Sarunwarin Wongudomtanakol");
          }
            else
            System.out.println("ERROR");
    }
    
}
