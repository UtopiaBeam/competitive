#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int v[20002],dp[20002],n,m,s,e,d[20002],mx=0;
stack<int> st;
vector<int> g[20002],tp;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&v[i]);
        dp[i]=v[i];
    }
    while(m--){
        scanf("%d %d",&s,&e);
        g[e].push_back(s);
        d[s]++;
    }
    for(int i=1;i<=n;i++)
        if(!d[i])   st.push(i);
    while(!st.empty()){
        s=st.top();
        st.pop();
        tp.push_back(s);
        for(int i=0;i<g[s].size();i++){
            d[g[s][i]]--;
            if(!d[g[s][i]])     st.push(g[s][i]);
        }
    }
    for(int i=0;i<tp.size();i++){
        s=tp[i];
        for(int j=0;j<g[s].size();j++){
            e=g[s][j];
            dp[e]=max(dp[e],dp[s]+v[e]);
        }
    }
    for(int i=1;i<=n;i++)
        if(dp[mx]<dp[i])    mx=i;
    printf("%d %d\n",mx,dp[mx]);
    return 0;
}
