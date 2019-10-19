#include<stdio.h>

int mine(char a[10][10],int i,int j)
{
    int cnt=0;

    if(i+1<=5 && a[i+1][j]==-6)      //down
        cnt++;

    if(i-1>=1 && a[i-1][j]==-6)      //up
        cnt++;

    if(j+1<=5 && a[i][j+1]==-6)      //right
        cnt++;

    if(j-1>=1 && a[i][j-1]==-6)      //left
        cnt++;

    if(i+1<=5 && j+1<=5 && a[i+1][j+1]==-6)  //upright
        cnt++;

    if(i+1<=5 && j-1>=1 && a[i+1][j-1]==-6)  //upleft
        cnt++;

    if(i-1>=1 && j+1<=5 && a[i-1][j+1]==-6)  //downright
        cnt++;

    if(i-1>=1 && j-1>=1 && a[i-1][j-1]==-6)  //downleft
        cnt++;

    if(cnt==0)
        return -16;

    return cnt;
}

int main()
{
    int i,j;
    char a[10][10];

    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
            a[i][j]=' ';
    }

    while(scanf("%d %d",&i,&j)!=EOF)
        a[i][j]=-6;

    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            if(a[i][j]!=-6)
            {
                a[i][j]=mine(a,i,j);
            }
        }
    }

    printf("+-+-+-+-+-+\n");
    for(i=1;i<=5;i++)
    {
        printf("|%c|%c|%c|%c|%c|\n",a[i][1]+'0',a[i][2]+'0',a[i][3]+'0',a[i][4]+'0',a[i][5]+'0');
        printf("+-+-+-+-+-+\n");
    }
    return 0;
}
