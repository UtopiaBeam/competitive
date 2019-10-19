#include<cstdio>
#include<algorithm>
using namespace std;
int a[7][1005],n,b[2005];
int main(){
    scanf("%d",&n);
    for(int i=0;i<7;i++){
        if(i%2){
            for(int j=0;j<=n;j++)
                scanf("%d",&a[i][j]);
        }
        else for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    for(int i=1;i<6;i++){
        if(i%2){
            for(int j=0;j<=n;j++){
                if(j==0 || j==n)   continue;

            }
        }
    }
    sort(b+1,b+2*n-1);
    return 0;
}
