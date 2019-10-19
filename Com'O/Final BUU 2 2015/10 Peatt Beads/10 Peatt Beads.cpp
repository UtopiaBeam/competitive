#include<cstdio>
int n,s,e,r[300002],f[300002],b[300002];
int find(int u){
    if(u!=r[u])     r[u]=find(r[u]);
    return r[u];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        r[i]=i;
    for(int i=1;i<n;i++){
        scanf("%d %d",&s,&e);
        int rs=find(s);
        f[s]=e;
        b[rs]=b[e];
        f[b[e]]=rs;
        if(b[e]==0) r[e]=rs;
        else    r[rs]=find(e);
        b[e]=s;
    }
    for(int i=1;i<=n;i++)
        if(!f[i]){
            s=i;    break;
        }
    while(s){
        printf("%d ",s);
        s=b[s];
    }
    return 0;
}
