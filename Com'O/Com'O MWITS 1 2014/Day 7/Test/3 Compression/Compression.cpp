#include<stdio.h>
int a,b[1005][1005];
int main(){
    int i,j,n,k;
    freopen("compression.in","r",stdin);
    freopen("compression.out","w",stdout);
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            scanf("%d",&a);
            b[i/k][j/k]+=a;
        }
    for(i=0;i<n/k;i++){
        for(j=0;j<n/k;j++){
            if(2*(b[i][j]%(k*k))>=k*k)
                printf("%d ",b[i][j]/(k*k)+1);
            else    printf("%d ",b[i][j]/(k*k));
        }
        printf("\n");
    }
    return 0;
}
