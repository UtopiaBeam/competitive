#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,k,u[1002][1002],d[1002][1002],l[1002][1002],r[1002][1002];
char a[1002][1002];
int main(){
    scanf("%d",&k);
    while(k--){
        int mx=-10;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
            scanf(" %s",a[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                a[i][j]-='0';
        for(int i=0;i<n;i++){
            l[i][0]=a[i][0];
            r[i][m-1]=a[i][m-1];
        }
        for(int j=0;j<m;j++){
            u[n-1][j]=a[n-1][j];
            d[0][j]=a[0][j];
        }
        for(int i=n-2;i>=0;i--)
            for(int j=0;j<m;j++)
                if(a[i][j])     u[i][j]=u[i+1][j]+1;
                else            u[i][j]=0;
        for(int i=1;i<n;i++)
            for(int j=0;j<m;j++)
                if(a[i][j])     d[i][j]=d[i-1][j]+1;
                else            d[i][j]=0;
        for(int j=1;j<m;j++)
            for(int i=0;i<n;i++)
                if(a[i][j])     l[i][j]=l[i][j-1]+1;
                else            l[i][j]=0;
        for(int j=m-2;j>=0;j--)
            for(int i=0;i<n;i++)
                if(a[i][j])     r[i][j]=r[i][j+1]+1;
                else            r[i][j]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                mx=max(mx,u[i][j]+l[i][j]);
                mx=max(mx,u[i][j]+r[i][j]);
                mx=max(mx,d[i][j]+l[i][j]);
                mx=max(mx,d[i][j]+r[i][j]);
            }
        printf("%d\n",mx-1);
    }
    return 0;
}
