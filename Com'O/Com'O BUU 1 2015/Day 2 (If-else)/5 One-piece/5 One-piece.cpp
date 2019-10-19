/*
TASK: One-piece
AUTHOR: Natchapol Srisang
SCHOOL: Mahidolwittayanusorn School
LANG: C
*/
#include<cstdio>
int main(){
    int s,mi,h,d,mo,y;
    scanf("%d",&s);
    y=s/(12*30*24*60*60),s%=12*30*24*60*60;
    mo=s/(30*24*60*60),s%=30*24*60*60;
    d=s/(24*60*60),s%=24*60*60;
    h=s/(60*60),s%=60*60;
    mi=s/60,s%=60;
    printf(y>1? "%dYears ":"%dYear ",y);
    printf(mo>1? "%dMonths ":"%dMonth ",mo);
    printf(d>1? "%dDays ":"%dDay ",d);
    printf(h>1? "%dHours ":"%dHour ",h);
    printf(mi>1? "%dMinutes ":"%dMinute ",mi);
    printf(s>1? "%dSeconds ":"%dSecond ",s);
}
