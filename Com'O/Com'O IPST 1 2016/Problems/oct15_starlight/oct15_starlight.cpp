#include<cstdio>
#include<algorithm>
#define P pair<int,int>
#define x first
#define y second
using namespace std;
int n,s,mxx=(int)-1e9,mxy=(int)-1e9;
int X[100002],Y[100002];
int main(){
    scanf("%d %d",&s,&n);
    for(int i=0;i<n;i++)    scanf("%d %d",&X[i],&Y[i]);
    sort(X,X+n);    sort(Y,Y+n);
    mxx=2*max(X[0],s-X[n-1]),mxy=2*max(Y[0],s-Y[n-1]);
    for(int i=0;i<n;i++)
        mxx=max(mxx,X[i]-X[i-1]),mxy=max(mxy,Y[i]-Y[i-1]);
    printf("%.3f\n",0.5*min(mxx,mxy));
    return 0;
}
