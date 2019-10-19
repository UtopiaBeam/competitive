#include<stdio.h>
int a[1010],n;
int main(){
    int i,j,cnt=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a[i]>a[j])	cnt++;
	printf("%d\n",cnt);
	return 0;
}
