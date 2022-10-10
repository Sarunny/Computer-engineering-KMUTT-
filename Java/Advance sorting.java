import java.util.Arrays;
public class ASS3 {
    public static void main(String[] args) {
        double starttime,stoptime,quicksorttime ,middleguicksorttime,quicksortstrtime,middleguicksortstrtime,mergesorttime,mergesortstrtime,libalytime,cmpnumtime;
        Array test = new Array(100010);
        Array temp = new Array(100010);
        if(test.Downlodefiledata("D:\\CPE111term2java\\test (1).csv")>0)
        {
            temp.data = Arrays.copyOf(test.data,100000);
            System.out.println("_____________________________________________________________________________________________________________________________________________________________________");
            System.out.println("|                    |               |                |                                                      |                                                      |");
            System.out.println("|       Unsort       |     order     |     number     |                       String1                        |                        String2                       |");
            System.out.println("|____________________|_______________|________________|______________________________________________________|______________________________________________________|");
            temp.printtest();
            starttime = System.nanoTime();
            temp.quicksort(0,99999);
            stoptime = System.nanoTime();
            quicksorttime = (stoptime-starttime)/1E6;

            System.out.println("_________________________________________________________________________________________________________________________________________________________________________________________________________");
            System.out.println("|                    |               |                |                                                      |                                                      |");
            System.out.println("|      NUM sort      |     order     |     number     |                       String1                        |                        String2                       |");
            System.out.println("|____________________|_______________|________________|______________________________________________________|______________________________________________________|");
            temp.printtest();
            temp.data = Arrays.copyOf(test.data,100000);
            starttime = System.nanoTime();
            temp.middleguicksortstr(0,99999);
            stoptime = System.nanoTime();
            middleguicksortstrtime = (stoptime-starttime)/1E6;

            System.out.println("_________________________________________________________________________________________________________________________________________________________________________________________________________");
            System.out.println("|                    |               |                |                                                      |                                                      |");
            System.out.println("|    STRING sort     |     order     |     number     |                       String1                        |                        String2                       |");
            System.out.println("|____________________|_______________|________________|______________________________________________________|______________________________________________________|");
            temp.printtest();
            temp.data = Arrays.copyOf(test.data,100000);
            starttime = System.nanoTime();
            temp.quicksortstr(0,99999);
            stoptime = System.nanoTime();
            quicksortstrtime = (stoptime-starttime)/1E6;
            //temp.printtest();

            temp.data = Arrays.copyOf(test.data,100000);
            starttime = System.nanoTime();
            temp.middleguicksort(0,99999);
            stoptime = System.nanoTime();
            middleguicksorttime = (stoptime-starttime)/1E6;
            //temp.printtest();

            temp.data = Arrays.copyOf(test.data,100000);
            starttime = System.nanoTime();
            temp. mergesort(0,99999);
            stoptime = System.nanoTime();
            mergesorttime = (stoptime-starttime)/1E6;
           // temp.printtest();

            temp.data = Arrays.copyOf(test.data,100000);
            starttime = System.nanoTime();
            temp.mergesortstr(0,99999);
            stoptime = System.nanoTime();
            mergesortstrtime = (stoptime-starttime)/1E6;
            //temp.printtest();
        
            temp.data = Arrays.copyOf(test.data,100000);
            starttime = System.nanoTime();
            Arrays.sort(temp.data,new cmpstring2());
            stoptime = System.nanoTime();
            libalytime = (stoptime-starttime)/1E6;
            //temp.printtest();

            temp.data = Arrays.copyOf(test.data,100000);
            starttime = System.nanoTime();
            Arrays.sort(temp.data,new cmpnum());
            stoptime = System.nanoTime();
            cmpnumtime = (stoptime-starttime)/1E6;
            //temp.printtest();

            System.out.printf("---------------------------------------------------------------------------\n");
            System.out.printf("|     Sorting     |      Number(ms)      |     String(ms)     |\n");
            System.out.printf("--------------------------------------------------------------\n");
            System.out.printf("|   Library Sort  |       %f     |     %f     |\n",cmpnumtime,libalytime);
            System.out.printf("|   Quick Sort1   |       %f      |     %f     |\n",quicksorttime,quicksortstrtime);
            System.out.printf("|   Quick Sort2   |       %f      |     %f     |\n",middleguicksorttime,middleguicksortstrtime);   
            System.out.printf("|   Merge Sort    |       %f      |     %f      |\n",mergesorttime,mergesortstrtime);
            System.out.printf("---------------------------------------------------------------\n");
        }
            else
                System.out.println("ERROR!!!!!!!!!!!!!");
                System.out.println("END PROGRAM\n");
                System.out.println("Program writen by 63070501058 Sarunwarin Wongudomtanakol");
            
        }

    }

