#include<stdio.h>
int r,c,newi,newj,I[4]={-1,1,0,0},J[4]={0,0,-1,1},cnt=0,search;

void send(char a[r+2][c+2],int i,int j,int len,int search)
{
    int k;
    char track;
    if(i<0||j<0||i>=r||j>=c)    return ;
    if(i==r-1 && j==c-1)
    {
        len++;
        if(len==search) cnt++;
        return ;
    }
    if(a[i][j]!='.')            return ;
    track=a[i][j];
    a[i][j]='X';
    for(k=0;k<4;k++)
    {
        newi=i+I[k];
        newj=j+J[k];
        send(a,newi,newj,len+1,search);
    }
    a[i][j]=track;
}

int main()
{
    int i;
    scanf("%d %d %d",&r,&c,&search);
    char a[r+2][c+2];
    for(i=r-1;i>=0;i--)
        scanf(" %s",a[i]);
    send(a,0,0,0,search);
    printf("%d\n",cnt);
    return 0;
}
