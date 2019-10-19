#include<stdio.h>
int a[10],max=-1<<20;
int main(){
    int i,in=0;
    for(i=0;i<10;i++){
        scanf("%d",&a[i]);
        if(max<a[i])
            max=a[i],in=i;
    }
    printf("%d\n",in);
    return 0;
}
