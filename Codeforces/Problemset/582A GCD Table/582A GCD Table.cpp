#include<cstdio>
#include<map>
#define F first
#define S second
using namespace std;
int n,t,a[502];
map<int,int> m;
int gcd(int x,int y){
    if(x%y)     return gcd(y,x%y);
    return y;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n*n;i++){
        scanf("%d",&t);
        m[-t]++;
    }
    int nw=n-1;
    for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
        while(it->S--){
            a[nw]=-it->F;
            for(int i=nw+1;i<n;i++)
                m[-gcd(a[nw],a[i])]-=2;
            nw--;
        }
    }
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
