#include<stdio.h>
int main(){
    int n,i,j,num[1050],temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&num[i]);
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
            if(num[j]>num[j+1])
                temp=num[j],num[j]=num[j+1],num[j+1]=temp;
    if(!num[0]){
        for(i=0;i<n;i++)
            if(num[i]){
                temp=num[0],num[0]=num[i],num[i]=temp;
                break;
            }
    }
    for(i=0;i<n;i++)
        printf("%d",num[i]);
    printf("\n");
    return 0;
}
