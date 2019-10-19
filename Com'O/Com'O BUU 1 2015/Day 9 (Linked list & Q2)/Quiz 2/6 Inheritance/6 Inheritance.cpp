#include<cstdio>
int a[10],chp=1;
int main(){
    int n;
    scanf("%d",&n);
    if(n<=0){
        printf("-1\n");     return 0;
    }
    if(n==1){
        printf("1\n");      return 0;
    }
    for(int i=9;i>1;i--)
        while(n>1 && n%i==0)  a[i]++,n/=i,chp=0;
    if(chp || n>1)     printf("-1\n");
    else for(int i=2;i<10;i++)
        while(a[i]--)   printf("%d",i);
    return 0;
}
