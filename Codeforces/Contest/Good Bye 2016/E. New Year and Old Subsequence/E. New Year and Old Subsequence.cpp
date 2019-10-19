#include<cstdio>
#include<cmath>
#include<deque>
#include<algorithm>
using namespace std;
struct S {
    int l,r;
    int id;
}q[200002];
int n,m,bx,by;
int N,ans[200002];
char a[200002];
deque<int> cnt[5];
bool cmp(S x,S y){
    bx=x.l/N;
    by=y.l/N;
    return (bx < by) || (bx == by && x.r < y.r);
}
void add_front(int x){
    if(a[x]=='2')
        cnt[0].push_front(x);
    if(a[x]=='0')
        cnt[1].push_front(x);
    if(a[x]=='1')
        cnt[2].push_front(x);
    if(a[x]=='6')
        cnt[3].push_front(x);
    if(a[x]=='7')
        cnt[4].push_front(x);
}
void add_back(int x){
    if(a[x]=='2')
        cnt[0].push_back(x);
    if(a[x]=='0')
        cnt[1].push_back(x);
    if(a[x]=='1')
        cnt[2].push_back(x);
    if(a[x]=='6')
        cnt[3].push_back(x);
    if(a[x]=='7')
        cnt[4].push_back(x);
}
void del_front(int x){
    if(a[x]=='2')
        cnt[0].pop_front();
    if(a[x]=='0')
        cnt[1].pop_front();
    if(a[x]=='1')
        cnt[2].pop_front();
    if(a[x]=='6')
        cnt[3].pop_front();
    if(a[x]=='7')
        cnt[4].pop_front();
}
void del_back(int x){
    if(a[x]=='2')
        cnt[0].pop_back();
    if(a[x]=='0')
        cnt[1].pop_back();
    if(a[x]=='1')
        cnt[2].pop_back();
    if(a[x]=='6')
        cnt[3].pop_back();
    if(a[x]=='7')
        cnt[4].pop_back();
}
bool chk(){
    if(cnt[4].empty())      return false;
    for(int i=0;i<3;i++)
        if(cnt[i].empty())  return false;
    for(int i=0;i<3;i++)
        if(!cnt[i].empty() && !cnt[i+1].empty() && cnt[i].front()>cnt[i+1].front())
            return false;
    return true;
}
int findAns(){
    int key=cnt[3].back();
    int mn=cnt[3].size();
    for(int i=0;i<2;i++){
        int tmp=lower_bound(cnt[i].begin(),cnt[i].end(),key)-cnt[i].begin();
        mn=min(mn,tmp);
    }
    return mn;
}
int main(){
    scanf("%d %d",&n,&m);
    N=(int)sqrt(n);
    scanf(" %s",a);
    for(int i=0;i<m;i++){
        scanf("%d %d",&q[i].l,&q[i].r);
        q[i].l--;   q[i].r--;
        q[i].id=i;
    }
    sort(q,q+m,cmp);
//    printf("\n");
//    for(int i=0;i<m;i++)
//        printf("%d %d\n",q[i].l,q[i].r);
//    printf("\n");
    int l=0,r=-1;
    for(int i=0;i<m;i++){
        while(r<q[i].r)     add_back(++r);
        while(r>q[i].r)     del_back(r--);
        while(l<q[i].l)     del_front(l++);
        while(l>q[i].l)     add_front(--l);
        if(chk())   ans[q[i].id]=findAns();
        else        ans[q[i].id]=-1;
//        for(int j=0;j<5;j++)
//            printf("%d ",cnt[j]);
//        printf("\n");
    }
    for(int i=0;i<m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
