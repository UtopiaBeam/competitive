#include<cstdio>
int a[100002],t[100002],n;
void merge(int s,int m,int e){
    int l=s,r=m+1;
    for(int i=s;i<=e;i++){
        if(l>m)    t[i]=a[r++];
        else if(r>e)   t[i]=a[l++];
        else if(a[l]<=a[r])  t[i]=a[l++];
        else    t[i]=a[r++];
    }
    for(int i=s;i<=e;i++)   a[i]=t[i];
}
void mergesort(int s,int e){
    if(s>=e)    return ;
    int m=(s+e)/2;
    mergesort(s,m); mergesort(m+1,e);
    merge(s,m,e);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)   scanf("%d",&a[i]);
    mergesort(0,n-1);
    for(int i=0;i<n;i++)    printf("%d\n",a[i]);
    return 0;
}
