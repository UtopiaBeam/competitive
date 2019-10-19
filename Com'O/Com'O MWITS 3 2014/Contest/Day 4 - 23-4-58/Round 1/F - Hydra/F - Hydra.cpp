#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
pair<int,int> deg[100005];
vector <int> adj[100005];
int n,m,h,t,a[100005];
int bs(int s,int e){
    if(s>e)     return -1;
    int mid=(s+e)/2;
    if(deg[mid].first==h+1)     return deg[mid].second;
    if(h+1<deg[mid].first)      return bs(s,mid);
    return bs(mid+1,e);
}
int main(){
    scanf("%d %d %d %d",&n,&m,&h,&t);
    for(int i=1;i<=n;i++)
        deg[i]=make_pair(0,i);
    while(m--){
        int s,e;
        scanf("%d %d",&s,&e);
        adj[s].push_back(e),adj[e].push_back(s);
        deg[s].first++,deg[e].first++;
        a[s]++,a[e]++;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");
    sort(deg+1,deg+n+1);
    int c1=bs(1,n),c2=-1;
    for(int i=1;i<=n;i++)
        printf("(%d,%d) ",deg[i].second,deg[i].first);
    printf("\n");
    if(c1<0)    printf("NO\n");
    else{
        for(int i=0;i<adj[c1].size();i++)
            if(a[adj[c1][i]]==t+1){
                c2=adj[c1][i];      break;
            }
        if(c2<0)    printf("NO\n");
        else{
            printf("YES\n%d %d\n",c1,c2);
            for(int i=0;i<adj[c1].size();i++)
                if(adj[c1][i]!=c2)  printf("%d ",adj[c1][i]);
            printf("\n");
            for(int i=0;i<adj[c2].size();i++)
                if(adj[c2][i]!=c1)  printf("%d ",adj[c2][i]);
            printf("\n");
        }
    }
    return 0;
}
