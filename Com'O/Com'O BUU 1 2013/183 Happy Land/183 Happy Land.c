#include<stdio.h>
double a[5][5],min=-1u/2,sum=0.00;
int r,c,b[5][5];
void play(int i,int j,int cnt){
    int m,n;
    double k;
    if(i>r||j>c||b[i][j]==1)    return ;
    k=a[i][j],sum+=k,b[i][j]=1;
    if(cnt==r*c){

        if(min>sum)     min=sum;
        sum-=k; b[i][j]=0;
        return ;
    }
    a[i-1][j-1]+=k*0.10;  a[i-1][j]+=k*0.10;
    a[i-1][j+1]+=k*0.10;  a[i][j+1]+=k*0.10;
    a[i+1][j+1]+=k*0.10;  a[i+1][j]+=k*0.10;
    a[i+1][j-1]+=k*0.10;  a[i][j-1]+=k*0.10;
    play(1,1,cnt+1);    play(1,2,cnt+1);    play(1,3,cnt+1);
    play(2,1,cnt+1);    play(2,2,cnt+1);    play(2,3,cnt+1);
    play(3,1,cnt+1);    play(3,2,cnt+1);    play(3,3,cnt+1);
    a[i-1][j-1]-=k*0.10;  a[i-1][j]-=k*0.10;
    a[i-1][j+1]-=k*0.10;  a[i][j+1]-=k*0.10;
    a[i+1][j+1]-=k*0.10;  a[i+1][j]-=k*0.10;
    a[i+1][j-1]-=k*0.10;  a[i][j-1]-=k*0.10;
    sum-=k,b[i][j]=0;
}
int main(){
    int i,j;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            scanf("%lf",&a[i][j]);
    for(i=1;i<=r;i++)
        for(j=1,sum=0.00;j<=c;j++,sum=0.00)
            play(i,j,1);
    printf("%.2lf\n",min);
    return 0;
}
