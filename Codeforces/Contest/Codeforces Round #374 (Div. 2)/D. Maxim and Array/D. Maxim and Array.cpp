#include<cstdio>
#include<vector>
#include<queue>
#define L long long
#define P pair<L,int>
#define F first
#define S second
using namespace std;
int n,k,cnt=0;
L x,a[200002];
vector<int> zr;
priority_queue<P> pq,mq;
P pt,mt;
int main(){
    scanf("%d %d %I64d",&n,&k,&x);
    for(int i=0;i<n;i++){
        scanf("%I64d",a+i);
        if(a[i]==0)     zr.push_back(i);
        if(a[i]>0)      pq.push(P(-a[i],i));
        if(a[i]<0)      mq.push(P(a[i],i)),cnt++;
    }
    while(k--){
//        printf("cnt = %d\n",cnt);
        if(!zr.empty()){
//            printf("1 : ");
            if(cnt%2){
                a[zr.back()]=x;
                pq.push(P(-x,zr.back()));
                zr.pop_back();
            }
            else{
                a[zr.back()]=-x;    cnt++;
                mq.push(P(-x,zr.back()));
                zr.pop_back();
            }
            continue;
        }
        if(!pq.empty())     pt=pq.top(),pt.F*=-1;
        else    pt=P(1e18,-1);
        if(!mq.empty())     mt=mq.top(),mt.F*=-1;
        else    mt=P(1e18,-1);
        if(cnt%2){
//            printf("2 : ");
            if(pt.F < mt.F){
                pq.pop();   pt.F+=x;
                a[pt.S]=pt.F;
                pq.push(P(-pt.F,pt.S));
            }
            else{
                mq.pop();   mt.F+=x;
                a[mt.S]=-mt.F;
                mq.push(P(-mt.F,mt.S));
            }
        }
        else{
//            printf("3 : ");
            if(pt.F < mt.F){
                pq.pop();   pt.F-=x;
                a[pt.S]=pt.F;
                if(pt.F==0)     zr.push_back(pt.S);
                if(pt.F>0)      pq.push(P(-pt.F,pt.S));
                if(pt.F<0)      mq.push(pt),cnt++;
            }
            else{
                mq.pop();   mt.F+=x;
                a[mt.S]=mt.F;
                if(mt.F==0)     zr.push_back(mt.S);
                if(mt.F>0)      pq.push(P(-mt.F,mt.S)),cnt--;
                if(mt.F<0)      mq.push(mt);
            }
        }
    }
    for(int i=0;i<n;i++)
        printf("%I64d ",a[i]);
    printf("\n");
    return 0;
}
