#include<cstdio>
#include<algorithm>
using namespace std;
long long sum[66000],n;
int q;
int main(){
    for(int i=1;i<66000;i++)
        sum[i]=sum[i-1]+i;
    scanf("%d",&q);
    while(q--){
        scanf("%I64d",&n);
        int in=lower_bound(sum,sum+66000,n-1)-sum;
        if(sum[in]+1==n)    printf("1 ");
        else    printf("0 ");
    }
    return 0;
}
