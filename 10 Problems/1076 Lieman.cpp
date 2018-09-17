#include<cstdio>
#define bit (k>>j)%2
int a[25][25],b[25],n,m,min=100;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    for(int k=0;k<(1<<m);k++){
        int cnt=0;
        for(int i=0;i<n;i++){
            b[i]=0;
            for(int j=0;j<m;j++){
                if((a[i][j]==1 && bit==0) || (a[i][j]==-1 && bit==1)){
                    b[i]=1;     break;
                }
            }
        }
        for(int i=0;i<n;i++)    cnt+=b[i];
        if(min>cnt)     min=cnt;
    }
    printf("%d\n",min);
    return 0;
}
