#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
priority_queue<int> q;
vector<int> g[50002],tp;
int n,m,s,e,d[50002];
int main(){
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d %d",&s,&e);
        g[e].push_back(s);
        d[s]++;
    }
    for(int i=1;i<=n;i++)
        if(!d[i])   q.push(-i);
    while(!q.empty()){
        s=-q.top();
        q.pop();
        tp.push_back(s);
        for(int i=0;i<g[s].size();i++){
            e=g[s][i];
            d[e]--;
            if(!d[e])   q.push(-e);
        }
    }
    if(tp.size()<n){
        printf("Never\n");
        return 0;
    }
    for(int i=tp.size()-2;i>=0;i--){
        s=tp[i],e=tp[i+1];
        int chk=1;
        for(int j=0;j<g[s].size() && chk;j++)
            if(g[s][j]==e)    chk=0;
        if(chk){
            swap(tp[i],tp[i+1]);
            printf("Different\n");
            for(int j=0;j<tp.size();j++)
                printf("%d ",tp[j]);
            return 0;
        }
    }
    printf("Same\n");
    for(int i=0;i<tp.size();i++)
        printf("%d ",tp[i]);
    return 0;
}
