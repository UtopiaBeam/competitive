#include <cstdio>
#include <algorithm>
int n,m;
int t[1000002];
int mx[1000002];
int mxIdx[1000002];
int cnt[1000002];
int ans=0;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++)
            scanf("%d",t+j);
        std::sort(t,t+m);
        for(int j=0; j<m; j++){
            if(mx[j] < t[j]){
                mx[j] = t[j];
                mxIdx[j] = i;
            }
        }
//        printf("Max:\n");
//        for(int j=0; j<m; j++)
//            printf("%d ",mxIdx[j]);
//        printf("\n--------------\n");
    }
    for(int i=0; i<m; i++)
        cnt[mxIdx[i]]++;
    for(int i=1; i<=n; i++)
        if(cnt[ans] < cnt[i])
            ans=i;
    printf("%d\n",ans);
    return 0;
}
