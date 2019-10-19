#include<cstdio>
int n,m,mn[102],a,b;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)   mn[i]=(int)1e9;
    while(m--){
        scanf("%d %d",&a,&b);
        if(mn[a]>b) mn[a]=b;
    }
    m=0;
    for(int i=1;i<=n;i++)   m+=mn[i];
    printf("%d\n",m);
    for(int i=1;i<=n;i++)   printf("%d %d\n",i,mn[i]);
    return 0;
}
