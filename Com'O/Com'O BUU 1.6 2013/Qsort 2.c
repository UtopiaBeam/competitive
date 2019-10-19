#include<stdio.h>
#include<stdlib.h>
double a[100010];
int cmp(const void *a,const void *b){
    if(*(double *)a > *(double *)b) return 1;
    return -1;
}
int main(){
    int n.i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    for(i=0;i<n;i++)
        printf((i!=n-1)? "%lf ":"%lf\n",a[i]);
    return 0;
}
