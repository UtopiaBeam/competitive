#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int pro[15],in;
}chem;
chem ch[100010];
int n,p;
int cmp(const void *a,const void *b){
    chem *aa=(chem *)a,*bb=(chem *)b;
    for(int i=0;i<p;i++){
        if(aa->pro[i] > bb->pro[i])     return 1;
        if(aa->pro[i] < bb->pro[i])     return -1;
    }
    return 0;
}
int b[15];
int bs(int str,int end){
    if(str>end)     return -1;
    int mid=(str+end)/2;
    for(int i=0;i<p;i++){
        if(ch[mid].pro[i]>b[i])    return bs(0,mid-1);
        if(ch[mid].pro[i]<b[i])    return bs(mid+1,end);
    }
    return mid;
}
int main(){
    scanf("%d %d",&n,&p);
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++)
            scanf("%d",&ch[i].pro[j]);
        ch[i].in=i+1;
    }
    qsort(ch,n,sizeof(chem),cmp);
    for(int i=0;i<p;i++)
        scanf("%d",&b[i]);
    int x=bs(0,n-1);
    if(x>=0)     printf("%d\n",ch[x].in);
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++)
                b[j]-=ch[i].pro[j];
            x=bs(i,n-1);
            if(x>=0 && x!=i){
                if(ch[i].in<ch[x].in)
                    printf("%d %d\n",ch[i].in,ch[x].in);
                else    printf("%d %d\n",ch[x].in,ch[i].in);
                return 0;
            }
            for(int j=0;j<p;j++)
                b[j]+=ch[i].pro[j];
        }
        printf("NO\n");
    }
    return 0;
}
