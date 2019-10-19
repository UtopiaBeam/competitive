#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v[200002];
int n,m,k,x,y,ans=0;
int c[200002],r[200002],cnt[200002];
int fr(int x){
    if(x!=r[x])     r[x]=fr(r[x]);
    return r[x];
}
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",c+i);
        r[i]=i;
    }
    while(m--){
        scanf("%d %d",&x,&y);
        r[fr(x)]=fr(y);
    }
    for(int i=1;i<=n;i++)
        v[fr(i)].push_back(i);
    for(int i=1;i<=n;i++){
        if(v[i].empty())    continue;
        for(int j=1;j<=k;j++)
            cnt[j]=0;
        int mx=0;
        for(int j=0;j<v[i].size();j++)
            mx=max(mx,++cnt[c[v[i][j]]]);
        ans+=v[i].size()-mx;
    }
    printf("%d\n",ans);
    return 0;
}
