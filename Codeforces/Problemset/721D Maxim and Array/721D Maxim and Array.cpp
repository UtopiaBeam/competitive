#include<cstdio>
#include<queue>
#include<algorithm>
#define L long long
using namespace std;
struct S{
    int in;
    L num;
    S(){}
    S(L num,int in):
        num(num),in(in){}
    bool operator<(const S &a)const{
        return abs(num) > abs(a.num);
    }
}t;
int n,k,cnt=0;
L x,a[200002];
priority_queue<S> q;
int main(){
    scanf("%d %d %I64d",&n,&k,&x);
    for(int i=0;i<n;i++){
        scanf("%I64d",a+i);
        if(a[i]<0)      cnt++;
        q.push(S(a[i],i));
    }
    while(k--){
        t=q.top();
        q.pop();
        if(cnt%2){
            if(t.num<0)     t.num-=x;
            else            t.num+=x;
        }
        else{
            if(t.num<0)     t.num+=x,cnt-=(t.num>=0);
            else            t.num-=x,cnt+=(t.num<0);
        }
        a[t.in]=t.num;
        q.push(t);
    }
    for(int i=0;i<n;i++)
        printf("%I64d ",a[i]);
    return 0;
}
