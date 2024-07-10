#include <stdio.h>
#include <math.h>
#include <time.h>

void timess(int flag,double a[]);
double f1(int n,double a[],double x);
double f2(int n,double a[],double x);

#define MAXN 10	//最大项数
clock_t start,stop;
double duration;
void main()
{
	int i;
	double a[MAXN];	
	for(i=0;i<MAXN;i++) a[i]=(double)i;
	timess(1,a);
	timess(2,a);	
}
void timess(int flag,double a[])
{
	start=clock();
	if(flag==1)
		f1(MAXN,a,1.1);
	else if(flag==2)
		f2(MAXN,a,1.1);
	stop=clock();
	duration=(double)(stop-start)/4;
	printf("ticks%d = %f\n",flag,(double)(stop-start));
	printf("duration%d = %f\n",flag,(double)duration);
}
double f1(int n,double a[],double x)
{
	int i;
	double p=a[0];
	for(i=1;i<=n;i++)
		p+=(a[i]*pow(x,(double)i));	
	return p;
}
double f2(int n,double a[],double x)
{
	int i;
	double p=a[n];
	for(i=n;i>0;i--)
		p=x*p+a[i-1];
	return p;
}
