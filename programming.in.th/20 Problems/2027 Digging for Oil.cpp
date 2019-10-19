#include<cstdio>
#include<algorithm>
using namespace std;
int r,c,k,qs[1502][1502];
int main(){
    scanf("%d %d %d",&r,&c,&k);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
            scanf("%d",&qs[i][j]);
            qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    return 0;
}
