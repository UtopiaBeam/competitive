#include<stdio.h>
int gcd(int a,int b){
    if(a%b==0)      return b;
    return gcd(b,a%b);
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    if(gcd(a,b)==1)     printf("Yes\n");
    else    printf("No\n");
    return 0;
}
