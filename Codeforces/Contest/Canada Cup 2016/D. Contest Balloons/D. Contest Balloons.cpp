#include<cstdio>
#include<queue>
#include<algorithm>
#define L long long
#define P pair<L,L>
#define F first
#define S second
using namespace std;
int n,nw=1,mn=0,cnt=1;
priority_queue<L> q;
L t,w;
P a[300002];
int main(){
    scanf("%d",&n);
    scanf("%I64d %I64d",&t,&w);
    n--;
    for(int i=1;i<=n;i++){
        scanf("%I64d %I64d",&a[i].F,&a[i].S);
        a[i].S=a[i].S-a[i].F+1;
        a[i].F*=-1;
    }
    sort(a+1,a+n+1);
//    for(int i=1;i<=n;i++)
//        printf("%I64d %I64d\n",-a[i].F,a[i].S);
    for(int i=1;i<=n;i++){
        if(-a[i].F<=t){
            nw=i;   break;
        }
        q.push(-a[i].S);
    }
//    printf("%d\n",nw);
    mn=cnt=nw;
    while(t>0 && !q.empty()){
        if(-q.top()<=t){
            t+=q.top();
            q.pop();
            cnt--;
        }
        else    break;
        while(nw<=n && -a[nw].F>t)
            q.push(-a[nw++].S),cnt++;
//        printf("t = %I64d, nw = %d\n",t,nw);
        mn=min(mn,cnt);
    }
    printf("%d\n",mn);
    return 0;
}
