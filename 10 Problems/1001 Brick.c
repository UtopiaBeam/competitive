#include<stdio.h>
int r,c,str[50],end[50],bri;
char a[50][50];
int main(){
    int i,j;
    scanf("%d %d",&r,&c);
    for(i=0;i<c;i++)
        str[i]=0,end[i]=r-1;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='O' && end[j]==r-1 && end[j]>0)
            end[j]=i-1;
        }
    for(i=0;i<c;i++){
        scanf("%d",&bri);
        if(end[i]-bri>=0)   str[i]=end[i]-bri+1;
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
            if(str[j]<=i && end[j]>=i)
                printf("#");
            else    printf("%c",a[i][j]);
        printf("\n");
    }
    return 0;
}
