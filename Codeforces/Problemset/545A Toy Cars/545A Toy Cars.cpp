#include<cstdio>
#include<vector>
using namespace std;
vector<int> ans;
int a[105][105],n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            if(a[i][j]==1 || a[i][j]==3)    break;
            if(j==n)    ans.push_back(i);
        }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    return 0;
}
