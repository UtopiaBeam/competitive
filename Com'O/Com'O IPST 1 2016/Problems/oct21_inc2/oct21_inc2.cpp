#include<cstdio>
int n,len=0,a[100002],b[100002];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        int s=1,e=len;
        while(s<=e){
            int m=(s+e)/2;
            if(a[b[m]]<a[i])    s=m+1;
            else    e=m-1;
        }
        b[s]=i;
        if(len<s)   len=s;
    }
    printf("%d\n",len);
    return 0;
}
