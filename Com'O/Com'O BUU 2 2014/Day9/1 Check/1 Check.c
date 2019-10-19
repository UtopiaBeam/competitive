//Bishop
#include<stdio.h>
char a[10][10];
int chk=1;
int main(){
    int i,j,k;
    for(i=0;i<8;i++)
        scanf(" %s",a[i]);
    for(i=0;i<8;i++)
        for(j=0;j<8;j++){
            if(a[i][j]=='k')
                if((i>1&&a[i-1][j]=='K')||(j>1&&a[i][j-1]=='K')||(i<8&&a[i+1][j]=='K')||(j<7&&a[i][j+1]=='K')
                   ||(i>1&&j>1&&a[i-1][j-1]=='K')||(i>1&&j<7&&a[i-1][j+1]=='K')||(i<7&&j>0&&a[i+1][j-1]=='K')||(i<7&&j<7&&a[i+1][j+1]=='K'))
                    printf("k check white king.\n"),chk=0;
            if(a[i][j]=='K'&&chk)
                if((i>1&&a[i-1][j]=='k')||(j>1&&a[i][j-1]=='k')||(i<8&&a[i+1][j]=='k')||(j<7&&a[i][j+1]=='k')
                   ||(i>1&&j>1&&a[i-1][j-1]=='k')||(i>1&&j<7&&a[i-1][j+1]=='k')||(i<7&&j>0&&a[i+1][j-1]=='k')||(i<7&&j<7&&a[i+1][j+1]=='k'))
                    printf("K check black king.\n"),chk=0;
            if(a[i][j]=='r')
                for(k=0;k<8&&chk;k++)
                    if(a[i][k]=='K'||a[k][j]=='K')
                        printf("r check white king.\n"),chk=0;
            if(a[i][j]=='R')
                for(k=0;k<8&&chk;k++)
                    if(a[i][k]=='k'||a[k][j]=='k')
                        printf("R check black king.\n"),chk=0;
            if(a[i][j]=='b'&&chk)
                for(k=0;k<8&&chk;k++)
                    ;
            if(a[i][j]=='B'&&chk)
                for(k=0;k<8&&chk;k++)
                    ;
            if(a[i][j]=='p'&&chk)
                if(i<7&&(j>0&&a[i+1][j-1]=='K')||(j<7&&a[i+1][j+1]=='K'))
                    printf("p check white king.\n"),chk=0;
            if(a[i][j]=='P'&&chk)
                if(i>0&&(j>0&&a[i-1][j-1]=='k')||(j<7&&a[i-1][j+1]=='k'))
                    printf("P check black king.\n"),chk=0;
        }
    if(chk)     printf("No king is in check.\n");
    return 0;
}
