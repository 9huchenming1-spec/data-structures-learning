//实验题三————————————————————————————————————————————————————————————————————
#include <stdio.h>
#include <time.h>		 	
#include <math.h>

bool prime1(long n)			
{
	long i;
	for (i=2;i<n;i++)
		if (n%i==0) 
			return false;	
	return true;
}

void PrimeTime1(long n)		
{
	clock_t t;
	long sum=0,i;
	t=clock();
	for (i=2;i<=n;i++)
		if (prime1(i))
			sum++;
	t=clock()-t;
	printf("方法1:\n");
	printf("  结果:2~%d的素数个数:%d\n",n,sum);
	printf("  用时:%lf秒\n" ,((float)t)/CLOCKS_PER_SEC);
}

bool prime2(long n)			
{
	long i;
	for (i=2;i<=(int)sqrt(n);i++)
		if (n%i==0) 
			return false;	
	return true;
}
void PrimeTime2(long n)		
{
	clock_t t;
	long sum=0,i;
	t=clock();
	for (i=2;i<=n;i++)
		if (prime2(i))
			sum++;
	t=clock()-t;
	printf("方法2:\n");
	printf("  结果:2~%d的素数个数:%d\n",n,sum);
	printf("  用时:%lf秒\n" ,((float)t)/CLOCKS_PER_SEC);
}
//------------------------------------------------------------
int main()
{
	long n;
	printf("n(大于100000):");
	scanf("%d",&n);
	if (n<10000) return 0;
	PrimeTime1(n);
	PrimeTime2(n);
	return 1;
}
