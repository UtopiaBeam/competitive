#include<cstdio>
int r,c,a[305][305],max=-2e9;
int main(){
    scanf("%d %d",&r,&c);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++){
            scanf("%d",&a[i][j]);
            a[i][j]+=a[i-1][j];
        }
    for(int i=1;i<r;i++)
        for(int j=i+1;j<=r;j++){
            int max_all=-2e9,max_here=0,ne=1;
            for(int k=1;k<=c;k++){
                max_here+=a[j][k]-a[i-1][k];
                if(max_here<0)      max_here=0;
                if(max_all<max_here) max_all=max_here;
                if(a[j][k]-a[i-1][k]>0)   ne=0;
            }
            if(max<max_all)     max=max_all;
        }
    printf("%d\n",max);
    return 0;
}
