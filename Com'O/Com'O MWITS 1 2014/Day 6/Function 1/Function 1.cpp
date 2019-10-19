#include<stdio.h>
int in=0;
int isprime(int n){
    for(int i=2;i*i<=n;i++)
        if(n%i==0)  return 0;
    return 1;
}
void genprime(int n,int a[]){
    for(int i=2;i<=n;i++)
        if(isprime(i))  a[in++]=i;
}
int main(){
    int n,a[10010];
    scanf("%d",&n);
    genprime(n,a);
    for(n=0;n<in;n++)
        printf("%d ",a[n]);
    printf("\n");
    return 0;
}
