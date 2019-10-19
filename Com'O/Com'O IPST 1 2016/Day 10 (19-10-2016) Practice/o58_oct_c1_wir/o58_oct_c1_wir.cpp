#include<cstdio>
#include<stack>
#include<vector>
#include<map>
#include<algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
stack<int> s;
map<int,int> mp;
map<int,int>::iterator it;
vector<P> v;
int n,m,a[100002],mx[100002];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<n;i++){
        while(!s.empty() && a[i]<=a[s.top()])
            s.pop();
        if(s.empty())       s.push(i),mx[i]=0;
        else{
            mx[i]=max(mx[s.top()],a[i]-a[s.top()]);
            mp[mx[i]-1]++;
            s.push(i);
        }
    }
    for(int i=0;i<m;i++){
        scanf("%d",a+i);
        if(!mp[a[i]])   mp[a[i]]=0;
    }
    for(it=mp.begin();it!=mp.end();it++)
        v.push_back(*it);
    for(int i=v.size()-2;i>=0;i--)
        v[i].S+=v[i+1].S;
    for(int i=0;i<v.size();i++)
        mp[v[i].F]=v[i].S;
    for(int i=0;i<m;i++)
        printf("%d\n",mp[a[i]]);
    return 0;
}
