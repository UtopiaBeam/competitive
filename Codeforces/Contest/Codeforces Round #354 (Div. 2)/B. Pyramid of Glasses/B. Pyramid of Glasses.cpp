#include<cstdio>
int n,t,a[12][12],cnt;
int main(){
    scanf("%d %d",&n,&t);
    for(int tt=1;tt<=t;tt++){
        a[1][1]+=1024;
        for(int i=2;i<=n+1;i++){
            if(a[i-1][1]>1024)
                a[i][1]+=(a[i-1][1]-1024)>>1;
            for(int j=2;j<i;j++){
                if(a[i-1][j-1]>1024)
                    a[i][j]+=(a[i-1][j-1]-1024)>>1;
                if(a[i-1][j]>1024)
                    a[i][j]+=(a[i-1][j]-1024)>>1;
            }
            if(a[i-1][i-1]>1024)
                a[i][i]+=(a[i-1][i-1]-1024)>>1;
            for(int j=1;j<i;j++)
                if(a[i-1][j]>1024)
                    a[i-1][j]=1024;
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            if(a[i][j]==1024)
                cnt++;
    printf("%d\n",cnt);
    return 0;
}
