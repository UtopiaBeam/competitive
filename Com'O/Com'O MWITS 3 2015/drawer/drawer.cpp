#include<cstdio>
int n,m,s,e,r[300002],cnt[300002];
int find(int u){
    if(r[u]!=u)     r[u]=find(r[u]);
    return r[u];
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        r[i]=i;     cnt[i]=1;
    }
    while(n--){
        scanf("%d %d",&s,&e);
        int rs=find(s),re=find(e);
        if(cnt[rs]){
            printf("drawer\n");
            cnt[rs]--;
        }
        else if(cnt[re]){
            printf("drawer\n");
            cnt[re]--;
        }
        else{
            printf("trash\n");
            continue;
        }
        cnt[rs]+=cnt[re];
        r[re]=rs;
    }
    return 0;
}
