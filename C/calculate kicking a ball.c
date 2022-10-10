#include <stdio.h>
#include <math.h>
int main()
{
	double deg,s,u,g,sx,sy,tx,ty,deltax,rad,Pi=3.14;
	g=-9.81;
	char ch,p;
	printf("Hello!! This is a program to calculate kicking a ball\n" );
do
{ 
	printf("Input velocity : ");
	while(scanf("%lf%c",&u,&p)==0 || p!='\n'){
		rewind(stdin);
		printf("Input again :");
	}
	printf("Input zeta : ");
	while(scanf("%lf%c",&deg,&p)==0 || p!='\n'){
		rewind(stdin);
		printf("Input again :");
	}
	printf("Input distance : ");
	while(scanf("%lf%c",&s,&p)==0 || p!='\n'){
		rewind(stdin);
		printf("Input again :");
	}
    rad=(deg*Pi)/180;
    tx=(s/(u*cos(rad)));
    ty=-(2*u*sin(rad))/g;
    sy=((u*sin(rad))*(tx))+((0.5*g)*(tx)*(tx));
    sx=-(u*u)*(sin(2*rad))/g;
    deltax=s-sx;
    
    if (sx<s){
	
    printf("ToT Fail bail\nThe distance the ball falls before the goal %.2lf m\nTake time%.2lf sec\n",deltax,ty); 
}
	else if (sy>=2.44){
	
	printf("ToT Overshoot\nThe distance the ball falls before the goal %.2lf m\nTake time%.2lf sec\n",sy,tx);
}
	else if (tx>0.5){
	
	printf("ToT Save ball!\nThe distance the ball falls before the goal %.2lf m\nTake time%.2lf sec\n,",sy,tx);
}
	else {
	printf("Goal! \\^o^/\nThe distance the ball falls before the goal %.2lf m\nTake time%.2lf sec \n",sy,tx);
}

	do{
     // printf("Test\nrad%lf\ntx%lf\nty%lf\nsy%lf\nsx%lf\ndeltax=%lf\n",rad,tx,ty,sy,sx,deltax);//Test
			printf("Enter y to this a random number program >< again or Enter n to end program : ");
			scanf(" %c",&ch);
		}
		while (ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
		}while (ch=='y'||ch=='Y');

}

