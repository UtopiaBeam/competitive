#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define P pair<int,int>
#define PP pair<P,P>    //FF = time, FS = type, SF = i, SS = j
#define F first
#define S second
char a[102][102];
int k,R,C,n,T,r,c,t,type,b[102][102][1002],s[5]={-1,1,0,0,0};
int main(){
    scanf("%d",&k);
    while(k--){
        queue<PP> q;
        priority_queue<PP> h;
        bool chk=true;
        memset(b,-1,sizeof(b));
        scanf("%d %d %d %d %d %d",&R,&C,&n,&T,&r,&c);
        q.push(PP(P(0,0),P(r,c)));          //type 0 = pacman
        for(int i=0;i<n;i++){
            scanf("%d %d %d",&t,&r,&c);
            h.push(PP(P(t+1,1),P(r,c)));
        }
        for(int i=0;i<R;i++)    scanf(" %s",a[i]);
        while(!q.empty()){
            t=q.front().F.F,type=q.front().F.S;
            r=q.front().S.F,c=q.front().S.S;
            q.pop();
            while(!h.empty() && h.top().F.F==t+1){
                q.push(h.top());
                b[h.top().S.F][h.top().S.S][t]=0;
                h.pop();
            }
            if(t==T+1)      break;
            if(b[r][c][t]==1-type){
                printf("NO\n");     chk=false;
                break;
            }
            b[r][c][t]=type;
            for(int i=0;i<5;i++){
                int nr=r+s[i],nc=c+s[4-i];
                if(nr>=0 && nc>=0 && nr<R && nc<C && a[nr][nc]=='.')
                    q.push(PP(P(t+1,type),P(nr,nc)));
            }
        }
        if(chk)     printf("YES\n");
    }
    return 0;
}
