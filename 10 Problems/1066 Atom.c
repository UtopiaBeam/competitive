#include<stdio.h>
#include<stdlib.h>
int a[1010];
int main(){
    int n,i,j,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    while(n>1){
        int max=-10,str=0;
        for(i=0;i<n-1;i++)
            if(abs(a[i]-a[i+1])>max)
                max=abs(a[i]-a[i+1]),str=i;
        for(i=str;i<n-2;i++)
            a[i]=a[i+2];
        n-=2,ans+=max;
    }
    printf("%d\n",ans);
    return 0;
}
