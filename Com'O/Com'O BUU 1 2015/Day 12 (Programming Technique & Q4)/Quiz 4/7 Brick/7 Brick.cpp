#include<cstdio>
char a[22][22];
int r,c,top[22],b[22];
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)    scanf(" %s",a[i]);
    for(int i=0;i<c;i++)    scanf("%d",&b[i]);
    for(int j=0;j<c;j++){
        int i=0;
        while(i<r && a[i][j]!='O') i++;
        top[j]=i;
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            if(i>=top[j]-b[j] && i<top[j])  printf("#");
            else    printf("%c",a[i][j]);
        printf("\n");
    }
    return 0;
}
