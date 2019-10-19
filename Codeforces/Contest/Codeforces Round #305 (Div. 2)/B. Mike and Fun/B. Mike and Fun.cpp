#include<cstdio>
int a[505][505],r,c,n;
int main(){
    scanf("%d %d %d",&r,&c,&n);
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<r;i++){
        int max=0,cnt=0;
        for(int j=0;j<c;j++)
            if(a[i][j])     cnt++;
            else{
                if(max<cnt)     max=cnt;
                cnt=0;
            }
        if(max<cnt)     max=cnt;
        a[i][c]=max;
    }
    while(n--){
        int x,y,max=0,cnt=0;
        scanf("%d %d",&x,&y);
        a[x-1][y-1]=1-a[x-1][y-1];
        for(int j=0;j<c;j++)
            if(a[x-1][j])     cnt++;
            else{
                if(max<cnt)     max=cnt;
                cnt=0;
            }
        if(max<cnt)     max=cnt;
        a[x-1][c]=max;
        max=0;
        for(int i=0;i<r;i++)
            if(max<a[i][c])     max=a[i][c];
        printf("%d\n",max);
    }
    return 0;
}
