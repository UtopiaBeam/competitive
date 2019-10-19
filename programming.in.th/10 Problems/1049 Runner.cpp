#include<stdio.h>
int lane[100010],spd[100010][3],round=0;
int main(){
    int m,n;
    scanf("%d %d\n",&n,&m);
    for(int i=0;i<n;i++){
        int a,l,s;
        scanf("%d %d %d",&a,&l,&s);
        if(spd[lane[l]][2]<s)
            spd[lane[l]][0]=a,spd[lane[l]][1]=l,spd[lane[l]][2]=s;
        else if(s==spd[lane[l]][2] && l<spd[lane[l]][1])
            spd[lane[l]][0]=a,spd[lane[l]][1]=l,spd[lane[l]][2]=s;
        lane[l]++;
        if(round<lane[l])   round=lane[l];
    }
    for(int i=0;i<round;i++)
        printf("%d\n",spd[i][0]);
    return 0;
}
