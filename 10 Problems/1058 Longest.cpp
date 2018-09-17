#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char a[1010][1010];
int mic[1010][1010][4],r,c,k,Max;   //0->right 1->down 2->left 3->up
int main(){
    scanf("%d",&k);
    while(k--){
        Max=0;
        scanf("%d %d",&r,&c);
        for(int i=0;i<r;i++)
            scanf(" %s",a[i]);
        for(int k=0;k<4;k++)
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    mic[i][j][k]=a[i][j]-'0';
        for(int i=0;i<r;i++)
            for(int j=1;j<c;j++){
                if(a[i][j]=='0')  continue;
                mic[i][j][0]=1+mic[i][j-1][0];
            }
        for(int j=0;j<c;j++)
            for(int i=1;i<r;i++){
                if(a[i][j]=='0')  continue;
                mic[i][j][1]=1+mic[i-1][j][1];
            }
        for(int i=0;i<r;i++)
            for(int j=c-2;j>=0;j--){
                if(a[i][j]=='0')  continue;
                mic[i][j][2]=1+mic[i][j+1][2];
            }
        for(int j=0;j<c;j++)
            for(int i=r-2;i>=0;i--){
                if(a[i][j]=='0')  continue;
                mic[i][j][3]=1+mic[i+1][j][3];
            }
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++){
                if(Max<mic[i][j][0]+mic[i][j][1]-1)
                    Max=mic[i][j][0]+mic[i][j][1]-1;
                if(Max<mic[i][j][0]+mic[i][j][3]-1)
                    Max=mic[i][j][0]+mic[i][j][3]-1;
                if(Max<mic[i][j][2]+mic[i][j][1]-1)
                    Max=mic[i][j][2]+mic[i][j][1]-1;
                if(Max<mic[i][j][2]+mic[i][j][3]-1)
                    Max=mic[i][j][2]+mic[i][j][3]-1;
            }
        printf("%d\n",Max);
    }
    return 0;
}
