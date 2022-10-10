import java.util.Scanner;
 public class ASS1 {
     static long factorial(int n)
     {
         long a;
         if(n==0)
         {
             System.out.printf("%d! is base case return answer of %d! = 1\n",n,n);
             System.out.printf("Calculate 0! complete.\n");
             return 1;
         }
         else{
            System.out.printf("%d! is recersive case.Answer = %d * recersive of %d!\n",n,n,n-1);
            System.out.printf("     Recursion to calculate %d!\n",n-1);
            a= n*factorial(n-1);
            if(n>1)
            System.out.printf("Calculate %d! complete.\n",n-1);
            System.out.printf("     Return answer from %d! = %d to calculate %d! = [%d*%d!] = %d*%d = %d \n",n-1,a/n,n,n,n-1,n,a/n,a);
             return a;

         }

     }
     static int  checkit(int min,int max){
         int n = 0;
         boolean complete = false;
         Scanner stdin = new Scanner(System.in);
         while(!complete){
             try{
                n = stdin.nextInt();
                if(n>=min&&n<=max)
                    complete = true;
                else
                    System.out.printf("Input error!! Please enter between %d-%d\n",min,max);
             }catch (Exception err){
                 System.out.printf("Input error!! Please enter between %d-%d\n",min,max);
                 stdin.nextLine();
             }
         }return n;
     }
     public static void main(String[] args) 
     {
        int n;
        char ch=0;
        long ans;
        Scanner scan = new Scanner(System.in);
        
            System.out.println("My Recursion Program.><");
            System.out.println("Program calculate n! by recuresion(n<=15)");
            do{
            System.out.print("Enter n = ");
            n = checkit(0,15);
            ans = factorial(n);
            System.out.printf("Complete calculation of %d!,answer = %d\n",n,ans);
            System.out.printf("Enter<y> to continue,others to exit.:)");
            if(scan.hasNext())
                ch = scan.next().charAt(0);
            }
        while(ch=='y'||ch=='Y');
        System.out.println("End program.");
        System.out.println("Program writen by 63070501058 Sarunwarin Wongudomtanakol");
     }

    
}
