#include<stdio.h>
int r,c,X[5]={0,-1,1,0,0},Y[5]={0,0,0,-1,1};
void turn(int a[r+2][c+2],int x,int y)
{
    int k;
    if(x<1||y<1||x>r||y>c)  return ;
    for(k=0;k<5;k++)
    {
        if(a[x+X[k]][y+Y[k]])
            a[x+X[k]][y+Y[k]]=0;
        else
            a[x+X[k]][y+Y[k]]=1;
    }
}

int main()
{
    int q,x,y,i,j;
    scanf("%d %d %d",&r,&c,&q);
    int a[r+2][c+2];

    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            a[i][j]=0;
    for(i=0;i<q;i++)
    {
        scanf("%d %d",&x,&y);
        turn(a,x,y);
    }

    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
