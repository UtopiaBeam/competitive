#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int data1[100010];
double data2[100010];
char data3[100010],data4[100010][110];
int cmp1(const void* a,const void* b){
    if(*(int *)a > *(int *)b)   return 1;
    return -1;
    //return *(int *)a - *(int *)b;
}
int cmp2(const void* a,const void* b){
    if(*(double *)a>*(double *)b)   return 1;
    return -1;
}
int cmp3(const void* a,const void* b){
    if(*(char *)a>*(char *)b)   return 1;
    return -1;
}
int cmp4(const void* a,const void* b){
    return strcmp(a,b);
}
int main(){
    int type,n,i;
    scanf("%d %d",&type,&n);
    if(type==1){
        for(i=0;i<n;i++)
            scanf("%d",&data1[i]);
        qsort(data1,n,sizeof(int),cmp1);
        for(i=0;i<n;i++)
            printf((i!=n-1)? "%d ":"%d\n",data1[i]);
        for(i=n-1;i>=0;i--)
            printf((i!=0)? "%d ":"%d\n",data1[i]);
    }
    if(type==2){
        for(i=0;i<n;i++)
            scanf("%lf",&data2[i]);
        qsort(data2,n,sizeof(double),cmp2);
        for(i=0;i<n;i++)
            printf((i!=n-1)? "%.0lf ":"%.0lf\n",data2[i]);
        for(i=n-1;i>=0;i--)
            printf((i!=0)? "%.0lf ":"%.0lf\n",data2[i]);
    }
    if(type==3){
        for(i=0;i<n;i++)
            scanf(" %c",&data3[i]);
        qsort(data3,n,sizeof(char),cmp3);
        for(i=0;i<n;i++)
            printf((i!=n-1)? "%c ":"%c\n",data3[i]);
        for(i=n-1;i>=0;i--)
            printf((i!=0)? "%c ":"%c\n",data3[i]);
    }
    if(type==4){
        for(i=0;i<n;i++)
            scanf(" %s",data4[i]);
        qsort(data4,n,sizeof(data4[0]),cmp4);
        for(i=0;i<n;i++)
            printf((i!=n-1)? "%s ":"%s\n",data4[i]);
        for(i=n-1;i>=0;i--)
            printf((i!=0)? "%s ":"%s\n",data4[i]);
    }
    return 0;
}
