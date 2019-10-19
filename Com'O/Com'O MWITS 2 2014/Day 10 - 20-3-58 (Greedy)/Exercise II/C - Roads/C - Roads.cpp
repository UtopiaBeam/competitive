#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
typedef pair<double,int> PDI;
double adj[1005][1005];
priority_queue <PDI> q;
int main(){
    int n,m;
    double x[1005],y[1005];
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lf %lf",&x[i],&y[i]);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            adj[i][j]=adj[j][i]=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
    //MST
    return 0;
}
