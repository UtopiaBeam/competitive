#include<cstdio>
#include<vector>
using namespace std;
vector <int> adj[10005];
int in[10005],out[10005],n,m,u,v;
void dfs(int now){

}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&m,&u);
        while(m--){
            scanf("%d",&v);
            adj[u].push_back(v);
            in[v]++,out[u]++;
            u=v;
        }
    }
    u=1;
    for(int i=1,chk=0;i<=10000;i++)
        if(in[i]-out[i]==1 || out[i]-in[i]==1){
            if(!chk)     u=i;
            else if(chk==2){
                printf("0\n");  return 0;
            }
            chk++;
        }
    dfs(u);
    return 0;
}
