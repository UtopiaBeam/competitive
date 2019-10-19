#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int goal,shot,scr;
    char name[30];
}pnt;
pnt team[10];
int a[10][10];
int cmp(const void *a,const void *b){
    pnt *aa,*bb;
    aa=(pnt *)a,bb=(pnt *)b;
    if(aa->scr > bb->scr)   return -1;
    else if(aa->scr < bb->scr)  return 1;
    else if(aa->goal-aa->shot > bb->goal-bb->shot)   return -1;
    else if(aa->goal-aa->shot < bb->goal-bb->shot)  return 1;
    else if(aa->goal > bb->goal)    return -1;
    else    return 1;
}
int main(){
    int i,j;
    for(i=0;i<4;i++){
        scanf(" %s",team[i].name);
        team[i].goal=0,team[i].scr=0,team[i].shot=0;
    }
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<4;i++)
        for(j=0;j<4;j++){
            team[i].goal+=a[i][j],team[j].shot+=a[i][j];
            if(a[i][j]>a[j][i])
                team[i].scr+=3;
            else if(a[i][j]==a[j][i] && i!=j)
                team[i].scr++;
        }
    qsort(team,4,sizeof(pnt),cmp);
    for(i=0;i<4;i++)
        printf("%s %d\n",team[i].name,team[i].scr);
    return 0;
}
