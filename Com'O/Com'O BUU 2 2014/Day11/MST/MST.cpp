#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int u,v;
    double w;
}Edge;
Edge e[510000];
int p[1100],h[1100];
int cmp(const void *a,const void *b){
    Edge *A,*B;
    A=(Edge *)a,B=(Edge *)b;
    if(A->w > B->w)     return 1;
    return -1;
}
int find(int i){
    if(p[i]!=i)
        return p[i]=find(p[i]);
    return i;
}
void U(int i,int j){
    if(h[i]>h[j])
        p[j]=i;
    else if(h[i]<h[j])
        p[i]=j;
    else{
        p[j]=i;
        h[i]++;
    }
}
int main(){
    int n,ne,i,t,rootu,rootv;
    double sum=0.0;
    scanf("%d %d",&n,&ne);
    for(i=0;i<ne;i++){
        scanf("%d %d %lf",&e[i].u,&e[i].v,&e[i].w);
        if(e[i].u>e[i].v)
            t=e[i].u,e[i].u=e[i].v,e[i].v=t;
    }
    qsort(e,ne,sizeof(e[0]),cmp);
    for(i=0;i<n;i++)          //Initial Union-Find
        h[i]=0,p[i]=i;
    for(i=0;i<ne;i++){
        rootu=find(e[i].u);
        rootv=find(e[i].v);
        if(rootu!=rootv){
            sum+=e[i].w;
            U(rootu,rootv);
        }
    }
    printf("%.3lf\n",sum);
    return 0;
}
