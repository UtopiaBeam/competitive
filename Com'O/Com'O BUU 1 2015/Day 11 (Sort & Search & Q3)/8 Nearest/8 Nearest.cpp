#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
map<double,P> m;
vector<double> v;
int q;
double x,y;
bool cmp(double x,double y){
    return x < y;
}
int gcd(int x,int y){
    if(x%y)     return gcd(y,x%y);
    return y;
}
int main(){
    for(int i=1;i<99;i++)
        for(int j=i+1;j<=99;j++)
            if(gcd(i,j)==1){
                v.push_back((double)i/j);
                m[(double)i/j]=P(i,j);
            }
    sort(v.begin(),v.end(),cmp);
    scanf("%d",&q);
    while(q--){
        scanf("%lf %lf",&x,&y);
        int in=lower_bound(v.begin(),v.end(),x/y)-v.begin();
        printf("%d %d %d %d\n",m[v[in-1]].F,m[v[in-1]].S,m[v[in]].F,m[v[in]].S);
    }
    return 0;
}
