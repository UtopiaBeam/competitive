#include<cstdio>
#include<algorithm>
using namespace std;
int r,c,h;
long long sum=0,t,mn=1e9;
int main(){
    scanf("%d %d %d",&c,&r,&h);
    for(int k=1;k<=h;k++)
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++){
                scanf("%lld",&t);
                sum+=t;
                if((i+j+k)%2==0)
                    mn=min(mn,t);
            }
    printf("%lld\n",sum-((r+c+h)%2!=(r*c*h)%2)*mn);
    return 0;
}
