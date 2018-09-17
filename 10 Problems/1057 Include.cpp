#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
vector <int> adj[1010];
queue <int> q;
int mark[1010];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        while(k--){
            int a;
            scanf("%d",&a);
            adj[i].push_back(a);
        }
    }
    for(int i=1;i<=n;i++){
        memset(mark,0,sizeof(mark));
        int chk=1;
        q.push(i);
        while(!q.empty()){
            int now=q.front();
            q.pop();
            if(mark[now]==1){
                printf("YES\n");     chk=0;
                while(!q.empty())    q.pop();
            }
            else{
                mark[now]=1;
                for(int j=0;j<(int)adj[now].size();j++)
                    q.push(adj[now][j]);
            }
        }
        if(chk)     printf("NO\n");
    }
    return 0;
}
