#include<cstdio>
int n,m,k,sx[40002],sy[40002],ex[40002],ey[40002],x,y;
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf("%d %d %d %d",&sx[i],&sy[i],&ex[i],&ey[i]);
    for(int i=0;i<m;i++){
        scanf("%d %d",&x,&y);
        int cnt=0;
        for(int j=0;j<n;j++)
            if(sx[j]<=x && sy[j]<=y && ex[j]>=x && ey[j]>=y)
                cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
