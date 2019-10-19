#include<stdio.h>
#include<stdlib.h>
int a[100010],b[100010],ans=0;
int cmp(const void *a,const void *b){
    return *(int *)a - *(int *)b;
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(i=0;i<n;i++)
        scanf("%d",&b[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    qsort(b,n,sizeof(b[0]),cmp);
    for(i=0;i<n;i++)
        ans+=a[i]*b[n-1-i];
    printf("%d\n",ans);
    return 0;
}
