#include<cstdio>
#include<algorithm>
#define P pair<double,double>
#define F first
#define S second
using namespace std;
int n;
double m,c,x0,x1;
P a[100002],t[100002];
long long mrg(int s,int m,int e){
    int l=s,r=m+1;
    long long sum=0;
    for(int i=s;i<=e;i++){
        if(l>m)     t[i]=a[r++];
        else if(r>e)    t[i]=a[l++];
        else if(a[l].S<=a[r].S)  t[i]=a[l++];
        else    t[i]=a[r++],sum+=m-l+1;
    }
    for(int i=s;i<=e;i++)   a[i]=t[i];
    return sum;
}
long long cnt(int s,int e){
    if(s>=e)    return 0;
    int m=(s+e)/2;
    return cnt(s,m)+cnt(m+1,e)+mrg(s,m,e);
}
int main(){
    scanf("%d %lf %lf",&n,&x0,&x1);
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&m,&c);
        a[i].F=m*x0+c,a[i].S=m*x1+c;
    }
    sort(a,a+n);
    printf("%lld\n",cnt(0,n-1));
    return 0;
}
