#include<stdio.h>
int a[30]={1,2};
int main(){
    int n,i;
    for(i=2;i<=25;i++)
        a[i]=a[i-1]+a[i-2]+1;
    while(1){
        scanf("%d",&n);
        if(n==-1)   break;
        printf("%d %d\n",a[n],a[n+1]);
    }
    return 0;
}
