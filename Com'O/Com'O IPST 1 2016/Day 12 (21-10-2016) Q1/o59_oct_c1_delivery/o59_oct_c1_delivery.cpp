#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#define L long long
#define P pair<L,int>
#define PQ pair<int,L>
#define F first
#define S second
#define hf (L)(1<<k)
using namespace std;
priority_queue<PQ> q;
map<int,vector<P> > g;
map<int,int> chk,d;
map<int,vector<P> >::iterator it;
int k,l,qr,t;
L x,y,s[5],e[5];
int dis(int x,int y){
    int cnt=0;
    while(x!=y){
        if(x>y)     x/=2;
        else        y/=2;
        cnt++;
    }
    return cnt;
}
void dijks(){
    chk.clear();
    q.push(P(0,x));
    while(!q.empty()){
        int w=-q.top().F;
        x=q.top().S;
        q.pop();
        if(!chk[x]){
            chk[x]=1;    d[x]=w;
            for(int i=0;i<g[x].size();i++)
                if(!chk[g[x][i].F] || d[g[x][i].F]>w+g[x][i].S)
                    q.push(PQ(-w-g[x][i].S,g[x][i].F));
        }
    }
}
int main(){
    scanf("%d %d %d",&k,&l,&qr);
    for(int i=0;i<l;i++){
        scanf("%lld %lld",s+i,e+i);
        if(s[i]>e[i]){
            L t=s[i];
            s[i]=e[i];
            e[i]=t;
        }
    }
    for(int t=0;t<qr;t++){
        scanf("%lld %lld",&x,&y);
        if(x>y){
            L t=x;
            x=y;
            y=t;
        }
        int mn=1<<30;
        g.clear();
        if(x<hf && y<hf){
            g[x].push_back(P(y,dis(x,y)));
            g[y].push_back(P(x,dis(x,y)));
        }
        if(x>hf && y>hf){
            g[x].push_back(P(y,dis(x-hf,y-hf)));
            g[y].push_back(P(x,dis(x-hf,y-hf)));
        }
        for(int i=0;i<l;i++){
            g[s[i]].push_back(P(e[i],1));
            g[e[i]].push_back(P(s[i],1));
            if(x<hf){
                g[x].push_back(P(s[i],dis(s[i],x)));
                g[s[i]].push_back(P(x,dis(s[i],x)));
            }
            if(y>hf){
                g[y].push_back(P(e[i],dis(y-hf,e[i]-hf)));
                g[e[i]].push_back(P(y,dis(y-hf,e[i]-hf)));
            }
        }
//        for(it=g.begin();it!=g.end();it++){
//            printf("%d: ",it->F);
//            for(int i=0;i<it->S.size();i++)
//                printf("%d ",(it->S)[i]);
//            printf("\n");
//        }
        dijks();
        printf("%d\n",d[y]);
    }
    return 0;
}
