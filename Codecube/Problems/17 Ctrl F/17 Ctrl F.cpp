#include<cstdio>
char a[1005],b[1005];
int n,m,cnt=0;
int main(){
    scanf("%d %d %s %s",&n,&m,a,b);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i+j]!=b[j])  break;
            if(j==m-1)      cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
