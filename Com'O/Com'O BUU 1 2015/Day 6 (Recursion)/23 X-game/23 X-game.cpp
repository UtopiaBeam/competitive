#include<cstdio>
char a[5][5];
int chk=1,mn=1<<30,n='b'+'w';
void f(int i,int j,int cnt){
    if(i>3)     return ;
    int chb=0,chw=0;
    for(int r=0;r<4;r++)
        for(int c=0;c<4;c++)
            if(a[r][c]=='b')    chb=1;
            else    chw=1;
    if((chb && !chw) || (!chb && chw)){
        if(mn>cnt)      mn=cnt;
        chk=0;
        return ;
    }
    if(j>3)     i++,j=0;
    a[i][j]=n-a[i][j];
    if(i>0)     a[i-1][j]=n-a[i-1][j];
    if(i<3)     a[i+1][j]=n-a[i+1][j];
    if(j>0)     a[i][j-1]=n-a[i][j-1];
    if(j<3)     a[i][j+1]=n-a[i][j+1];
    f(i,j+1,cnt+1);
    a[i][j]=n-a[i][j];
    if(i>0)     a[i-1][j]=n-a[i-1][j];
    if(i<3)     a[i+1][j]=n-a[i+1][j];
    if(j>0)     a[i][j-1]=n-a[i][j-1];
    if(j<3)     a[i][j+1]=n-a[i][j+1];
    f(i,j+1,cnt);
}
int main(){
    for(int i=0;i<4;i++)    scanf(" %s",a[i]);
    f(0,0,0);
    if(chk) printf("Impossible\n");
    else    printf("%d\n",mn);
    return 0;
}
