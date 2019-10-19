#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> edge;
vector <edge> adj;
long long cnt[1000010],base[1000010]={1},ans=0;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=1000000;i++)
        base[i]=base[i-1]*37;
    for(int i=0;i<m;i++){
        int str,end;
        scanf("%d %d",&str,&end);
        adj.push_back(edge(str,end));
        cnt[str]+=base[end],cnt[end]+=base[str];
    }
    for(int i=0;i<m;i++)
        if(cnt[adj[i].first]-base[adj[i].second]==cnt[adj[i].second]-base[adj[i].first])
            ans++;
    sort(cnt+1,cnt+n+1);
    long long count=1;
    for(int i=2;i<=n+1;i++)
        if(i<=n && cnt[i]==cnt[i-1])
            count++;
        else    ans+=(count*(count-1))/2,count=1;
    printf("%I64d\n",ans);
    return 0;
}
