#include<stdio.h>
int r,c,newi,newj,I[4]={-1,1,0,0},J[4]={0,0,-1,1},min=50,max=0,len=0,cnt=0;

void send(char a[r+2][c+2],int i,int j,int len)
{
    int k;
    char track;
    if(i<0||j<0||i>=r||j>=c)    return ;
    if(i==r-1 && j==c-1)
    {
        len++,cnt++;
        if(max<len) max=len;
        if(min>len) min=len;
        return ;
    }
    if(a[i][j]!='.')            return ;
    track=a[i][j];
    a[i][j]='X';
    for(k=0;k<4;k++)
    {
        newi=i+I[k];
        newj=j+J[k];
        send(a,newi,newj,len+1);
    }
    a[i][j]=track;
}

int main()
{
    int i;
    scanf("%d %d",&r,&c);
    char a[r+2][c+2];
    for(i=0;i<r;i++)
        scanf(" %s",a[i]);
    send(a,0,0,0);
    printf("%d %d %d\n",cnt,max,min);
    return 0;
}
