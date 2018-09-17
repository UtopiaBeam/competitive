#include<stdio.h>

int main(){
    int a[15],sum=-100;
    int i,j;
    for(i=0;i<9;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    for(i=0;i<9;i++)
        for(j=i+1;j<9;j++)
            if(a[i]+a[j]==sum)
                a[i]=0,a[j]=0;
    for(i=0;i<9;i++)
        if(a[i])    printf("%d\n",a[i]);
    return 0;
}
