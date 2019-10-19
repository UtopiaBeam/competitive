#include<cstdio>
#include<algorithm>
using namespace std;
double l,v1,v2,mn=1LL,t=0;
int n,k;
int main(){
    scanf("%d %lf %lf %lf %d",&n,&l,&v1,&v2,&k);
    mn=l/v1;
    printf("%lf\n",mn);
    return 0;
}
