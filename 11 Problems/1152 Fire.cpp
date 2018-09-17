#include<cstdio>
#include<queue>
using namespace std;
int n,a[1002][1002],ans=0;
priority_queue<int> q;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(int i=2*n-1;i>1;i--){
        int x=n-1,y=i-n;
        while(x>=0 && y<n){
            while(y<0)  x--,y++;
            q.push(a[x][y]);
            x--,y++;
        }
        ans+=q.top();
        q.pop();
    }
    printf("%d\n",ans);
    return 0;
}
