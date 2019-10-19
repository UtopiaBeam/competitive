#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[10010][70],b[70];
int bs(int p,int q){
    if(p>q)    return -1;
    int mid=(p+q)/2;
    if(strcmp(a[mid],b)==0)          return mid;
    else if(strcmp(a[mid],b)>0)     bs(p,mid-1);
    else if(strcmp(a[mid],b)<0)    bs(mid+1,q);
}
int cmp(const void *a,const void *b){
    return strcmp(a,b);
}
int main(){
    int n,m,k,i,in;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<n;i++)
        scanf(" %s",a[i]);
    qsort(a,n,sizeof(a[0]),cmp);
    while(m--){
        scanf(" %s",b);
        in=bs(0,n-1);
        if(in!=-1)      printf("Accepted\n");
        else            printf("Rejected\n");
    }
    return 0;
}
