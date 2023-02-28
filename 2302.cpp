#include <bits/stdc++.h>
using namespace std;

int dp[41] = { 1, 1 };
int n, m, v, p, ans = 1;

int fibo(int num)
{
	if (num < 2)
		return 1;
	
	if (dp[num] == 0)
		dp[num] = fibo(num - 1) + fibo(num - 2);
	
	return dp[num];
}

int main(void)
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &v);
		
		ans *= fibo(v - p - 1);
		p = v;
	}
	
	printf("%d\n", ans * fibo(n - p));
	
	return 0;
}

