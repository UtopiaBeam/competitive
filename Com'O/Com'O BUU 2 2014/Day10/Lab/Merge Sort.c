#include<stdio.h>
#include<time.h>
#define n 100000000
int a[n],t[n];
void merge(int left,int mid,int right){
    int i,j,k;
    i=left,j=mid+1;
    for(k=left;k<=right;k++){
        if(i>mid){
            t[k]=a[j++];
            continue;
        }
        if(j>right){
            t[k]=a[i++];
            continue;
        }
        if(a[i]<a[j])   t[k]=a[i++];
        else    t[k]=a[j++];
    }
    for(k=left;k<=right;k++)
        a[k]=t[k];
}
void msort(int left,int right){
    int mid;
    if(left>=right)     return ;
    mid=(left+right)/2;
    msort(left,mid);      msort(mid+1,right);
    merge(left,mid,right);
}
int main(){
    int i,j;
    clock_t str;
    str=clock();
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    msort(0,n-1);
    str=clock()-str;
    printf("%lf\n",(double)str/CLOCKS_PER_SEC);
    return 0;
}
