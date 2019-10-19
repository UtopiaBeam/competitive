#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
vector<ll> v;
ll a[102],x,y;
int main(){
    for(int i=1;i<log2(1e18);i++){
        for(int j=0;j<=i;j++)
            a[j]=1;
        for(int j=1;j<=i;j++){
            a[j]=0,a[j-1]=1;
            ll t=0;
            for(int k=0;k<=i;k++)
                t*=2,t+=a[k];
            v.push_back(t);
        }
    }
    scanf("%I64d %I64d",&x,&y);
    printf("%d\n",upper_bound(v.begin(),v.end(),y)-lower_bound(v.begin(),v.end(),x));
    return 0;
}
