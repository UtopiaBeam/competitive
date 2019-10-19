#include<stdio.h>

int a[1010][100],w,h,count,max=0;

void clear(int i,int j)
{
    if(i-1>=0 && a[i-1][j]==1)      //up
    {
        a[i-1][j]=0;    count++;
        clear(i-1,j);
    }
    if(i+1<h && a[i+1][j]==1)    //down
    {
        a[i+1][j]=0;    count++;
        clear(i+1,j);
    }
    if(j-1>=0 && a[i][j-1]==1)      //left
    {
        a[i][j-1]=0;    count++;
        clear(i,j-1);
    }
    if(j+1<w && a[i][j+1]==1)     //right
    {
        a[i][j+1]=0;    count++;
        clear(i,j+1);
    }
}

int main()
{
    int i,j;
    char ch;
    scanf("%d %d",&w,&h);
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            scanf(" %c",&ch);
            if(ch=='*')
                a[i][j]=1;
            else
                a[i][j]=0;
        }
    }
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
        {
            if(a[i][j]==1)
            {
                count=1;
                a[i][j]=0;
                clear(i,j);
                if(count>max)
            max=count;
            }
        }
    }
        printf("%d\n",max);

    return 0;
}
