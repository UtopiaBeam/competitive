#include<cstdio>
int n,k,t,a[4005][4005],mx=0;
int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        int x=i+1,y=n-i;
        for(int j=0;j<n;j++)
            scanf("%d",&a[x+j][y+j]);
    }
    n=2*n-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            if(!a[i][j])    printf("-- ");
            else    printf("%2d ",a[i][j]);
        printf("\n");
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
//    printf("--------------\n");
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=n;j++)
//
//            printf("%d ",a[i][j]);
//        printf("\n");
//    }
    for(int i=0;i<n;i++){
        int x=i+1,y=n-i;
        for(int j=0;j<n;j++,x++,y++){
            t=a[x+k][y+k];
            if(x-k-1>0)   t-=a[x-k-1][y+k];
            if(y-k-1>0)   t-=a[x+k][y-k-1];
            if(x-k-1>0 && y-k-1>0)
                t+=a[x-k-1][y-k-1];
            if(mx<t)    mx=t;
        }
    }
    printf("%d\n",mx);
    return 0;
}
