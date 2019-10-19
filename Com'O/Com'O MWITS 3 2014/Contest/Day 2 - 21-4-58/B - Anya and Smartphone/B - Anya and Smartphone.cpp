#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,k,a[100005],f[100005],in[100005];
long long cnt=0;
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        in[a[i]]=i;
    }
    while(m--){
        int num;
        scanf("%d",&num);
        cnt+=(long long)in[num]/k+1,f[num]++;
        if(in[num]>0 && f[num]>f[a[in[num]-1]])
            swap(a[in[num]],a[in[num]-1]),swap(in[num],in[a[in[num]]]);
    }
    printf("%lld\n",cnt);
    return 0;
}
