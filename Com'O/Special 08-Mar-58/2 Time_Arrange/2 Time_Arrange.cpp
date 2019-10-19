//Interval Scheduling Problem
#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int str,end;
}room;
room a[100010];
int n;
int cmp(const void *a,const void *b){
    room *aa=(room *)a,*bb=(room *)b;
    if(aa->end != bb->end)  return aa->end - bb->end;
    return aa->str - bb->str;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d %d",&a[i].str,&a[i].end);
    qsort(a,n,sizeof(room),cmp);
    int last=0,cnt=1;
    for(int i=1;i<n;i++){
        if(a[i].str<a[last].end)    continue;
        last=i,cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
