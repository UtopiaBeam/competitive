#include<stdio.h>
int n,m,a[1010][4]; //x1,y1,x2,y2
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<4;j++)
            scanf("%d",&a[i][j]);
    while(m--){
        int x1,y1,x2,y2,cnt=0;
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(int i=0;i<n;i++){
            if((a[i][0]<=x1 && x1<a[i][2]) || (a[i][0]<x2 && x2<=a[i][2]) || (x1<=a[i][0] && a[i][2]<=x2)){
                if(a[i][1]<=y2 || a[i][3]>=y1)  continue;
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
