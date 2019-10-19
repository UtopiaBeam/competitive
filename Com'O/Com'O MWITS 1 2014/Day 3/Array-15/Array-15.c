#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char a[5][30];
int cmp(const void *a,const void *b){
    return strcmp(a,b);
}
int main(){
    int i;
    for(i=0;i<3;i++)
        scanf(" %s",a[i]);
    qsort(a,3,sizeof(a[0]),cmp);
    for(i=0;i<3;i++)
        printf("%s\n",a[i]);
    return 0;
}
