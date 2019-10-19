/*
TASK: Board Roll
LANG: C
AUTHOR: Natchapol Srisang
CENTER: Princess Chulabhron's College, Chonburi
*/
#include<stdio.h>
int a[10010][10010],b[1000010100][2],cnt;
int main(){
    int i,j,q,n,r,c,a,x,y,t;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            a[i][j]=(i-1)*n+j,b[a[i][j]][0]=i,b[a[i][j]][1]=j;
    while(q--){
        cnt=0;
        scanf("%d %d %d",&a,&r,&c);
        x=b[a][0],y=b[a][1];
        if(x<=r){
            t=a[n][y];
            for(i=r;i>=x;i--){
                a[i]=a[i-1];
            }
        }
    }
    return 0;
}
