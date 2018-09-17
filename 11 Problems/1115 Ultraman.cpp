#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
class node{
public:
    int str,end,cost;
};
class cmp{
public:
    bool operator()(node x,node y){
        return x.cost > y.cost;
    }
};
vector <int> w;
priority_queue <node,vector<node>,cmp> q;
typedef pair<int,int> PII;
PII a[1005];
int n,k,root[1005];
int dis(int x,int y){
    return (a[x].first-a[y].first)*(a[x].first-a[y].first)+(a[x].second-a[y].second)*(a[x].second-a[y].second);
}
int find(int now){
    if(root[now]!=now)
        root[now]=find(root[now]);
    return root[now];
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d %d",&a[i].first,&a[i].second);
    for(int i=0;i<n;i++){
        root[i]=i;
        for(int j=i+1;j<n;j++){
            node tmp;
            tmp.str=i,tmp.end=j,tmp.cost=dis(i,j);
            q.push(tmp);
        }
    }
    while(!q.empty()){
        node tmp=q.top();
        q.pop();
        int roots=find(tmp.str),roote=find(tmp.end);
        if(roots!=roote){
            root[roots]=roote;
            w.push_back(tmp.cost);
        }
    }
    printf("%d\n",w[w.size()-k]);
    return 0;
}
