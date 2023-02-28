#include <bits/stdc++.h>
using namespace std;

int cal[10000001];
int prv[10000001];
int n;

void printPrev(int now)
{	
	if (cal[now] != 0)
		printPrev(prv[now]);
	
	printf("%d ", now);
}

int main(void)
{
	scanf("%d", &n);
	do
	{
		if (n % 3 == 0 && (cal[n / 3] > cal[n] || !cal[n / 3]))
		{
			cal[n / 3] = cal[n] + 1;
			prv[n / 3] = n;
		}
		
		if (n % 2 == 0 && (cal[n / 2] > cal[n] || !cal[n / 2]))
		{
			cal[n / 2] = cal[n] + 1;
			prv[n / 2] = n;
		}
		
		if (cal[n - 1] > cal[n] || !cal[n - 1])
		{
			cal[n - 1] = cal[n] + 1;
			prv[n - 1] = n;
		}
	} while (n--);
	
	printf("%d\n", cal[1]);
	printPrev(1);
	
	return 0;
}

