#include<cstdio>
#include<utility>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int n;
P a[100002],t[100002];
void merge(int s,int m,int e){
    int l=s,r=m+1;
    for(int i=s;i<=e;i++)
        if(l>m)     t[i]=a[r++];
        else if(r>e)    t[i]=a[l++];
        else if(a[l].F<a[r].F)  t[i]=a[l++];
        else if(a[l].F>a[r].F)  t[i]=a[r++];
        else if(a[l].S<a[r].S)  t[i]=a[l++];
        else    t[i]=a[r++];
    for(int i=s;i<=e;i++)   a[i]=t[i];
}
void msort(int s,int e){
    if(s>=e)    return ;
    int m=(s+e)/2;
    msort(s,m);     msort(m+1,e);
    merge(s,m,e);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)    scanf("%d %d",&a[i].F,&a[i].S);
    msort(0,n-1);
    for(int i=0;i<n;i++)    printf("%d %d\n",a[i].F,a[i].S);
    return 0;
}
