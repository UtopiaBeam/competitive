#include<stdio.h>
#include<time.h>
#define n 1000000
int a[100000010];
int main(){
    int i,j,t;
    clock_t str,stp;
    str=clock();
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=n;i>0;i--)
        for(j=0;j<i;j++)
            if(a[j]>a[j+1])
                t=a[j],a[j]=a[j+1],a[j+1]=t;
    str=clock()-str;
    printf("%lf\n",(double)str/CLOCKS_PER_SEC);

}
