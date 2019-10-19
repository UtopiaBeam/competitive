#include<stdio.h>
int main(){
    int m,n,a,i,j,max;
    scanf("%d %d",&m,&n);
    for(i=0;i<m;i++){
        for(j=0,max=-1<<20;j<n;j++){
            scanf("%d",&a);
            if(max<a)   max=a;
        }
        printf("%d\n",max);
    }
    return 0;
}
