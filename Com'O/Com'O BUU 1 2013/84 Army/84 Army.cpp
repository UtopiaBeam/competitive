#include<stdio.h>
#include<string.h>
char a[800][800];
int q[562600][2],b[800][800],max=-1<<20,r,c;
int main(){
    memset(b,-1,sizeof(b));
    int front=0,rear=0,i,j;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
        scanf(" %s",a[i]);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            if(a[i][j]=='.' && b[i][j]==-1)
                q[rear][0]=i,q[rear++][1]=j;
}
