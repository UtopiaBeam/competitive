#include<stdio.h>
#include<stdlib.h>
int a[100010];
int cmp(const void *a,const void *b){
    return *(int *)a - *(int *)b;
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    for(i=0;i<n;i++)
        printf((i!=n-1)? "%d ":"%d\n",a[i]);
    return 0;
}
