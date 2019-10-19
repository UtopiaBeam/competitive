#include<stdio.h>
#include<stdlib.h>
#define n 100000000
int a[100000010];
int main(){
    int i;
    for(i=0;i<n;i++)
        a[i]=rand()%100000000;
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
    return 0;
}
