#include<cstdio>
#include<algorithm>
int a[1002],n,m,s,p;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    while(m--){
        scanf("%d %d",&s,&p);
        for(int i=0;i<p/2;i++)
            std::swap(a[(s-1+i+n)%n],a[(s-2+p-i+n)%n]);
    }
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
