#include<cstdio>
int n,a[100005],b[100005],mx=0;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        int s=1,e=mx;
        while(s<=e){
            int m=(s+e)/2;
            if(a[b[m]]>a[i])    e=m-1;
            else    s=m+1;
        }
        b[s]=i;
        if(mx<s)    mx=s;
    }
    printf("%d\n",mx);
    return 0;
}
