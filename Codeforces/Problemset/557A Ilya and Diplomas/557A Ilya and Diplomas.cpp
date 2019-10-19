#include<cstdio>
int n,mx[3],mn[3],a[3];
int main(){
    scanf("%d",&n);
    for(int i=0;i<3;i++){
        scanf("%d %d",&mn[i],&mx[i]);
        a[i]+=mn[i],n-=mn[i];
    }
    for(int i=0;i<3 && n;i++)
        if(n>=mx[i]-mn[i])    a[i]=mx[i],n-=mx[i]-mn[i];
        else        a[i]+=n,n=0;
    for(int i=0;i<3;i++)
        printf("%d ",a[i]);
    return 0;
}
