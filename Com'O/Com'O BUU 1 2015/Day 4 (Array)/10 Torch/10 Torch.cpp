#include<cstdio>
int r,c,x,y;
char a[102][102];
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            scanf(" %c",&a[i][j]);
            a[2*r-i-1][j]=a[i][2*c-j-1]=a[2*r-i-1][2*c-j-1]=a[i][j];
        }
    scanf("%d %d",&x,&y);
    for(int i=0;i<2*r;i++){
        for(int j=0;j<2*c;j++){
            if(i+1==x && j+1==y){
                if(a[i][j]=='#')    printf(".");
                else    printf("#");
            }
            else    printf("%c",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
