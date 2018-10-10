#include<stdio.h>
#include<math.h>
#define INF 1<<20
int min[260],n,k;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<(int)pow(2,k);i++)
        min[i]=INF;
    for(int i=0;i<n;i++){
        int pri,p,in=0;
        scanf("%d",&pri);
        for(int j=k-1;j>=0;j--){
            scanf("%d",&p);
            in+=(int)pow(2,j)*p;
        }
        for(int j=0;j<(int)pow(2,k);j++){
            if(min[j|in]>min[j]+pri)
                min[j|in]=min[j]+pri;
        }
    }
    printf("%d\n",min[(int)pow(2,k)-1]);
    return 0;
}
