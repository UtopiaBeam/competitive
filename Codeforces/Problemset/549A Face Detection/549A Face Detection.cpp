#include<cstdio>
char a[55][55];
int r,c,cnt=0;
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)
        scanf(" %s",a[i]);
    for(int i=1;i<r;i++)
        for(int j=1;j<c;j++){
            bool b1=false,b2=false,b3=false,b4=false;
            for(int k=-1;k<1;k++)
                for(int l=-1;l<1;l++){
                    if(a[i+k][j+l]=='f')    b1=true;
                    if(a[i+k][j+l]=='a')    b2=true;
                    if(a[i+k][j+l]=='c')    b3=true;
                    if(a[i+k][j+l]=='e')    b4=true;
                }
            if(b1 && b2 && b3 && b4)    cnt++;
        }
    printf("%d\n",cnt);
    return 0;
}
