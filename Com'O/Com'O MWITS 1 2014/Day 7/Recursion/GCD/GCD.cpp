#include<stdio.h>
int gcd(int a,int b){
    if(a%b)     return gcd(b,a%b);
    return b;
}
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",gcd(a,b));
    return 0;
}
