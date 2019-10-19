#include<cstdio>
#include<vector>
#include<algorithm>
#define L long long
using namespace std;
struct S{
    L a,b,c;
    S(L a=0,L b=0,L c=0):
        a(min(a,b)),b(max(a,b)),c(c){}
};
int q;
L s,la,lb,lc;
vector<S> v;
bool cmp(S x,S y){
    return x.a<y.a;
}
bool cmp2(S x,S y){
    return x.a==y.a && x.b==y.b && x.c==y.c;
}
int main(){
    scanf("%d",&q);
    for(int t=1;t<=q;t++){
        v.clear();
        la=lb=lc=0;
        scanf("%lld",&s);
        printf("Case #%d:\n",t);
        for(L a=1;a<=s/3;a++){
            L x=s*s-2*a*s,y=2*s-2*a;
            if(x%y)     continue;
            L b=x/y,c=s-a-b;
            if(a*a+b*b==c*c)    v.push_back(S(a,b,c));
        }
        sort(v.begin(),v.end(),cmp);
        if(v.empty())   printf("-1\n");
        else for(int i=0;i<v.size();i++){
            if(la==v[i].a && lb==v[i].b && lc==v[i].c)   continue;
            la=v[i].a,lb=v[i].b,lc=v[i].c;
            printf("%lld %lld %lld\n",v[i].a,v[i].b,v[i].c);
        }
    }
    return 0;
}
