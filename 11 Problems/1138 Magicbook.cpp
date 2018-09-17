#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#define l in*n
#define r (in+1)*n-1
using namespace std;
typedef pair<int,int> PII;
map <int,int> m;
PII book[100005];
int n,k,s,x,v,st[1000005],a[300005],h,si=0;
int q(int str,int end,int in,int n){
    if(end<l || str>r)  return -10;
    if(str<=l && r<=end)    return st[in];
    return max(q(str,end,in<<1,n>>1),q(str,end,(in<<1)+1,n>>1));
}
int rq(int str,int end){
    return q((1<<h)+str,(1<<h)+end,1,1<<h);
}
void u(int in){
    if(in==0)   return ;
    st[in]=max(st[in<<1],st[(in<<1)+1]);
    u(in>>1);
}
void ru(int in,int v){
    st[(1<<h)+in]=v;
    u(((1<<h)+in)>>1);
}
void findh(int n){
    while(n)    n=n>>1,h++;
}
int main(){
    memset(st,-10,sizeof(st));
    scanf("%d %d %d",&n,&k,&s);
    a[si++]=s;
    for(int i=0;i<n;i++){
        scanf("%d %d",&x,&v);
        a[si++]=x-k,a[si++]=x,a[si++]=x+k;
        book[i]=PII(x,v);
    }
    sort(a,a+si);
    findh(si);
    for(int i=0;i<si;i++)   m[a[i]]=i;
    map<int,int>::iterator it=m.find(s),it1,it2;
    ru((*it).second,0);
    for(int i=0;i<n;i++){
        it=m.find(book[i].first),it1=m.find(book[i].first-k),it2=m.find(book[i].first+k);
        int Max=rq((*it1).second,(*it2).second);
        if(Max>=0)  ru((*it).second,Max+book[i].second);
    }
    printf("%d\n",st[1]);
    return 0;
}
