#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int a[1010][1010],r,c;
vector <int> ans;
int main(){
    int k,i,j,num,n;
    scanf("%d %d %d",&r,&c,&k);
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++){
            scanf("%d",&num);
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+num;
        }
    for(i=0;i<=r-k;i++)
        for(j=0;j<=c-k;j++)
            ans.push_back(a[i+k][j+k]-a[i][j+k]-a[i+k][j]+a[i][j]);
    n=ans.size();
    sort(&ans[0],&ans[n]);
    for(i=n-1;i>=0;i--)
        printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
