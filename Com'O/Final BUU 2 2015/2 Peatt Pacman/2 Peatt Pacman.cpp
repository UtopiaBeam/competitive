#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int k,a[702][702],r,c,n,t,T,rp,cp;
struct S{
    int x,y,t,type;     //type 0 = pacman, 1 = ghost
    S(int x,int y,int t,int type):
        x(x),y(y),t(t),type(type){}
};
struct cmp{
    bool operator()(S a,S b){
        return a.t<b.t;
    }
};
int main(){
    scanf("%d",&k);
    while(k--){
        queue<S> q;
        priority_queue<S,vector<S>,cmp> h;
        memset(a,0,sizeof(a));
        scanf("%d %d %d %d %d %d",&r,&c,&n,&T,&rp,&cp);
        q.push(*(new S(rp,cp,0,0)));
        for(int i=0;i<n;i++){
            scanf("%d %d %d",&rp,&cp,&t);
            h.push(*(new S(rp,cp,t,1)));
        }
        while(!q.empty()){
            ;
        }
    }
}
