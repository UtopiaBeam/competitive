#include<cstdio>
#include<algorithm>
using namespace std;
int a[1010][1010],b[10010],n,k,ans=0;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n+1;i++){
        int num;
        for(int j=1;j<=n;j++){
            scanf("%d",&num);
            a[i][j]+=3*num;
            a[i-1][j]-=3*num;
        }
        if(i<n+1){
            for(int j=1;j<=n+1;j++){
                scanf("%d",&num);
                a[i][j]+=5*num;
                a[i][j-1]-=5*num;
            }
        }
    }
    for(int i=1;i<=n*n;i++)
        b[i]=a[(i-1)/n+1][(i-1)%n+1];
    sort(b+1,b+n*n+1);
    for(int i=1;i<=k;i++)
        ans+=b[i];
    printf("%d\n",ans);
    return 0;
}
