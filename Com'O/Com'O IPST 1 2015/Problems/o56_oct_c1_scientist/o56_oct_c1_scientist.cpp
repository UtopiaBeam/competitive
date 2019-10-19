#include<cstdio>
#include<cstring>
#include<queue>
#define INF (int)1e9
using namespace std;
struct S{
    int ch,d,c,cnt;
}s,e,nx,a[5];
int t,dp[10][10][10];    //[][0]=chicken, [1]=dog, [2]=cat
queue<S> q;
int main(){
    for(int i=0;i<3;i++)
        scanf("%d %d %d",&a[i].ch,&a[i].d,&a[i].c);
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                for(int k=0;k<10;k++)
                    dp[i][j][k]=INF;
        scanf("%d %d %d",&s.ch,&s.d,&s.c);
        s.cnt=0;
        scanf("%d %d %d",&e.ch,&e.d,&e.c);
        q.push(s);
        while(!q.empty()){
            s=q.front();
            q.pop();
            if(dp[s.ch][s.d][s.c]<=s.cnt)   continue;
            dp[s.ch][s.d][s.c]=s.cnt;
            nx.cnt=s.cnt+1;
            if(s.ch)    nx.ch=s.ch-1+a[0].ch,nx.d=s.d+a[0].d,nx.c=s.c+a[0].c,q.push(nx);
            if(s.d)     nx.ch=s.ch+a[1].ch,nx.d=s.d-1+a[1].d,nx.c=s.c+a[1].c,q.push(nx);
            if(s.c)     nx.ch=s.ch+a[2].ch,nx.d=s.d+a[2].d,nx.c=s.c-1+a[2].c,q.push(nx);
        }
        if(dp[e.ch][e.d][e.c]==INF)     printf("NO SOLUTION\n");
        else    printf("%d\n",dp[e.ch][e.d][e.c]);
    }
    return 0;
}
