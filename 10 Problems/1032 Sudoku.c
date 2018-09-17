#include<stdio.h>
int ini[10][10],a[10][10];
int main(){
    int n,i,j,k,sum,chk;
    scanf("%d",&n);
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
            scanf("%d",&ini[i][j]);
    for(k=1;k<=n;k++){
        chk=1;
        for(i=0;i<9;i++)
            for(j=0;j<9;j++){
                scanf("%d",&a[i][j]);
                if(ini[i][j]!=0 && a[i][j]!=ini[i][j])  chk=0;
            }
        if(!chk)    continue;
        for(i=0;i<9 && chk;i++){
            sum=0,chk=1;
            for(j=0;j<9;j++)
                sum+=a[i][j];
            if(sum!=45)     chk=0;
        }
        for(i=0;i<9 && chk;i++){
            sum=0,chk=1;
            for(j=0;j<9;j++)
                sum+=a[j][i];
            if(sum!=45)     chk=0;
        }
        if(chk)     printf("%d\n",k);
    }
    printf("END\n");
    return 0;
}
