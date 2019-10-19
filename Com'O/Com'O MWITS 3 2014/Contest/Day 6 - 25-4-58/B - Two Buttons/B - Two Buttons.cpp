#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
int n,m,cnt=0,d[20005],mark[20005];
typedef pair<int,int> PII;
priority_queue <PII> q;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=2e4;i++)
        d[i]=1<<20;
    q.push(PII(0,n));
    while(!q.empty()){
        int now=q.top().second,dis=-1*q.top().first;
        q.pop();
        if(!mark[now]){
            mark[now]=1,d[now]=dis;
            if(now-1>0 && d[now-1]>dis+1)     q.push(PII(-dis-1,now-1));
            if(2*now<=20000 && d[2*now]>dis+1)  q.push(PII(-dis-1,2*now));
        }
    }
    printf("%d\n",d[m]);
    return 0;
}
