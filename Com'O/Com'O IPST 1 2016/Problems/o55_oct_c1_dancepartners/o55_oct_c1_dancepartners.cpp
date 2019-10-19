#include<cstdio>
#include<queue>
#include<algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
priority_queue<P> q_tall,q_short;
int n,nw=0;
int a[100002],h[100002],b[100002],k[100002],ans=0,ht,kt;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",h+i,a+i);
    for(int i=0;i<n;i++){
        scanf("%d %d",k+i,b+i);
        q_tall.push(P(b[i]-k[i],k[i]));
    }
    for(int i=0;i<n;i++){
        while(nw<n && h[i]>k[nw]){
            q_short.push(P(b[nw]+k[nw],k[nw]));
            nw++;
        }
        while(!q_tall.empty() && q_tall.top().S<h[i])
            q_tall.pop();
        if(q_short.empty())     ht=-1<<30;
        else        ht=q_short.top().F;
        if(q_tall.empty())      kt=-1<<30;
        else        kt=q_tall.top().F;
        ans=max(a[i]-h[i]+ht,a[i]+h[i]+kt);
        printf("%d\n",ans);
    }
    return 0;
}
