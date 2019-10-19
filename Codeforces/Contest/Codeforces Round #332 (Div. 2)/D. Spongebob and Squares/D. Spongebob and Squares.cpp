#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define LL long long
#define P pair<LL,LL>
#define F first
#define S second
LL x,a=0,b=0,last=0;
vector<P> v;
int main(){
    scanf("%I64d",&x);
    for(LL i=1;i<=x && i!=last;i++){
        a+=(i*(i-1))/2;
        b+=i;
        if((x+a)%b==0){
            if((x+a)/b<i)   break;
            v.push_back(P(i,(x+a)/b));
            if(i!=(x+a)/b)  v.push_back(P((x+a)/b,i));
            last=(x+a)/b;
        }
    }
    sort(v.begin(),v.end());
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++)
        printf("%I64d %I64d\n",v[i].F,v[i].S);
    return 0;
}
