#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string a[70],b;
int bs(int p,int q){
    if(p>=q)    return -1;
    int mid=(p+q)/2;
    if(!strcmp(a[mid],b))   return mid;
    else if(strcmp(a[mid],b)==-1)    bs(p,mid-1);
    else        bs(mid+1,q);
}
int main(){
    int n,m,k,i,in;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<n;i++)
        scanf(" %s",a[i]);
    sort(a,a+n);
    while(m--){
        scanf(" %s",b);
        in=bs(0,n-1);
        if(in!=-1)  printf("Accepted\n");
        else        printf("Rejected\n");
    }
    return 0;
}
