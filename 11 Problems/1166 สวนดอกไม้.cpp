#include<stdio.h>
int a[40][40],max=0,cnt,r,c;
void clear(int i,int j){
    if(i>0 && a[i-1][j]==1){       //up
        cnt++;  a[i-1][j]=0;
        clear(i-1,j);
    }
    if(i<r-1 && a[i+1][j]==1){       //down
        cnt++;  a[i+1][j]=0;
        clear(i+1,j);
    }
    if(j>0 && a[i][j-1]==1){       //left
        cnt++;  a[i][j-1]=0;
        clear(i,j-1);
    }
    if(j<c-1 && a[i][j+1]==1){       //right
        cnt++;  a[i][j+1]=0;
        clear(i,j+1);
    }
}
int main(){
    int i,j;
    char ch;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            scanf(" %c",&ch);
            if(ch=='.')     a[i][j]=1;
            else            a[i][j]=0;
        }
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            if(a[i][j]==0){
                if(i>0&&a[i-1][j]==1)     a[i-1][j]=-1;
                if(i<r-1&&a[i+1][j]==1)   a[i+1][j]=-1;
                if(j>0&&a[i][j-1]==1)     a[i][j-1]=-1;
                if(j<c-1&&a[i][j+1])   a[i][j+1]=-1;
            }
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            if(a[i][j]==1){
                a[i][j]=0;
                cnt=1;
                clear(i,j);
                if(max<cnt) max=cnt;
            }
    printf("%d\n",max);
    return 0;
}
