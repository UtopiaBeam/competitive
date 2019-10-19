#include<stdio.h>
int coin[12],a[1000010];
int main(){
    int i,j,n,m;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&coin[i]);
        a[coin[i]]=1;
    }
    for(i=coin[0];i<=m;i++)
        for(j=0;j<n;j++)
            if(a[i+coin[j]]==0||a[i]+1<a[i+coin[j]])
                a[i+coin[j]]=a[i]+1;
    printf("%d\n",a[m]);
    return 0;
}
