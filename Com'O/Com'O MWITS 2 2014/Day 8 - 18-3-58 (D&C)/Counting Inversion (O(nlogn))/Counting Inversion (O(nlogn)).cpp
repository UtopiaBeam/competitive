#include<cstdio>
int n,a[1000],t[1000];
int merge(int str,int mid,int end){
    int sum=0,l=str,r=mid+1;
    for(int i=str;i<=end;i++){
        if(l>mid)       t[i]=a[r++];
        else if(r>end)  t[i]=a[l++];
        else if(a[l]<=a[r])  t[i]=a[l++];
        else        t[i]=a[r++],sum+=mid-l+1;
    }
    for(int i=str;i<=end;i++)
        a[i]=t[i];
    return sum;
}
int cnt(int str,int end){
    if(str>=end)    return 0;
    int mid=(str+end)/2;
    return cnt(str,mid)+cnt(mid+1,end)+merge(str,mid,end);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("%d\n",cnt(0,n-1));
    return 0;
}
