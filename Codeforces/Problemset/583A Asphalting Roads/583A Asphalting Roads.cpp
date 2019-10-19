#include<cstdio>
int a[55][2],b[2505][2],n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n*n;i++)
        scanf("%d %d",&b[i][0],&b[i][1]);
    for(int i=0;i<n*n;i++)
        if(!a[b[i][0]][0] && !a[b[i][1]][1]){
            printf("%d ",i+1);
            a[b[i][0]][0]=a[b[i][1]][1]=1;
        }
    return 0;
}
