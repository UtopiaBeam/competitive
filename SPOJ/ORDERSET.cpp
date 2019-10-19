#include<cstdio>
#include<set>
#include<map>
using namespace std;
set<int> s;
map<int,int> m,M;
int ft[200002],q,x[200002],n=0,t,cnt=0;
char ch[200002];
void ud(int x,int v){
    for(;x<=n;x+=-x&x)  ft[x]+=v;
}
int gs(int x){
    int sum=0;
    for(;x>0;x-=-x&x)     sum+=ft[x];
    return sum;
}
int gt(int x){
    return gs(x)-gs(x-1);
}
int bs(int s,int e,int x){
    if(s>=e)    return M[s];
    int m=(s+e)/2;
    if(gs(m)<x)     return bs(m+1,e,x);
    return bs(s,m,x);
}
int main(){
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf(" %c %d",&ch[i],&x[i]);
        s.insert(x[i]);
    }
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
        m[*it]=++n,M[n]=*it;
    for(int i=0;i<q;i++){
        t=m[x[i]];
        if(ch[i]=='I')
            if(gt(t)==0)    ud(t,1),cnt++;
        if(ch[i]=='D')
            if(gt(t)==1)    ud(t,-1),cnt--;
        if(ch[i]=='K'){
            if(cnt<x[i])    printf("invalid\n");
            else    printf("%d\n",bs(1,n,x[i]));
        }
        if(ch[i]=='C')
            printf("%d\n",gs(t-1));
    }
    return 0;
}
