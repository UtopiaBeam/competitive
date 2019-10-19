#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class P{
public:
    int s,e,w;
}tmp;
vector<P> edge;
int n,m,a,b,t,k,x,y,d[1002];
int main(){
    cin >> n >> m;
    cin >> x >> y;
    cin >> a >> b >> t >> k;
    tmp.s=a,tmp.e=b,tmp.w=t;
    edge.push_back(tmp);
    for(int i=0;i<n;i++)   d[i]=1e9;
    d[x]=0;
    while(m--){
        cin >> tmp.s >> tmp.e >> tmp.w;
        edge.push_back(tmp);
    }
    while(--n)
        for(int i=0;i<edge.size();i++){
            if(edge[i].s==a && edge[i].e==b && d[edge[i].s]>k)     continue;
            if(d[edge[i].s]!=1e9)   d[edge[i].e]=min(d[edge[i].e],d[edge[i].s]+edge[i].w);
        }
    cout << d[y] << endl;
    return 0;
}
