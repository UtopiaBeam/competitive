#include<cstdio>
int n,a[100005],t[100005];
void merge(int str,int mid,int end){
    int front=str,back=mid+1;
    for(int i=str;i<=end;i++){
        if(front>mid)       t[i]=a[back++];
        else if(back>end)   t[i]=a[front++];
        else if(a[front]<a[back])
            t[i]=a[front++];
        else    t[i]=a[back++];
    }
    for(int i=str;i<=end;i++)
        a[i]=t[i];
}
void mergesort(int str,int end){
    if(str>=end)    return ;
    int mid=(str+end)/2;
    mergesort(str,mid);     mergesort(mid+1,end);
    merge(str,mid,end);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
