#include<stdio.h>
#include<string.h>
#include<ctype.h>
char a[50][50],b[20];
int stri,strj,r,c,len,mark[50][50],chk;
void up(int i,int j,int cnt){
    if(cnt==len-1){
        printf("%d %d\n",stri,strj);
        chk=0;  return ;
    }
    if(i>0 && a[i-1][j]==b[cnt+1] && mark[i-1][j]!=1){
        mark[i-1][j]=1;    up(i-1,j,cnt+1);
        mark[i-1][j]=0;
    }
}
void down(int i,int j,int cnt){
    if(cnt==len-1){
        printf("%d %d\n",stri,strj);
        chk=0;  return ;
    }
    if(i<r-1 && a[i+1][j]==b[cnt+1] && mark[i+1][j]!=1){
        mark[i+1][j]=1;    down(i+1,j,cnt+1);
        mark[i+1][j]=0;
    }
}
void left(int i,int j,int cnt){
    if(cnt==len-1){
        printf("%d %d\n",stri,strj);
        chk=0;  return ;
    }
    if(j>0 && a[i][j-1]==b[cnt+1] && mark[i][j-1]!=1){
        mark[i][j-1]=1;    left(i,j-1,cnt+1);
        mark[i][j-1]=0;
    }
}
void right(int i,int j,int cnt){
    if(cnt==len-1){
        printf("%d %d\n",stri,strj);
        chk=0;  return ;
    }
    if(j<c-1 && a[i][j+1]==b[cnt+1] && mark[i][j+1]!=1){
        mark[i][j+1]=1;    right(i,j+1,cnt+1);
        mark[i][j+1]=0;
    }
}
void upleft(int i,int j,int cnt){
    if(cnt==len-1){
        printf("%d %d\n",stri,strj);
        chk=0;  return ;
    }
    if(i>0 && j>0 && a[i-1][j-1]==b[cnt+1] && mark[i-1][j-1]!=1){
        mark[i-1][j-1]=1;  upleft(i-1,j-1,cnt+1);
        mark[i-1][j-1]=0;
    }
}
void upright(int i,int j,int cnt){
    if(cnt==len-1){
        printf("%d %d\n",stri,strj);
        chk=0;  return ;
    }
    if(i>0 && j<c-1 && a[i-1][j+1]==b[cnt+1] && mark[i-1][j+1]!=1){
        mark[i-1][j+1]=1;  upright(i-1,j+1,cnt+1);
        mark[i-1][j+1]=0;
    }
}
void downleft(int i,int j,int cnt){
    if(cnt==len-1){
        printf("%d %d\n",stri,strj);
        chk=0;  return ;
    }
    if(i<r-1 && j>0 && a[i+1][j-1]==b[cnt+1] && mark[i+1][j-1]!=1){
        mark[i+1][j-1]=1;   downleft(i+1,j-1,cnt+1);
        mark[i+1][j-1]=0;
    }
}
void downright(int i,int j,int cnt){
    if(cnt==len-1){
        printf("%d %d\n",stri,strj);
        chk=0;  return ;
    }
    if(i<r-1 && j<c-1 && a[i+1][j+1]==b[cnt+1] && mark[i+1][j+1]!=1){  //Downright
        mark[i+1][j+1]=1;  downright(i+1,j+1,cnt+1);
        mark[i+1][j+1]=0;
    }
}
int main(){
    int i,j,q;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            scanf(" %c",&a[i][j]);
            a[i][j]=tolower(a[i][j]);
        }
    scanf("%d",&q);
    while(q--){
        chk=1;
        scanf(" %s",b);
        len=strlen(b);
        for(i=0;i<len;i++)
            b[i]=tolower(b[i]);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++){
                if(a[i][j]==b[0] && chk){
                    stri=i,strj=j;
                    mark[i][j]=1;
                    up(i,j,0);
                    if(chk)     down(i,j,0);
                    if(chk)     left(i,j,0);
                    if(chk)     right(i,j,0);
                    if(chk)     upleft(i,j,0);
                    if(chk)     upright(i,j,0);
                    if(chk)     downleft(i,j,0);
                    if(chk)     downright(i,j,0);
                    mark[i][j]=0;
                }
            }
    }
    return 0;
}
