#include<cstdio>
#include<algorithm>
using namespace std;
int ft[200005],n,k,now=1,ans;
int query(int in){
    int sum=0;
    for(;in;in-=(-in&in))   sum+=ft[in];
    return sum;
}
void update(int in,int v){
    for(;in<=n;in+=(-in&in))    ft[in]+=v;
}
void bs(int str,int end){
    if(str>end)     return ;
    int mid=(str+end)/2;
    if(str==end){
        k=mid;
        now=query(mid);
        update(mid,-1);
        ans=mid;
    }
    else if(query(mid)<now)     bs(mid+1,end);
    else    bs(str,mid);
}
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        update(i,1);
    for(int i=n;i>0;i--){
        now+=k-1,now=(now-1)%i+1;
        bs(1,n);
    }
    printf("%d\n",ans);
    return 0;
}
