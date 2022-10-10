#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main ()
{

	int x,y,count;
	char name[30],ch;
	printf("This a random number program ><");
	printf("Input your name :");
	scanf("%s",&name);
	printf("Sawaddee %s\n",name);
	do{
	srand(time(NULL));
	x = rand() %100 +1;
	count  = 0;
	printf("%d\n",x);
				do{
					count = count+1;
					printf("%d, Input your number\n",count);
					scanf("%d",&y);
					if(x==y){
						printf("Hulee! Your answer is correct\n ");	
					}
					else if(y>x){
						printf("Hmm.. Your answer is too much\n");
					}
					else{
						printf("Hmm.. Your answer is too low\n");
					}
					if(count==7&&x!=y){
						printf("You are the loser!! , The correct anser is : %d\n",x);
					}	
				}
				while (x!=y&&count!=7);
		do{
			printf("Enter y to this a random number program >< again or Enter n to end program : ");
			scanf(" %c",&ch);
		}
		while (ch!='y'&&ch!='Y'&&ch!='n'&&ch!='N');
		}while (ch=='y'||ch=='Y');
}
