#include<cstdio>
#include<stack>
#include<algorithm>
using namespace std;
struct S{
    int s,e,v;
};
S a[100002];
int n,dp[100002],p[100002];
stack<int> st;
int bs(int s,int e,int k){
    if(s==e)    return s;
    int m=(s+e+1)/2;
    if(a[m].e<=k)    return bs(m,e,k);
    return bs(s,m-1,k);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d %d",&a[i].s,&a[i].e,&a[i].v);
    //a is sorted by end time
    for(int i=1;i<=n;i++)
        p[i]=bs(0,i-1,a[i].s);
    for(int i=1;i<=n;i++)
        dp[i]=max(dp[i-1],dp[p[i]]+a[i].v);
    printf("%d\n",dp[n]);
    for(int i=n;i;){
        if(dp[i-1]<=dp[p[i]]+a[i].v){
            st.push(i);
            i=p[i];
        }
        else    i--;
    }
    printf("%d\n",st.size());
    while(!st.empty()){
        printf("%d ",st.top());
        st.pop();
    }
    return 0;
}
