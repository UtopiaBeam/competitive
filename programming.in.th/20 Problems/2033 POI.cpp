#include<cstdio>
#include<algorithm>
using namespace std;
class C{
public:
    int sol,scr,in;
    C(){
        sol=0,scr=0;
    }
}c[2005];
int n,t,p,a[2005][2005],b[2005];
bool cmp(C x,C y){
    if(x.scr!=y.scr)    return x.scr > y.scr;
    if(x.sol!=y.sol)    return x.sol > y.sol;
    return x.in < y.in;
}
int main(){
    scanf("%d %d %d",&n,&t,&p);
    for(int i=1;i<=n;i++)
        for(int j=0;j<t;j++){
            scanf("%d",&a[i][j]);
            if(!a[i][j])    b[j]++;
            else    c[i].sol++;
        }
    for(int i=1;i<=n;i++){
        c[i].in=i;
        for(int j=0;j<t;j++)
            if(a[i][j])     c[i].scr+=b[j];
    }
    sort(c+1,c+n+1,cmp);
    for(int i=1;i<=n;i++)
        if(c[i].in==p)
            printf("%d %d\n",c[i].scr,i);
    return 0;
}
