#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

long int  factorial(int n)
{
	long int ans;
	int i ;
	for(ans = 1 , i = n ; i >= 1 ; i = i-1)
	{
		ans = ans * i;
	}
	 return ans;
}
int fibonacci(int n)
{
	int ans=1,fi,fc=1,ft=0,i;
	if(n<=1)
	ans = n;
	else{
		for(i=2;i<=n;i++){
			fi = fc + ft;
			ft = fc;
			fc = fi; 
		}
		ans = fi;
	}
	return ans;
}

//ans = nCr(n,r)
long int nCr(int n,int r)
{
	long int ans;
	ans = factorial(n)/(factorial(r)*factorial(n-r));
	return ans;
}

//ans = GCD(m,n)
int GCD(int m ,int n)
{
	int ans;
	for( ans = m ;m%ans !=0 || n%ans !=0 ;ans=ans-1);
	return ans;	
}

int get_int(int min,int max)
{
	int ans;
	char ch;
	while((scanf("%d%c",&ans,&ch)!=1&&ch!='\n')||ans<min||ans>max)
	{    
	rewind(stdin);
	printf("Input error please input again.");	
	}
	return ans;
}
//guessing
void guessing()
{
	int y,x,count;
	srand(time(NULL));
	x = rand() %100 +1;
	count = 0;
	while (x!=y&&count!=7){
		count = count + 1;
		printf("%d. Input your number : \n",count);
		y = get_int(0,99);
		if(x==y){
			printf("Hulee! Your answer is correct\n");
		}	
		else if(y>x){
			printf("Hmm.. Your answer is too much\n");
		}
		else{
			printf("Hmm.. Your answer is too low\n");
		}	 
		if(count==7&&x!=y){
			printf("\nWrong, the correct answer is %d\n",x);
		}		
	}
}
int get_manu()
{
	int select;
	printf("##################################################\n");
	printf("#                 Manu of Calculate              #\n");
	printf("##################################################\n");
	printf("#              1. Fibonacci function             #\n");
	printf("#              2. Combination number             #\n");
	printf("#              3. Find GCD (x,y)                 #\n");
	printf("#              4. Guessing number                #\n");
	printf("#              0. Exit                           #\n");
	printf("##################################################\n");
	printf("Enter your number :");
	select = get_int(0,4);
	return select;
}
int main()
{
	int select,m,n,r,x,y,count;
	long int ans;
	char ch;
	do
	{
		select = get_manu();
		if (select==1)
		{
		do{
					printf("Program fibonacci\n");
					printf("Enter n =");
					n = get_int(0,10);
					ans = fibonacci(n);	
					printf("\nans of fibonacci(%d) = %d\n",n,ans);
					do{
                		printf("\nEnter y to play again or n to exit.");
                       scanf(" %c",&ch);
            		}
            		while(ch!='y'&&ch!='n');
				}
				while (ch == 'y');	
			}	
		
		else if (select==2)
		{
			do{
			printf("program combination number nCr \n");
			printf("Input n = ");
			n = get_int(1,10);
			printf("Input r = ");
			r = get_int(1,n);
			ans = nCr(n,r);
			printf("\nans of %dC%d = %d\n",n,r,ans);
			do{
				printf("\nEnter y to play again or n to exit.");
                    	scanf(" %c",&ch);
			}
            		while(ch!='y'&&ch!='n');
				}
				while (ch == 'y');
			}	
		else if (select==3)
		{
			do{
			
			printf("\nCalculatr GCD (X,Y)\n");
			printf("Input X : ");
			m = get_int(1,100000);
			printf("Input Y : ");
			n = get_int(1,100000);
			ans = GCD(m,n);
			printf("answer of GCD (%d,%d) = %d \n\n\n",m,n,ans);
			do{
				printf("\nEnter y to play again or n to exit.");
                scanf(" %c",&ch);
				}
            		while(ch!='y'&&ch!='n');
				}
				while (ch == 'y');
			}
		else if (select==4)
		{
			do{
			
			printf("Random Guess Program\n");
			guessing();
			do{
				printf("\nEnter y to play again or n to exit.");
                scanf(" %c",&ch);
			}
            		while(ch!='y'&&ch!='n');
				}
				while (ch == 'y');
			}
}while (select !=0);
	printf("End program");
	return 0;
}
