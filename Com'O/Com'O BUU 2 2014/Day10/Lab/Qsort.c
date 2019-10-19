#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 100000000
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int a[100000010];
int main(){
    int i;
    clock_t str;
    double timing;
    str=clock();
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    str=clock()-str;
    printf("%lf\n",(double)str/CLOCKS_PER_SEC);
    return 0;
}
