#include<stdio.h>
#include<stdlib.h>
int x[100010],y[100010];
int cmp(const void* a,const void* b){
    return *(int *)a - *(int *)b;
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&x[i],&y[i]);
        qsort(x,i,sizeof(x[0]),cmp);
        qsort(y,i,sizeof(y[0]),cmp);
    }
}
