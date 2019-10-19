#include<bits/stdc++.h>
using namespace std;
double sum=0.0,a[100005],t[100005],m;
void merge(int str,int mid,int end){
    double dp[100005];
    int l=str,r=mid+1;
    dp[l]=a[l];
    for(int i=l+1;i<r;i++)
        dp[i]=a[i]+dp[i-1];
    for(int i=str;i<=end;i++){
        if(l>mid)       t[i]=a[r++];
        else if(r>end)  t[i]=a[l++];
        else if(a[l]<=a[r]) t[i]=a[l++];
        else{
            t[i]=a[r];
            sum+=(mid-l+1)*a[r++]+dp[mid];
            if(l>str)   sum-=dp[l-1];
        }
    }
    for(int i=str;i<=end;i++)
        a[i]=t[i];
}
void cnt(int str,int end){
    if(str>=end)    return ;
    int mid=(str+end)/2;
    cnt(str,mid);   cnt(mid+1,end);
    merge(str,mid,end);
}
int main(){
    int n,k;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf %d",&m,&k);
        a[k-1]=m;
    }
    cnt(0,n-1);
    printf("%.0lf\n",sum);
    return 0;
}
