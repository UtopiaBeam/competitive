#include<cstdio>
#include<list>
#include<map>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
map<int,int> mp;
list<P> l[100002];
list<P>::iterator it;
int n,m,k,t,x,y,r[100002],nx[100002],h[100002];
int fr(int x){
    if(x!=r[x])     return r[x]=fr(r[x]);
    return x;
}
void debug(){
//    for(int i=1;i<=n;i++){
//        if(!h[i]){
//            int nw=i;
//            while(true){
//                for(it=l[nw].begin();it!=l[nw].end();it++){
//                    if(it->S>0)     mp[it->F]++;
//                    if(mp[it->F]==0)
//                        printf("%d ",it->F);
//                    if(it->S<0)     mp[it->F]--;
//                }
//            }
//            if(nw==nx[nw])      break;
//            nw=nx[nw];
//        }
//        printf("\n");
//    }
    printf("head\n");
    for(int i=1;i<=n;i++)
        printf("%d ",!h[i]);
    printf("\n");
    printf("tail\n");
    for(int i=1;i<=n;i++)
        printf("%d ",fr(i));
    printf("\n");
    printf("next\n");
    for(int i=1;i<=n;i++)
        printf("%d ",nx[i]);
    printf("\n\n");
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        while(k--){
            scanf("%d",&t);
            l[i].push_back(P(t,0));
        }
        r[i]=nx[i]=i;
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&t,&x,&y);
        if(t==1){
            l[x].push_front(P(y,1));
            l[fr(x)].push_back(P(y,-1));
        }
        else    r[fr(x)]=y,nx[x]=y,h[y]=1;
//        debug();
    }
    for(int i=1;i<=n;i++){
        if(!h[i]){
            int nw=i;
            while(true){
                for(it=l[nw].begin();it!=l[nw].end();it++){
                    if(it->S>0)     mp[it->F]++;
                    if(mp[it->F]==0)
                        printf("%d\n",it->F);
                    if(it->S<0)     mp[it->F]--;
                }
                if(nw==nx[nw])      break;
                nw=nx[nw];
            }
        }
    }
    return 0;
}
