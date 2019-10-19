#include<cstdio>
#include<algorithm>
#define N 10
using namespace std;
int a[N+2],t[N+2];
int part(int s,int e){
    if(s>=e)    return 0;
    int mx=(int)-1e9,mn=(int)1e9;
    for(int i=s;i<=e;i++)
        mx=max(mx,a[i]),mn=min(mn,a[i]);
    int pivot=(mn+mx)/2,l=s,r=e;
    for(int i=s;i<=e;i++)
        if(a[i]<=pivot)     t[l++]=a[i];
        else    t[r--]=a[i];
    for(int i=s;i<=e;i++)   a[i]=t[i];
    return l;
}
void quicksort(int s,int e){
    if(s>=e)    return ;
    int m=part(s,e);
    quicksort(s,m-1);     quicksort(m,e);
}
int main(){
    for(int i=0;i<N;i++)    scanf("%d",&a[i]);
    quicksort(0,N-1);
    for(int i=0;i<N;i++)    printf("%d ",a[i]);
    return 0;
}
