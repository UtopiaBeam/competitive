#include<cstdio>
int r,c,chk=0;
char ch;
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            scanf(" %c",&ch);
            if(ch!='B' && ch!='G' && ch!='W')
                chk=1;
        }
    if(chk)     printf("#Color");
    else        printf("#Black&White");
    return 0;
}
