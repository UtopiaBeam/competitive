#include<stdio.h>
#include<stdlib.h>
char a[100010];
int cmp(const void *a,const void *b){
    return *(char *)a - *(char *)b;
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf(" %c",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    for(i=0;i<n;i++)
        printf((i!=n-1)? "%c ":"%c\n",a[i]);
    return 0;
}
