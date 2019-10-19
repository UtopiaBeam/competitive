#include<cstdio>
int a[100005],t[100005],n;
//int mrg(int s,int m,int e){
//    int sum=0,l=s,r=m+1;
//    for(int i=s;i<=e;i++){
//        if(l>m)         t[i]=a[r++];
//        else if(r>e)    t[i]=a[l++];
//        else if(a[l]<=a[r])  t[i]=a[l++];
//        else    t[i]=a[r++],sum+=m-l+1;
//    }
//    for(int i=s;i<=e;i++)
//        a[i]=t[i];
//    return sum;
//}
//int cnt(int s,int e){
//    if(s>=e)     return 0;
//    int m=(s+e)/2;
//    return cnt(0,m)+cnt(m+1,e)+mrg(s,m,e);
//}
int main(){
    int cnt=0,t;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=n;i>1;i--)
        for(int j=1;j<i;j++)
            if(a[j]>a[j+1])
                t=a[j],a[j]=a[j+1],a[j+1]=t,cnt++;
    printf("%d\n",cnt);
//    printf("%d\n",cnt(0,n-1));
//    return 0;
}
