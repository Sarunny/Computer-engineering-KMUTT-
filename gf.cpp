#include <stdio.h>
#include <math.h>
int main(){
    float n=0,ans=0,ans1=0,ans2=0;
    int b=0,count = 1,i = 0;
    scanf("%f",&ans);
    ans2 = log(ans)/log(2);
    i = floor(ans2);
    ans1 = ans/pow(2,i);
    printf("%f %d %f\n",ans2,i,ans1);
    if(ans1 > 1)
        ans1--;
    while (ans1 != 1 && count != 52)
    {
    ans1 = ans1*2;
    //printf("%f\n",ans);
    if(ans1 > 1){
        b=1;
        ans1--;
    }
    else if(ans1<1)
        b=0;
    printf("%d",b);
    count++;
    }
}
