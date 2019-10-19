#include<cstdio>
int a[100002],t[100002],n;
void mergesort(void){
    for(int i=1;i<n;i<<=1)
        for(int j=0;j<n-i;j+=i){
            int s=j,e=j+i,m=(s+e)/2;
            int l=s,r=m+1;
            for(int k=s;k<=e;k++)
                if(l>m)     t[k]=a[r++];
                else if(r>e)    t[k]=a[l++];
                else if(a[l]<=a[r]) t[k]=a[l++];
                else    t[k]=a[r++];
            for(int k=s;k<=e;k++)   a[k]=t[k];
        }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)    scanf("%d",&a[i]);
    mergesort();
    for(int i=0;i<n;i++)    printf("%d\n",a[i]);
    return 0;
}
