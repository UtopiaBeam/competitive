#include<cstdio>
#include<vector>
#define P pair<int,int>
#define F first
#define S second
using namespace std;
int pas[1002][1002]={{1},{1,1}};
int n,m,in,a[1002],ans=1,lim=0;
vector<P> v;
int main(){
    for(int i=2;i<=1000;i++){
        pas[i][0]=pas[i][i]=1;
        for(int j=1;j<i;j++)
            pas[i][j]=pas[i-1][j-1]+pas[i-1][j],pas[i][j]%=9901;
    }
    v.push_back(P(1,1));
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        lim+=a[i];
    }
    while(m--){
        scanf("%d",&in);
        int t=in;
        for(int i=1;t;i++){
            if(t>a[i])      t-=a[i];
            else{
                v.push_back(P(in,i));   t=0;
            }
        }
    }
    v.push_back(P(lim,n));
    for(int i=1;i<v.size();i++){
        int M=v[i].F-v[i-1].F-1;
        int N=v[i].S-v[i-1].S+1;
        if(M>0){
            ans*=pas[M+1][M-N+2];
            ans%=9901;
        }
    }
    printf("%d\n",ans);
    return 0;
}
