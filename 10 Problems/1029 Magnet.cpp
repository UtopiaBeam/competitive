#include<cstdio>
#include<algorithm>
using namespace std;
int a[200010]={1},ans;
void bsearch(int str,int end,int n){
    int mid=(str+end)/2;
    if(a[mid]<=n && n<a[mid+1]){
        ans=a[mid+1]-a[mid];
        return ;
    }
    else if(n<a[mid])    bsearch(str,mid,n);
    else if(n>a[mid])    bsearch(mid,end,n);
}
int main(){
    int str,len,n,m,q,i,j,in=1;
    scanf("%d %d %d",&m,&n,&q);
    while(n--){
        scanf("%d %d",&str,&len);
        if(str!=1)  a[in++]=str;
        if(str+len<=m)  a[in++]=str+len;
    }
    sort(a,a+in);
    for(i=1;i<in-1;i++)
        if(a[i]==a[i+1])    a[i]=a[i+1]=0,i++;
    sort(a,a+in);
    str=0;
    while(a[str]==0)    str++;
    while(q--){
        scanf("%d",&n);
        if(n>=a[in-1]) printf("%d\n",m-a[in-1]+1);
        else{
            bsearch(str,in,n);
            printf("%d\n",ans);
        }
    }
    return 0;
}
