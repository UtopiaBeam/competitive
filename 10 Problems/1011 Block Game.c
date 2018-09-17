#include<stdio.h>
char a[10][10];
int r,c,scr=0;
void drop(){
    int i,j;
    for(i=0;i<r-1;i++)
        for(j=0;j<c;j++)
            if(a[i][j]!='#' && a[i][j]!='-' && a[i+1][j]=='-')
                a[i+1][j]=a[i][j],a[i][j]='-';
}
void clear(int i,int j){
    char ch=a[i][j];
    scr+=5,a[i][j]='-';
    if(a[i][j-1]==ch)   clear(i,j-1);
    if(a[i][j+1]==ch)   clear(i,j+1);
    if(a[i+1][j]==ch)   clear(i+1,j);
}
int main(){
    int i,j,k,n,x,y;
    char ch;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf(" %c",&a[i][j]);
    scanf("%d",&n);
    while(n--){
        scanf("%d %d %c",&x,&y,&ch);
        if(ch=='L'){
            if(y<1||a[x][y-1]!='-'||a[x][y]=='#'||a[x][y]=='-'){
                scr-=5; continue;
            }
            else{
                a[x][y-1]=a[x][y],a[x][y]='-';
            }
        }
        else{
            if(y>=r-1||a[x][y+1]!='-'||a[x][y]=='#'||a[x][y]=='-'){
                scr-=5; continue;
            }
            else{
                a[x][y+1]=a[x][y],a[x][y]='-';
            }
        }
        for(k=0;k<3;k++){
            drop();
            for(i=0;i<r-1;i++)
                for(j=1;j<c-1;j++)
                    if(a[i][j]!='#'&& a[i][j]!='-' && (a[i][j]==a[i+1][j]||a[i][j]==a[i][j-1]||a[i][j]==a[i][j+1]))
                        clear(i,j);
        }
    }
    printf("%d\n",scr);
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            printf("%c ",a[i][j]);
        printf("\n");
    }
}
