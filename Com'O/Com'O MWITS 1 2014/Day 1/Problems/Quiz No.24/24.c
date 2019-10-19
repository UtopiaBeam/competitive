#include<stdio.h>
int main(){
    int i,sum,cnt=0;
    for(i=50;i<=500;i++){
        sum=i%10+(i/10)%10+i/100;
        if(sum==5)  cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
