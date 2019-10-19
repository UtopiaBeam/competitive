#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char str[100010][150];
int cmp(const void *a,const void *b){
    return strcmp(a,b);
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf(" %s",str[i]);
    qsort(str,n,sizeof(str[0]),cmp);
    for(i=0;i<n;i++)
        printf("%s\n",str[i]);
    return 0;
}
