#include<stdio.h>

int r,c,cnt=0,a[200][200];

void bomb(int i,int j)
{
    if(i-1>=0 && a[i-1][j]==1)      //up
    {
        a[i-1][j]=0;    cnt++;
        bomb(i-1,j);
    }
    if(i+1<r && a[i+1][j]==1)    //down
    {
        a[i+1][j]=0;    cnt++;
        bomb(i+1,j);
    }
    if(j-1>=0 && a[i][j-1]==1)      //left
    {
        a[i][j-1]=0;    cnt++;
        bomb(i,j-1);
    }
    if(j+1<c && a[i][j+1]==1)     //right
    {
        a[i][j+1]=0;    cnt++;
        bomb(i,j+1);
    }
    if(i-1>=0 && j-1>=0 && a[i-1][j-1]==1)      //upleft
    {
        a[i-1][j-1]=0;    cnt++;
        bomb(i-1,j-1);
    }
    if(i+1<r && j-1>=0 && a[i+1][j-1]==1)    //downleft
    {
        a[i+1][j-1]=0;    cnt++;
        bomb(i+1,j-1);
    }
    if(i-1>=0 && j+1<c && a[i-1][j+1]==1)      //upright
    {
        a[i-1][j+1]=0;    cnt++;
        bomb(i-1,j+1);
    }
    if(i+1<r && j+1<c && a[i+1][j+1]==1)     //downright
    {
        a[i+1][j+1]=0;    cnt++;
        bomb(i+1,j+1);
    }
}
int main()
{
    int i,j;
    char ch;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf(" %c",&ch);
            if(ch=='L')
                a[i][j]=1;
            else if(ch=='E')
                a[i][j]=0;
            else if(ch=='S')
                a[i][j]=2;
        }
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]==2)
            {
                a[i][j]=0;
                cnt++;
                bomb(i,j);
            }
        }
    }
    printf("%d\n",cnt);

    return 0;
}
