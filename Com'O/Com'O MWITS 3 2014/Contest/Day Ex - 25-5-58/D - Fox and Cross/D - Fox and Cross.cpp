#include<cstdio>
int n;
char a[105][105];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf(" %s",a[i]);
    for(int i=1;i<n-1;i++)
        for(int j=1;j<n-1;j++)
            if(a[i][j]=='#' && a[i-1][j]=='#' && a[i+1][j]=='#' && a[i][j-1]=='#' && a[i][j+1]=='#')
                a[i][j]=a[i-1][j]=a[i+1][j]=a[i][j-1]=a[i][j+1]='.';
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i][j]=='#'){
                printf("NO\n");
                return 0;
            }
    printf("YES\n");
    return 0;
}
