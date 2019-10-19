#include<stdio.h>
int main(){
    int max=-1<<20,n,i;
    for(i=0;i<3;i++){
        scanf("%d",&n);
        if(max<n)   max=n;
    }
    printf("%d\n",max);
    return 0;
}
