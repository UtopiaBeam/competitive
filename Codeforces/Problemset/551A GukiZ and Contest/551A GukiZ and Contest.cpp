#include<cstdio>
int a[2005],n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        int cnt=1;
        for(int j=0;j<n;j++)
            if(a[i]<a[j])   cnt++;
        printf("%d ",cnt);
    }
    return 0;
}
