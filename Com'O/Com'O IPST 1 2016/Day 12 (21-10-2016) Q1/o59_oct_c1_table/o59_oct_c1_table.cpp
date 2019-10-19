#include<cstdio>
#include<queue>
#include<algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int r,c,n,op,x,y,v,t,mn[302],ans,rd[302],cnt[302],chk[302][5002];
P val[302][5002];
void debug(){
    printf("----------------\n");
    for(int i=1;i<=r;i++){
        printf("%d ",mn[i]);
        for(int j=1;j<=c;j++){
            if(val[i][0].S>val[i][j].S)
                printf("%d ",val[i][0].F);
            else    printf("%d ",val[i][j].F);
        }
        printf("\n");
    }
    printf("----------------\n");
}
int f(int i,int j){
    if(val[i][0].S>val[i][j].S)
        return val[i][0].F;
    else    return val[i][j].F;
}
int main(){
    scanf("%d %d %d",&r,&c,&n);
    for(int i=1;i<=r;i++)
        rd[i]=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&op);
        if(op==1){
            scanf("%d %d %d",&x,&y,&v);
            if(chk[x][y]!=rd[x])
                chk[x][y]=rd[x],cnt[x]++;
            val[x][y]=P(v,i);
            if(cnt[x]==c){
                mn[x]=1<<30;
                for(int j=1;j<=c;j++)
                    mn[i]=min(mn[i],f(i,j));
                cnt[x]=0;   rd[x]++;
            }
            else if(v<mn[x])    mn[x]=v;
//            debug();
        }
        if(op==2){
            scanf("%d %d",&x,&v);
            val[x][0]=P(v,i);
            mn[x]=v;
            rd[x]++;    cnt[x]=0;
//            debug();
        }
        if(op==3){
            scanf("%d %d",&x,&y);
            if(val[x][y].S>val[x][0].S)
                printf("%d\n",val[x][y].F);
            else    printf("%d\n",val[x][0].F);
        }
        if(op==4){
            ans=1<<30;
            for(int j=1;j<=r;j++)
                ans=min(mn[j],ans);
            printf("%d\n",ans);
        }
    }
    return 0;
}
