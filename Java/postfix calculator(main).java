
import java.util.Scanner;
import java.util.Stack;
import java.util.ArrayList;

public class ASS5main {
    static ArrayList<String> postfix = new ArrayList<String>();
    static Stack<String> oprstack = new Stack<String>();
    static Stack<Double> numstack = new Stack<Double>();
    static double ans = 0;

        public double ValueOf(String str)
            {
                if(str.equalsIgnoreCase("pi"))
                    return Math.PI;
                else if(str.equalsIgnoreCase("ans"))
                    return ans;
                else
                    return Double.parseDouble(str);
            }
        public void changeinfixispostfix(String[] token)
            {
                int group,cur,prior = 0,i;
                String buff;
                postfix.clear(); 
                oprstack.clear();
                for(i=0;i<token.length;i++)
                    {
                        group = ASS5function.checkgroup(token[i]);
                        if(group ==1)
                            postfix.add(token[i]);
                        else if(group>=2 && group <=6)
                        {
                            do
                            {
                                cur = ASS5function.checkgroup(token[i]);
                                buff = oprstack.peek();
                                prior = ASS5function.checkgroup(buff);
                                if(prior>=cur && prior<=6)
                                {
                                    buff = oprstack.pop();
                                    postfix.add(buff);
                                }

                            }while(prior>=cur && prior<=6);
                            oprstack.push(token[i]);

                        }else if (group == 7)
                        oprstack.push(token[i]);
                       
                        else if (group == 8)
                        {
                            do
                            {
                                buff = oprstack.pop();
                                if(!buff.equals("("))
                                    postfix.add(buff);
                            }while(!buff.equals("("));
                        }
                }
            }

        public double calculatepostfix()
        {
            double ans=0,num,num1,num2;
            int i,group;
            String token = new String("");
            for(i=0;i<postfix.size();i++)
            {
                token = postfix.get(i);
                group = ASS5function.checkgroup(token);
                if(group==1)
                {
                    num1 = ValueOf(token);
                    numstack.push(num1);
                }
                else if(group>=2 && group<=4)
                {
                    num1 = numstack.pop();
                    num2 = numstack.pop();
                    if((group == 2) && token.equals("+"))
                        numstack.push(num2+num1);
                    else if((group == 2) && token.equals("-"))
                        numstack.push(num2-num1);
                    else if((group == 3) && token.equals("/"))
                        numstack.push(num2/num1);
                    else if((group == 3) && token.equals("*"))
                        numstack.push(num2*num1);
                    else if(group == 4)
                        numstack.push(Math.pow(num2, num1));

                }else if (group == 5)
                {
                    num1 = numstack.pop();
                    numstack.push(-num1);
                }
                else if(group == 6)
                {
                    if(token.equalsIgnoreCase("sin")){
                        num = Math.sin(numstack.pop()*Math.PI/180);
                        numstack.push(num);
                    }
                    else if(token.equalsIgnoreCase("cos")){
                        num = Math.cos(numstack.pop()*Math.PI/180);
                        numstack.push(num);
                    }
                    else if(token.equalsIgnoreCase("tan")){
                        num = Math.tan(numstack.pop()*Math.PI/180);
                        numstack.push(num);
                    }
                    else if(token.equalsIgnoreCase("asin")){
                        num = Math.asin(numstack.pop())*180 / Math.PI;
                        numstack.push(num);
                    }
                    else if(token.equalsIgnoreCase("acos")){
                        num = Math.acos(numstack.pop())*180 / Math.PI;
                        numstack.push(num);
                    }

                    else if(token.equalsIgnoreCase("atan")){
                        num = Math.atan(numstack.pop())*180 / Math.PI;
                        numstack.push(num);
                    }
                    else if(token.equalsIgnoreCase("sqrt")){
                        num = Math.sqrt(numstack.pop());
                        numstack.push(num);
                    }
                    else if(token.equalsIgnoreCase("log")){
                        num = Math.log10(numstack.pop());
                        numstack.push(num);
                    }
                    else if(token.equalsIgnoreCase("exp")){
                        num = Math.exp(numstack.pop());
                        numstack.push(num);
                    }
                    else if(token.equalsIgnoreCase("abs")){
                        num = Math.abs(numstack.pop());
                        numstack.push(num);
                    }
                }
                   
            }ans = numstack.pop();
            return ans;
        }

public static void main(String[] args)
{
    ASS5main calc = new ASS5main();
    Scanner in = new Scanner(System.in);
    String str;
    do
    {
        System.out.print("expression >> ");
        str = in.nextLine();
        if(str.trim().equalsIgnoreCase("help"))
            System.out.println("token = sin, cos, tan, asin, acos, atan, sqrt, log, exp, abs +, -, *, /, ^, (, ), pi, ans");
        else{
            if(!str.equalsIgnoreCase("end"))
            {
                str = "(" + str +")";
                str = ASS5function.Transform(str);
                String [] token = str.trim().split("\\s+");
                ASS5function.changesignoperator(token);
                int state = ASS5function.checkstate(token);
                if(state == 1 || state == 8)
                {
                    calc.changeinfixispostfix(token);
                    System.out.println("PRINT = "+postfix);
                    ans = calc.calculatepostfix();
                    System.out.println("ANSWER >> "+ans);
                }
                else
                    System.out.println("ENSWER >> ERROR!!!!!!!!");
            }
        }
    }
    while(!str.equalsIgnoreCase("end"));
    System.out.println(" ^0^ ^0^ ^0^ ^0^ ^0^ ^0^ ^0^ ^0^ ^0^ ^0^ ^0^ ^0^ ^0^");
	System.out.println("WRITTEN BY 63070501058 SARUNWARIN WONGUDOMTANAKOL");
	in.close();

}

}

