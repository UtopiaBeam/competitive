#include<cstdio>
int a[105];
int main(){
    int n,m,sum=0,cnt=1;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        if(sum+a[i]>m)      cnt++,i--,sum=0;
        else    sum+=a[i];
    }
    printf("%d\n",cnt);
    return 0;
}
