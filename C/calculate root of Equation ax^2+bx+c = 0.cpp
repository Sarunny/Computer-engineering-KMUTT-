#include <stdio.h>
#include <math.h>
int newton_raphson (double a,double b,double c,double err,double xp,double *Xn)
{
	double delta = 1 ;
	int count = 0 ;
	do
	{
		if(2*a*xp+b==0)
		  xp = xp + 0.0000001;
		else
		{ 
			delta = ((a*xp*xp )+ ((b*xp)+ c))/((2*a*xp)+b);
			*Xn = xp  - delta;
			xp = *Xn;
		} count++;
	}while (fabs(delta) > err && count<1000);
	if (count < 1000)
		return count;
	else
		return 0;
		
}

int main()
{
	double a,b,c,x1,x2;
	char ch;
	int loop;
	do
	{
		printf("\n Program calculate root of Equation ax^2+bx+c = 0 \n");
		printf("Input parameter a : ");
		scanf("%lf",&a);
		printf("Input parameter b : ");
		scanf("%lf",&b);
		printf("Input parameter c :");
		scanf("%lf",&c);
		
		loop = newton_raphson(a,b,c,0.0000001,100.123,&x1);
		printf("run %d round\n ",loop);
		if(loop==0)
			printf("error NAJAAA cant find answer!!\n");
		else
		{
			printf("answer x1 = %g\n ",x1);
			loop = newton_raphson(a,b,c,0.0000001,-100.123,&x2);
			if (fabs(x1-x2)>0.00001)
			printf("answer x2 = %g\n",x2);	
		}
		do
		{
			printf("Enter y to calculate again or n to exit");
			scanf(" %c",&ch);
		}while(ch!='n'&&ch!='y');
	}while(ch!='n');
	return 0;	
}




