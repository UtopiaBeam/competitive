#include<cstdio>
#include<vector>
using namespace std;
int n,m,a[100002],x,isAm=0,isIm=0;
vector<int> h[100002];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        h[x].push_back(i);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&x);
        if(h[x].empty())
            isIm=1;
        else if(h[x].size()>1)
            isAm=1;
        else    a[i]=h[x][0];
    }
    if(isIm)    printf("Impossible\n");
    else if(isAm)   printf("Ambiguity\n");
    else{
        printf("Possible\n");
        for(int i=0;i<m;i++)
            printf("%d ",a[i]);
    }
    return 0;
}
