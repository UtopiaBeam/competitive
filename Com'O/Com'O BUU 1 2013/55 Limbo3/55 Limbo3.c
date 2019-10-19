#include<stdio.h>

int a[1010][100],w,h,count=0,next;

void clear(int i,int j)
{
    if(i-1<0)   next=h-1;
    else        next=i-1;
    {
        if(a[next][j]==1)      //up
        {
            a[next][j]=0;
            clear(next,j);
        }
    }

    if(i+1>=h)   next=0;
    else         next=i+1;
    {
        if(a[next][j]==1)      //down
        {
            a[next][j]=0;
            clear(next,j);
        }
    }
    if(j-1<0)   next=w-1;
    else        next=j-1;
    {
        if(a[i][next]==1)      //left
        {
            a[i][next]=0;
            clear(i,next);
        }
    }
    if(j+1>=w)   next=0;
    else         next=j+1;
    {
        if(a[i][next]==1)      //right
        {
            a[i][next]=0;
            clear(i,next);
        }
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
                count++;
                a[i][j]=0;
                clear(i,j);
            }

        }
    }
        printf("%d\n",count);

    return 0;
}
