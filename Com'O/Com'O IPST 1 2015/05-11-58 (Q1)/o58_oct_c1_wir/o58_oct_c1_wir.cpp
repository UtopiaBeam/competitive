#include<cstdio>
#include<stack>
#include<vector>
#include<map>
#include<algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int n,m,h[100002],mx[100002];
stack<int> S;
vector<P> V;
map<int,int> M;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&h[i]);
    for(int i=0;i<n;i++){
        while(!S.empty() && h[S.top()]>=h[i])
            S.pop();
        if(S.empty())   S.push(i),mx[i]=0;
        else{
            mx[i]=max(h[i]-h[S.top()],mx[S.top()]);
            M[mx[i]-1]++;
            S.push(i);
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d",&h[i]);
        if(!M[h[i]])    M[h[i]]=0;
    }
    for(map<int,int>::iterator it=M.begin();it!=M.end();it++)
        V.push_back(*it);
    for(int i=V.size()-2;i>=0;i--)
        V[i].S+=V[i+1].S;
    for(int i=0;i<V.size();i++)
        M[V[i].F]=V[i].S;
    for(int i=0;i<m;i++)
        printf("%d\n",M[h[i]]);
    return 0;
}
