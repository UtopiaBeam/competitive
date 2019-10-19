#include<stdio.h>

int a[120][120],r,c,cnt=0;

int check(int i,int j)
{
    if(i-1>=0 && a[i-1][j]==1)  cnt+=3;     //up
    if(i+1<r && a[i+1][j]==1)   cnt+=3;     //down
    if(j-1>=0 && a[i][j-1]==1)  cnt+=3;     //left
    if(j+1<c && a[i][j+1]==1)   cnt+=3;     //right

    return cnt;
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
            if(ch=='#')
                a[i][j]=1;
            else if(ch=='.')
                a[i][j]=0;
        }
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(a[i][j]==0)
                check(i,j);
        }
    }
    printf("%d\n",cnt);
    return 0;
}
