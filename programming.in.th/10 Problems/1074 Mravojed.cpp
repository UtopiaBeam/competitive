#include<cstdio>
char a[110][110];
int main(){
    int r,c,x,y,s,x1=1,y1=1,s1=1;
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)
        scanf(" %s",a[i]);
    for(int i=0,chk=1;i<r && chk;i++)
        for(int j=0;j<c && chk;j++){
            int size=0;
            if(a[i][j]=='x'){
                while(i+size<r && j+size<c && a[i+size][j]=='x' && a[i][j+size]=='x' && a[i+size][j+size]=='x')   size++;
                printf("%d %d %d\n",i+1,j+1,size);
                chk=0,x=i,y=j,s=size;
            }
        }
    int chk=1;
    for(int i=r-1;i>=0 && chk;i--)
        for(int j=c-1;j>=0 && chk;j--){
            int size=0;
            if(a[i][j]=='x'){
                while(i-size>=0 && j-size>=0 && a[i-size][j]=='x' && a[i][j-size]=='x' && a[i-size][j-size]=='x')   size++;
                if(x>i-size+1 || i>x+s-1 || y>j-size+1 ||j>y+s-1){
                    printf("%d %d %d\n",i-size+2,j-size+2,size);
                    chk=0;
                }
                else if(x<=i-size+1 && i<=x+s-1 && y<=j-size+1 && j<=y+s-1)      continue;
                else    x1=i,y1=j,s1=size;
            }
        }
    if(chk)     printf("%d %d %d\n",x1-s1+2,y1-s1+2,s1);
    return 0;
}
