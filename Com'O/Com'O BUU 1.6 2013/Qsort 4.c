#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[100010][100];
int cmp(const void* a,const void *b){
    return strcmp(a,b);
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf(" %s",&a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    for(i=0;i<n;i++)
        printf((i!=n-1)? "%s ":"%s\n",a[i]);
    return 0;
}
