#include<cstdio>
int r,c,bi[]={-1,1,0,0},bj[]={0,0,-1,1},ci[]={-1,-1,1,1},cj[]={-1,1,-1,1},cnt=0;
char a[1002][1002];
int main(){
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='A')    cnt++;
        }
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(a[i][j]=='+'){
                a[i][j]='.';
                for(int k=0;k<4;k++)
                    if(i+bi[k]>=0 && i+bi[k]<r && j+bj[k]>=0 && j+bj[k]<c && a[i+bi[k]][j+bj[k]]=='A')
                        a[i+bi[k]][j+bj[k]]='.',cnt--;
            }
            else if(a[i][j]=='x'){
                a[i][j]='.';
                for(int k=0;k<4;k++){
                    if(i+ci[k]>=0 && i+ci[k]<r && j+cj[k]>=0 && j+cj[k]<c && a[i+ci[k]][j+cj[k]]=='A')
                        a[i+ci[k]][j+cj[k]]='.',cnt--;
                    if(i+ci[k]*2>=0 && i+ci[k]*2<r && j+cj[k]*2>=0 && j+cj[k]*2<c && a[i+ci[k]*2][j+cj[k]*2]=='A')
                        a[i+ci[k]*2][j+cj[k]*2]='.',cnt--;
                }
            }
    printf("%d\n",cnt);
    for(int i=0;i<r;i++)
        printf("%s\n",a[i]);
    return 0;
}
