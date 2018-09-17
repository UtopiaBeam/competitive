#include<stdio.h>
int gcd(int a,int b){
    if(a%b)     return gcd(b,a%b);
    return b;
}
int main(){
    int r,g,GCD;
    scanf("%d %d",&r,&g);
    GCD=gcd(r,g);
    for(int i=GCD;i>0;i--){
        if(GCD%i==0){
            int t=GCD/i;
            printf("%d %d %d\n",t,r/t,g/t);
        }
    }
    return 0;
}
