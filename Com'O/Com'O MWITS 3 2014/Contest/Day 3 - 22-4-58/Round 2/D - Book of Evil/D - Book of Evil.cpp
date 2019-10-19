#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector <int> adj[100005];
int n,m,k,s,e,a[100005];
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        scanf("%d %d",&s,&e);
        adj[s].push_back(e),adj[e].push_back(s);
    }
    return 0;
}
