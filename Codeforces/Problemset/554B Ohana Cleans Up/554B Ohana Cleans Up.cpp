#include<cstdio>
#include<cstring>
char a[105][105];
int n,mx=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf(" %s",a[i]);
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n;j++)
            if(!strcmp(a[i],a[j]))  cnt++;
        if(mx<cnt)  mx=cnt;
    }
    printf("%d\n",mx);
    return 0;
}
