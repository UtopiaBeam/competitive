#include<stdio.h>
int a[1010],b[1010],path[1010],ans[1010],max=-(-1u/2),index;
int main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        b[i]=1;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=2;i<=n;i++)
        for(j=1;j<i;j++)
            if(a[j]<a[i] && b[j]+1>b[i]){
                b[i]=b[j]+1;
                path[i]=j;
            }
    for(i=1;i<=n;i++)
        if(max<b[i]){
            max=b[i];   index=i;
        }
    for(i=max;i>0;i--){
        ans[i]=a[index];
        index=path[index];
    }
    printf("%d\n",max);
    for(i=1;i<=max;i++)
        printf((i!=max)? "%d ":"%d\n",ans[i]);
    return 0;
}
