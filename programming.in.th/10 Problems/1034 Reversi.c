#include<stdio.h>
#include<string.h>
int a[10][10],turn=1;
void n(int x,int y){
    int i,j;
    for(i=1;i<=8;i++){
        if(x-i<1||a[x-i][y]==-1)  return ;
        if(a[x-i][y]==turn){
            for(j=1;j<i;j++)
                a[x-j][y]=turn;
            return ;
        }
    }
}
void e(int x,int y){
    int i,j;
    for(i=1;i<=8;i++){
        if(y+i>8||a[x][y+i]==-1)   return ;
        if(a[x][y+i]==turn){
            for(j=1;j<i;j++)
                a[x][y+j]=turn;
            return ;
        }
    }
}
void s(int x,int y){
    int i,j;
    for(i=1;i<=8;i++){
        if(x+i>8||a[x+i][y]==-1)   return ;
        if(a[x+i][y]==turn){
            for(j=1;j<i;j++)
                a[x+j][y]=turn;
            return ;
        }
    }
}
void w(int x,int y){
    int i,j;
    for(i=1;i<=8;i++){
        if(y-i<1||a[x][y-i]==-1)   return ;
        if(a[x][y-i]==turn){
            for(j=1;j<i;j++)
                a[x][y-j]=turn;
            return ;
        }
    }
}
void ne(int x,int y){
    int i,j;
    for(i=1;i<=8;i++){
        if(x-i<1||y+i>8||a[x-i][y+i]==-1)    return ;
        if(a[x-i][y+i]==turn){
            for(j=1;j<i;j++)
                a[x-j][y+j]=turn;
            return ;
        }
    }
}

void se(int x,int y){
    int i,j;
    for(i=1;i<=8;i++){
        if(x+i>8||y+i>8||a[x+i][y+i]==-1)    return ;
        if(a[x+i][y+i]==turn){
            for(j=1;j<i;j++)
                a[x+j][y+j]=turn;
            return ;
        }
    }
}
void nw(int x,int y){
    int i,j;
    for(i=1;i<=8;i++){
        if(x-i<1||y-i<1||a[x-i][y-i]==-1)    return ;
        if(a[x-i][y-i]==turn){
            for(j=1;j<i;j++)
                a[x-j][y-j]=turn;
            return ;
        }
    }
}
void sw(int x,int y){
    int i,j;
    for(i=1;i<=8;i++){
        if(x+i>8||y-i<1||a[x+i][y-i]==-1)    return ;
        if(a[x+i][y-i]==turn){
            for(j=1;j<i;j++)
                a[x+j][y-j]=turn;
            return ;
        }
    }
}
int main(){
    int k,i,j;
    memset(a,-1,sizeof(a));
    a[4][4]=a[5][5]=0,a[4][5]=a[5][4]=1;
    scanf("%d",&k);
    while(k--){
        int x,y;
        char ch;
        scanf(" %c %d",&ch,&x);
        a[x][y=ch-'a'+1]=turn;
        n(x,y); ne(x,y);
        e(x,y); se(x,y);
        s(x,y); sw(x,y);
        w(x,y); nw(x,y);
        turn=1-turn;
    }
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++){
            if(a[i][j]==-1)     printf(".");
            if(a[i][j]==0)      printf("O");
            if(a[i][j]==1)      printf("X");
        }
        printf("\n");
    }
    return 0;
}
