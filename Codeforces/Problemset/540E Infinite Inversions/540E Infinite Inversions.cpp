#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
map<int,int> m;
map<int,int>::iterator it;
vector<P> v;
int n,x,y,ft[200002];
long long cnt=0;
void ud(int x){
    for(;x<=200000;x+=-x&x)    ft[x]++;
}
long long qr(int x){
    long long sum=0;
    for(;x;x-=-x&x)     sum+=ft[x];
    return sum;
}
bool cmp(P x,P y){
    return (x.F>y.F) || (x.F==y.F && x.S<y.S);
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&x,&y);
        if(!m.count(x))     m[x]=x;
        if(!m.count(y))     m[y]=y;
        swap(m[x],m[y]);
    }
    for(it=m.begin();it!=m.end();it++){
        v.push_back(P(it->S,it->F));
        it->S=v.size();
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        cnt+=qr(m[v[i].S]);
        ud(m[v[i].S]);
        cnt+=abs(v[i].F-v[i].S)-abs(m[v[i].F]-m[v[i].S]);
    }
    printf("%I64d\n",cnt);
    return 0;
}
