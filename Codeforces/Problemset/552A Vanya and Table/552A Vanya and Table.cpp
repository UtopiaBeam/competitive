#include<cstdio>
int a[105][105],n,x1,y1,x2,y2,sum=0;
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(int i=x1;i<=x2;i++)
            for(int j=y1;j<=y2;j++)
                a[i][j]++;
    }
    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
            sum+=a[i][j];
    printf("%d\n",sum);
    return 0;
}
