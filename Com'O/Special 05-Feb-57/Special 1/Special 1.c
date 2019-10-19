#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int x,y;
}point;
point p[100010];
int cmp(const void* a,const void* b){
    point *A,*B;
    A=(point *)a,B=(point *)b;
    if(A->x < B->x)     return 1;
    else if(A->x > B->x)    return -1;
    else{
        if(A->y > B->y)     return 1;
        return -1;
    }
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&p[i].x,&p[i].y);
    qsort(p,n,sizeof(p[0]),cmp);
    for(i=0;i<n;i++)
        printf("%d %d\n",p[i].x,p[i].y);
    return 0;
}
