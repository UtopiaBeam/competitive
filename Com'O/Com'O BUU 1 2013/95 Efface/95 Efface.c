#include<stdio.h>

int main()
{
    double x1,x2,x3,x4,y1,y2,y3,y4,m1,m2;
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        if(x2-x1==0)
            m1=500;
        else
            m1=(y2-y1)/(x2-x1);

        if(x4-x3==0)
            m2=500;
        else
            m2=(y4-y3)/(x4-x3);

        if(m1-m2)
            ;
        else
            printf("Not-Intersect\n");
    }

    return 0;
}
