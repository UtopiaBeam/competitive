#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#define PDI pair<double,int>
using namespace std;
vector <double> adj[30][30];
vector <int> ans;
priority_queue <PDI> q;
double dp[30],d[30][30];
int mark[30],pre[30];
int in(char ch){
    if(ch=='X')     return 0;
    if(ch=='Y')     return 27;
    return ch-'a'+1;
}
char re(int num){
    if(num==0)      return 'X';
    if(num==27)     return 'Y';
    return num+'a'-1;
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        char str,end;
        double w;
        scanf(" %c %c %lf",&str,&end,&w);
        int from=in(str),to=in(end);
        adj[from][to].push_back(w),adj[to][from].push_back(w);
    }
    for(int i=0;i<28;i++)
        for(int j=0;j<28;j++){
            int size=adj[i][j].size();
            if(!size)   continue;
            sort(adj[i][j].begin(),adj[i][j].end());
            if(size%2)      d[i][j]=adj[i][j][size/2];
            else    d[i][j]=(adj[i][j][size/2-1]+adj[i][j][size/2])/2;
        }
    for(int i=0;i<28;i++)
        dp[i]=10000000000;
    q.push(PDI(0.0,0));
    while(!q.empty()){
        double w=(q.top()).first*(-1);
        int now=(q.top()).second;
        q.pop();
        if(!mark[now]){
            mark[now]=1,dp[now]=w;
            for(int i=0;i<28;i++){
                if(!mark[i] && d[now][i] && dp[i]>dp[now]+d[now][i])
                    q.push(PDI((-1)*(dp[now]+d[now][i]),i)),pre[i]=now;
            }
        }
    }
    if(dp[27]==10000000000){
        printf("broken\n");     return 0;
    }
    int now=27;
    while(1){
        ans.push_back(now);
        if(pre[now]==now)   break;
        now=pre[now];
    }
    for(int i=ans.size()-1;i>0;i--){
        int str=ans[i],end=ans[i-1];
        printf("%c %c %.1lf\n",re(str),re(end),d[str][end]);
    }
    printf("%.1lf\n",dp[27]);
    return 0;
}
