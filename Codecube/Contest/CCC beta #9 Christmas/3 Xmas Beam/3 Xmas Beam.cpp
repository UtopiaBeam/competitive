#include<cstdio>
#include<deque>
#include<algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
deque<int> mn,mx;
deque<int>::iterator it;
int q,n,h,ans=1<<30;
P a[100002];
bool chk(int x){
    int l=0;
    mn.clear();     mx.clear();
    for(int r=1;r<=n;r++){
        while(!mn.empty() && a[mn.back()].S>a[r].S)
            mn.pop_back();
        while(!mx.empty() && a[mx.back()].S<a[r].S)
            mx.pop_back();
        mn.push_back(r);    mx.push_back(r);
        while(l<r && a[r].F-a[l].F>x){
            l++;
            while(!mn.empty() && mn.front()<l)
                mn.pop_front();
            while(!mx.empty() && mx.front()<l)
                mx.pop_front();
        }
        if(a[mx.front()].S-a[mn.front()].S>=h)
            return true;
    }
    return false;
}
int bs(int s,int e){
    if(s==e){
        if(s>1000000)   return -1;
        return s;
    }
    int m=(s+e)/2;
    if(chk(m))      return bs(s,m);
    return bs(m+1,e);
}
int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&h);
        for(int i=1;i<=n;i++)
            scanf("%d %d",&a[i].F,&a[i].S);
        sort(a+1,a+n+1);
        printf("%d\n",bs(0,2000000));
    }
    return 0;
}
