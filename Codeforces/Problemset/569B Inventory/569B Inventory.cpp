#include<cstdio>
int n,a[100005],b[100005],nw=1;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[a[i]]++;
    }
    for(int i=0;i<n;i++)
        if(a[i]<=n && b[a[i]]==1)      printf("%d ",a[i]);
        else{
            while(b[nw])    nw++;
            printf("%d ",nw++);
            b[a[i]]--;
        }
    return 0;
}