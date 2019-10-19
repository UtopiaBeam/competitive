#include<stdio.h>
#include<time.h>
#define n 100000000
int a[n];
int part(int left,int right){
    int p=a[left],i=left,j=right+1,t;
    while(i<j){
        while(a[--j]>p) ;
        while(a[++i]<p){
            if(i==right)
                break;
        }
        if(i<j)
            t=i,i=j,j=i;
    }
    return j;
}
void qsort(int left,int right){
    int j;
    if(left<right){
        j=part(left,right);
        qsort(left,j-1);    qsort(j+1,right);
    }
}
int main(){
    int i;
    clock_t str;
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    str=clock();
    qsort(0,n-1);
    str=clock()-str;
    printf("%lf\n",(double)str/CLOCKS_PER_SEC);
    return 0;
}
