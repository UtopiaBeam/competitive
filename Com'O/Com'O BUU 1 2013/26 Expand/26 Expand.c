#include<stdio.h>
int n,m,zn,zm,i,zi,j,zj;
char a[102][102];
int main(){
    scanf("%d %d %d %d",&n,&m,&zn,&zm);
    for(i=0;i<n;i++)
        scanf(" %s",a[i]);
    for(i=0;i<n;i++)
        for(zi=0;zi<zn;zi++){
            for(j=0;j<m;j++)
                for(zj=0;zj<zm;zj++)
                    printf("%c",a[i][j]);
            printf("\n");
        }
    return 0;
}
