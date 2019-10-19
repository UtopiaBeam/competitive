#include<stdio.h>
int a[100][100],check=1,cnt=0,n,x[50],y[50];
void play(int i,int j,int o)
{
    int k,l;
    x[o]=i,y[o]=j;
    if(o==cnt)
    {
        check=0;
        for(k=0;k<=cnt;k++)
            printf("%d %d\n",x[k],y[k]);
        return ;
    }
    if(i-2>0 && j-2>0 && a[i-1][j-1]==1)
    {
        a[i-1][j-1]=0;
        play(i-2,j-2,o+1);
        a[i-1][j-1]=1;
    }
    if(i-2>0 && j+2<=n && a[i-1][j+1]==1)
    {
        a[i-1][j+1]=0;
        play(i-2,j+2,o+1);
        a[i-1][j+1]=1;
    }
    if(i+2<=n  && j-2>0 && a[i+1][j-1]==1)
    {
        a[i+1][j-1]=0;
        play(i+2,j-2,o+1);
        a[i+1][j-1]=1;
    }
    if(i+2<=n && j+2<=n && a[i+1][j+1]==1)
    {
        a[i+1][j+1]=0;
        play(i+2,j+2,o+1);
        a[i+1][j+1]=1;
    }
}
int main()
{
    int i,j;
    char chess;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf(" %c",&chess);
            if(chess=='K')    a[i][j]=2;
            else if(chess=='o')
            {
                a[i][j]=1;
                cnt++;
            }
            else                a[i][j]=0;
        }
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(a[i][j]==2)
                play(i,j,0);
    if(check)   printf("impossible\n");
    return 0;
}
