#include<stdio.h>
#include<math.h>

int main()
{
    double x1,y1,x2,y2,x3,y3,k,Area,AreaAll;
    scanf("%lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&k);
    Area=fabs(x1*y2+x3*y1+x2*y3-x1*y3-x2*y1-x3*y2)/2.0;
    AreaAll=acos(-1)*k*k+k*(sqrt(pow(x2-x1,2.0)+pow(y2-y1,2.0))
                                +sqrt(pow(x3-x2,2.0)+pow(y3-y2,2.0))
                                +sqrt(pow(x3-x1,2.0)+pow(y3-y1,2.0)));

    printf("%.2lf %.2lf\n",Area,AreaAll);

    return 0;
}
