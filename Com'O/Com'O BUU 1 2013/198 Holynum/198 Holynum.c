#include<stdio.h>
int main(){
    long long num;
    int k,i;
    scanf("%lld %d",&num,&k);
    for(i=0;i<k-1;i++)
        num/=10;
    if(num%10>=5){
        num/=10,num++;
    }
    else    num/=10;
    for(i=0;i<k;i++)
        num*=10;
    printf("%lld\n",num);
    return 0;
}
