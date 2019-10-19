#include<stdio.h>
int main(){
    int i,cnt=0;
    for(i=1;i<=1000;i++)
        if(i%10==9) cnt++;
    printf("%d\n",cnt);
    return 0;
}
