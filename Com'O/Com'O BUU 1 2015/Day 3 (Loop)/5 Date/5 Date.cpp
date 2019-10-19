#include<stdio.h>

void printmonth(int m)
{
    if(m==1)
        printf("January");
    if(m==2)
        printf("February");
    if(m==3)
        printf("March");
    if(m==4)
        printf("April");
    if(m==5)
        printf("May");
    if(m==6)
        printf("June");
    if(m==7)
        printf("July");
    if(m==8)
        printf("August");
    if(m==9)
        printf("September");
    if(m==10)
        printf("October");
    if(m==11)
        printf("November");
    if(m==12)
        printf("December");
}
int main()
{
    int n,d,m,y,type,i;
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%d/%d/%d %d",&d,&m,&y,&type);
        if(d<1||d>31||m<1||m>12||y<1000||y>3000)
            printf("No\n");
        else if(type==2)
        {
            printf("%02d ",d);
            printmonth(m);
            printf(", %d\n",y);
        }
        else if(type==3)
        {
            printmonth(m);
            printf(" %02d, %d\n",d,y);
        }
        else if(type==4)
        {
            printf("%02d ",d);
            printmonth(m);
            printf(", %02d\n",y%100);
        }
    }
    return 0;
}
