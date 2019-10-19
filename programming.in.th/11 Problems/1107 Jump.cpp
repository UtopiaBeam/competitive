#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,p,k,a[1000002],dp[1000002],mn=1<<30,mx=0;
vector<int> v;
bool chk(int m){
    v.clear();
    v.push_back(0);
    for(int i=1;i<=n;i++)
        if(a[i]>m)  v.push_back(i);
    int s=0;
    for(int i=1;i<v.size();i++){
        while(s<=i && v[i]-v[s]+1>p)    s++;
        dp[i]=dp[s-1]+1;
    }
    return dp[v.size()-1]<=k;
}
int bs(int s,int e){
    if(s==e)    return s;
    int m=(s+e)/2;
    if(chk(m))      return bs(s,m);
    return bs(m+1,e);
}
int main(){
    scanf("%d %d %d",&n,&k,&p);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
    }
    printf("%d\n",bs(mn,mx));
    return 0;
}
