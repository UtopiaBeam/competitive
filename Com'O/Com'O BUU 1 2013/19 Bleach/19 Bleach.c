//Uncomplete
#include<stdio.h>

int main()
{
    int Y,D1,M1,D2,M2,D_dif,M_dif,cnt_30,cnt_31;
    scanf("%d %d %d %d %d",&Y,&D1,&M1,&D2,&M2);
    if(M2==1||M2==3||M2==5||M2==7||M2==8||M2==10||M2==12)
    {
        if(D2<D1)
        {
            D2=D2+31;
            M2=M2-1;
        }
    }
    else
    {
        if(D2<D1)
        {
            D2=D2+30;
            M2=M2-1;
        }
    }
    return 0;
}
