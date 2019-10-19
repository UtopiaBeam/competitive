#include<stdio.h>
int gcd(int a,int b){
    if(b==0)    return a;
    if(a%b)     return gcd(b,a%b);
    return b;
}
int main(){
    int p,q,angle,prob,now_gcd;
    scanf("%d %d",&p,&q);
    scanf("%d",&angle);
    now_gcd=angle;
    while(--p){
        scanf("%d",&angle);
        now_gcd=gcd(now_gcd,angle);
    }
    now_gcd=gcd(now_gcd,360);
    while(q--){
        scanf("%d",&prob);
        if(prob%now_gcd)    printf("NO\n");
        else    printf("YES\n");
    }
    return 0;
}
