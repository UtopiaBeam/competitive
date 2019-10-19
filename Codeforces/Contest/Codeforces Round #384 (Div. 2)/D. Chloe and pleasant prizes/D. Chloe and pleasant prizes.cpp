#include<cstdio>
#include<vector>
#include<algorithm>
#define N 200002
#define L long long
using namespace std;
vector<int> g[N];
bool chk=true,mk[N];
L a[N],sum[N],mx=(L)(-1)<<60,mxsum[N];
int n,x,y;
void dfs(int u){
    if(mk[u])   return ;
    vector<L> tmp;
    int cnt=0;
    mk[u]=true;
    sum[u]=a[u];
    for(int v:g[u]){
        if(mk[v])       continue;
        cnt++;
        dfs(v);
        sum[u]+=sum[v];
        tmp.push_back(-mxsum[v]);
        mxsum[u]=max(mxsum[u],mxsum[v]);
    }
    if(cnt>1)       chk=false;
    mxsum[u]=max(mxsum[u],sum[u]);
    if(tmp.size()<2){
        return ;
    }
    sort(tmp.begin(),tmp.end());
    mx=max(mx,-tmp[0]-tmp[1]);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%I64d",a+i);
        mxsum[i]=(L)(-1)<<60;
    }
    for(int i=1;i<n;i++){
        scanf("%d %d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    if(chk)     printf("Impossible\n");
    else        printf("%I64d\n",mx);
    return 0;
}
