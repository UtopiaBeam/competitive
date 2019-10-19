#include<cstdio>
#include<queue>
#include<cstring>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
queue<P> q;
int n,cnt,d[1002];
int main(){
    scanf("%d",&n);
    q.push(P(n,0));
    memset(d,-1,sizeof(d));
    while(!q.empty()){
        n=q.front().F,cnt=q.front().S;
        q.pop();
        if(n<1 || d[n]>=0 && d[n]<=cnt)   continue;
        d[n]=cnt;
        int t=n,a[10]={};
        while(t)    a[t%10]=1,t/=10;
        for(int i=2;i<=5;i++)
            if(!a[i] && n%i) q.push(P(n-i,cnt+1));
    }
    printf("%d\n",d[1]);
    return 0;
}
