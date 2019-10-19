#include<cstdio>
int a,b,c;
int gcd(int a,int b){
    if(b==0)    return a;
    if(a%b)     return gcd(b,a%b);
    return b;
}
int main(){
    scanf("%d %d %d",&a,&b,&c);
    if(c%gcd(a,b))  printf("No\n");
    else    printf("Yes\n");
    return 0;
}
